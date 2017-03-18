/*************************************************************************
	> File Name: Epoller.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年03月09日 星期四 00时01分25秒
 ************************************************************************/

#include"Epoller.h"
#include<sys/epoll.h>
#include<assert.h>
#include"Channel.h"

namespace unet
{
    namespace net
    {
        Epoller::Epoller() :
            epollfd(::epoll_create(EPOLL_CLOEXEC))
        {
            if(epollfd < 0)
            {
                std::cout << "epollfd create errno" << std::endl;
                exit(0);
            }
        }
        
        Epoller::~Epoller()
        {
            ::close(epollfd);
        }

        void Epoller::epoll(ChennelList* channels)
        {
            eventlist.clear();
            int activeEvents = ::epoll_wait(epollfd,&*eventlist.begin(),static_cast<int>(channelmap.size()),timeoutMs);

            int savedErrno = errno;

            if(activeEvents > 0)
            {
                getActiveEvents(channels);
                std::cout << "get activeEvents" << activeEvents << std::endl;
            }
            else if(activeEvents == 0)
                std::cout << "nothing happended" << std::endl;
            else
            {
                if(savedErrno != EINTR)
                    std::cerr << errno << std::endl;
            }
        }


        void Epoller::getActiveEvents(ChannelList* channels)
        {
            for(EventList::iterator iter=eventlist.begin();iter!=eventlist.end();++iter)
            {   
                fd = iter->data.fd;
                assert(channelmap.find(fd) != channelmap.end());
                channels->push_back(channelmap[fd]);
            }
        }
        
        void Epoller::addInChannelMap(Channel* channel_)
        {//增加参数,在加入epoll时就确定关注的事件
            const int fd = channel_->getFd();
            assert(channelmap.find(fd) == channelmap.end());
            channelmap[fd] = channel_;
            channel_->setIndex(fd);
            channel_->setEvent();
            channel_->setRemoveCallBck(std::bind(&removeChannle,this,std::placeholders::_1));
            channel_->setUpdateCallBack(std::bind(&updateChannle,this,std::placeholders::_1));
            update(EPOLL_CTL_ADD,channel_);
        }



        void Epoller::updateChannel(Channel* channel_)
        {//only change channel in events
            const int index = channel_->getIndex();
            const int fd = channel_->getFd();

            assert(channels.find(fd) != channels.end());
            assert(channels[fd] == channel);
            assert(fd == index);
            update(EPOLL_CTL_MOD,channel_);
            
            if(channel_->getEvent() == KNoneEvent)
            {
                removeChannel(channel_);
            }
        }

        void Epoller::update(int operation,Channel* channel_)
        {
            struct epoll_event event;
            bzero(&evnet,sizeof(event));
            event.events = channel_->getEvent();
            int fd = event.data.fd = channel_->getFd();

            if(::epoll_ctl(epollfd,operation,fd,&event) < 0)
            {
                std::cerr << "epol_ctl erorr" << std::endl;
                exit(0);
            }
        }

        bool Epoller::hasChannel(Channel* channel_)
        {
            loop->assertInLoopThread();
            int fd = channel_->getFd();
            ChannelMap::const_iterator iter = channelmap.find(fd);
            return iter!=channelmap.end() && iter.second==channel_;
        }

//remove channelmap epollfd eventlist
        void removeChannel(Channel* channel_)
        {
            const int fd = channel_->getFd();
            const int index = channel_->getIndex();

            assert(channelmap[fd] != channelmap.end());
            assert(channelmap[fd] == channel_);
            assert(channel_->getEvent() == KNoneEvent);

//remove in epollfd
            update(EPOLL_CTL_DEL,channel_);
//remove in ChannelMap
            channelmap.erase(fd);
//remove in eventlist
//取决于channel的实现
            eventlist.erase(index);//从vector中删除一个元素
        }

    }
}

