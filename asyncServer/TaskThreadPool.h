/*************************************************************************
	> File Name: TaskThreadPool.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年04月17日 星期一 18时06分48秒
 ************************************************************************/

#ifndef _TASKTHREADPOOL_H
#define _TASKTHREADPOOL_H

#include"../ThreadPool.h"
#include"../Mutex.h"
#include"../Condition.h"
#include"../Channel.h"
#include"../Condition.h"

namespace unet
{
    namespace thread
    {
        class TaskThreadPool final
        {
            typedef std::function<void()> Task;
            typedef std::vector<Task> TaskList;
            typedef std::vector<unet::net::Channel*> ChannelList;
            
            public:
                explicit TaskThreadPool(int size = 2) : pool(size),lock(),cond(lock)
                {
                    Thread thread(std::bind(&TaskThreadPool::ThreadFunc,this));
                    pool.setThreadCallBack(std::move(thread));
                }

                TaskThreadPool(const TaskThreadPool& lhs) = delete;
                TaskThreadPool& operator=(const TaskThreadPool& lhs) = delete;
                
                ~TaskThreadPool()
                {
                    pool.joinAll();
                }

                void start()
                {
                    pool.start();
                }
/*                
                void setThreadCallBack(const Thread& cb)
                {
                    pool.setThreadCallBack(cb);
                }
*/
/*                
                void addInTaskQueue(TaskList&& lhs)
                {
                    MutexLockGuard guard(lock);
                    queue.insert(queue.end(),lhs.begin(),lhs.end());
                }
*/               
                //这种情况就属于muduo中阐述的第一种情况：将一个对象暴露在多个线程中
                //must have error
                void addInChannelQueue(ChannelList* lhs)//由server调用
                {
                    std::cout << "addInChannelQueue not have lock" << std::endl;
                    MutexLockGuard guard(lock);
                    std::cout << "addInChannelQueue have lock" << std::endl;
//                    channelqueue.swap(*lhs);
                    channelqueue.insert(channelqueue.end(),lhs->cbegin(),lhs->cend());
//                    std::cout << "addInChannelQueue: " << (*channelqueue.begin())->getFd() << std::endl;
//                    lhs->clear();
                    cond.notify();
                }

                int getChannelInPool(ChannelList* lhs)//由线程调用
                {
                    std::cout << "getChannelInPool not have lock" << std::endl;
                    MutexLockGuard guard(lock);
                    std::cout << "getChannelInPool have lock" << std::endl;
                    
                    while(channelqueue.size() == 0)
                        cond.wait();
                    
                    std::cout << "getChannelInPool leave cond.wait" << std::endl;
                    lhs->insert(lhs->end(),channelqueue.begin(),channelqueue.end());
//                    channelqueue.swap(*lhs);
//                    channelqueue.clear();
                    if(lhs->size() != 0)
                        std::cout << "getChannelInPool: " << (*lhs->begin())->getFd() << std::endl;
                    return lhs->size();
                }
/*
                int getTaskInPool(TaskQueue* lhs)
                {
                    MutexLockGuard guard(lock);
                    lhs->swap(queue);
                    return lhs->size();
                }
*/
            private:

                void ThreadFunc()
                {
                    TaskList taskqueue;
                    ChannelList channels;
                    Task task;
                    int queuesize = 0;

                    while(1)
                    { 
/*                        
                        taskqueue.clear();
                        queuesize = getTaskInPool(&taskqueue);
                        for(int i=0;i<queuesize;++i)
                        {
                            task = taskqueue.back();
                            taskqueue.pop_back();
                            task();
                        }
                        taskqueue.clear();
*/                                         
/*                        
                        {
                            thread::MutexLockGuard guard(lock); 
                            queuesize = channelqueue.size();
                            while(queuesize == 0)
                                cond.wait();
                            
                            if(queuesize != 0)
                                channels.swap(channelqueue);

                            std::cout << "channelqueue.size: " << channelqueue.size() << std::endl;
                            std::cout << "channels.size: " << channels.size() << std::endl;
                        }
*/                     
                        queuesize = getChannelInPool(&channels);
//                        for(int i=0;i<queuesize;++i)
//                            std::cout << "channel[i]->getFd: " << channels[i]->getFd() << std::endl;
                        for(int i=0;i<queuesize;++i)
                        {
//                            printf("%ld-----\n",pthread_self());
                            
                            std::cout << "channel.getFd: " << channels[i]->getFd() << std::endl;
                            channels[i]->handleEvent();
//                            printf("%ld-----\n",pthread_self());
                        }
                        channels.clear();
                    }
                }

                ThreadPool pool;
                TaskList queue;
                ChannelList channelqueue;
                MutexLock lock;
                Condition cond;
        };
    }
}
        

#endif

