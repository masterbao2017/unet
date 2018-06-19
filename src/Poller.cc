/*************************************************************************
	> File Name: Poller.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月20日 星期日 12时41分59秒
 ************************************************************************/

#include<poll.h>
#include<algorithm>

#include"../include/Type.h"
#include"../include/Global.h"
#include"../include/Event.h"
#include"../include/EventMap.h"
#include"../include/Poller.h"

namespace unet
{
    Poller::Poller() : 
        EventDemultiplexer(),
        u_eventList(),
        u_set(),
        u_mutex(),
        u_stopMap()
    {};

    Poller::Poller(Poller&& poll) :
        EventDemultiplexer(),
        u_eventList(poll.u_eventList),
        u_set(poll.u_set),
        u_mutex(),
        u_stopMap()
    {
        base::MutexLockGuard guard(poll.u_mutex);
        std::swap(u_stopMap,poll.u_stopMap);
    };

    Poller& Poller::operator=(Poller&& poll)
    {
        if(*this == poll)
            return *this;
        std::swap(poll.u_eventList,u_eventList);
        std::swap(u_set,poll.u_set);
        
        {
            base::MutexLockGuard guard(poll.u_mutex);
            {
                base::MutexLockGuard guard(u_mutex);
                std::swap(u_stopMap,poll.u_stopMap);
            }
        }

        return *this;
    }

    Poller::~Poller()
    {
        u_eventList.clear();
        u_stopMap.clear();
        u_set.clear();
    };
   
    /*usr event->sys event*/
    int Poller::switchEvent(int usrEvent)
    {
        int sysEvent = 0;
        if(usrEvent & U_READ)
            sysEvent |= POLLIN;
        if(usrEvent & U_WRITE)
            sysEvent |= POLLOUT;
        if(usrEvent & U_EXCEPTION)
            sysEvent |= POLLERR|POLLHUP|POLLNVAL|POLLRDHUP;
        return sysEvent;
    }
    
    /*什么时候向Poller中添加事件？*/
    /*在Acceptor中的事件被触发时，Accepter的事件被纳入时间处理线程进行处理，而
     * Poller一直运行在Loop线程，需要用锁保护临界区,删除也是同样的道理*/
    void Poller::addEvent(int fd,int wevent)
    {
        struct pollfd pfd;
        pfd.fd = fd;
        pfd.events = switchEvent(wevent);
        pfd.revents = 0;
        
        {
            base::MutexLockGuard guard(u_admutex);
            u_addEventList.push_back(pfd);
        }
    }
    
    /*在每一次主循环前都会统计add event与erase event的数量*/
    void Poller::addEventCore()
    {
        base::MutexLockGuard guard(u_admutex);
        while(!u_addEventList.empty())
        {
            if(u_set.find(u_addEventList.back().fd) == u_set.end())
            {
                ++u_wfds;
                u_set.insert(u_addEventList.back().fd);
                u_eventList.push_back(u_addEventList.back());
            }
            else
            {
                auto iter = u_eventList.begin();
                for(;iter!=u_eventList.end();++iter)
                    if(iter->fd == u_addEventList.back().fd)
                        break;
                *iter = u_addEventList.back();
            }
            
            u_addEventList.pop_back();
        }
    }
    
    /*异步的删除事件*/
    void Poller::delEvent(int fd)
    {
        {
            base::MutexLockGuard guard(u_admutex);
            u_deleteEventList.push_back(fd);
        }
    }
    
    void Poller::deleteEventCore()
    {        
        {
            base::MutexLockGuard guard(u_admutex);
            int fd = -1;
            /*逐步的遍历删除事件列表*/
            while(!u_deleteEventList.empty())
            {
                fd = u_deleteEventList.back();
                u_deleteEventList.pop_back();
            
                auto iter = u_set.find(fd);
                if(iter == u_set.end())
                    continue;
                /*在event list中删除事件*/
                for(auto viter=u_eventList.begin();viter!=u_eventList.end();++viter)
                {
                    if(viter->fd == fd && viter != u_eventList.end())
                    {
                        u_eventList.erase(viter);
                        break;
                    }
                }
                /*调整统计量*/
                u_set.erase(iter);
                --u_wfds;
            
                /*从暂停列表中删除事件*/
                {
                    base::MutexLockGuard guard(u_mutex);
                    auto miter = u_stopMap.find(fd);
                    if(miter != u_stopMap.end())
                        u_stopMap.erase(miter);
            
                    miter = u_stopMap.find(-fd);
                    if(miter != u_stopMap.end())
                        u_stopMap.erase(miter);
                }
            }
        }   
        
    }

    void Poller::poll(const EventMap& eventMap,std::vector<std::shared_ptr<Event>>& eventList)
    {
        /*重置暂停列表中的事件*/
        {
            base::MutexLockGuard guard(u_mutex);
            for(auto iter=u_stopMap.begin();iter!=u_stopMap.end();++iter)
            {
                if(iter->first > 0)
                {
                    for(auto viter=u_eventList.begin();viter!=u_eventList.end();++viter)
                    {
                        if(viter->fd == iter->first)
                        {
                            viter->events = iter->second;
                            break;
                        }
                    }
                    u_stopMap.erase(iter);
                }
            }
        }

        /*处理添加与删除的事件*/
        deleteEventCore();
        addEventCore();
        
        if(u_eventList.size() > 0)
            u_rfds = ::poll(&*u_eventList.begin(),u_eventList.size(),POLL_TIMEOUT);
        
        if(u_rfds < 0)
        {
            perror("poll error!\n");
            unet::handleError(errno);
        }
    
        /*处理发生的事件*/
        int revent = 0;
        for(auto iter=u_eventList.begin();iter!=u_eventList.end();++iter)
        {
            /*sys->usr*/
            revent = 0;
            if((iter->revents & POLLRDHUP) || (iter->revents & POLLERR) || (iter->revents & POLLHUP) || (iter->revents & POLLNVAL))
                revent |= U_EXCEPTION;
            if(iter->revents & POLLIN)
                revent |= U_READ;
            if(iter->revents & POLLOUT)
                revent |= U_WRITE;
            
            /*将发生的事件添加到事件处理列表并将发生的事件置0*/
            iter->revents = 0;
            if(revent)
            {
                std::shared_ptr<Event> ptr = eventMap.find(iter->fd);
                if(ptr)
                {
                    ptr->setREvent(revent);
                    eventList.push_back(ptr);
                }
                
                /*使用了一个小技巧，将索引改变为-1的。在事件处理线程重置事件
                时，将符号变正即可*/
                {
                    base::MutexLockGuard guard(u_mutex);
                    u_stopMap.insert({-(iter->fd),iter->events});
                }
                iter->events = 0;/*不关注任何事件*/
            }
        }
    }

    /*重置事件时，删除-fd，添加+fd*/
    void Poller::resetEvent(int fd)
    {
        base::MutexLockGuard guard(u_mutex);
        auto iter = u_stopMap.find(-fd);
        if(iter == u_stopMap.end())
            return;
        u_stopMap.insert({fd,iter->second}); 
        u_stopMap.erase(iter);
    }
}

