/*************************************************************************
	> File Name: TimerEvent.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月18日 星期五 18时39分33秒
 ************************************************************************/

#ifndef _TIMEREVENT_H
#define _TIMEREVENT_H

#include<queue>
#include<utility>
#include<list>
#include<memory>

#include"type.h"
#include"base/Timer.h"
#include"base/Mutex.h"

namespace unet
{
    class TimerEvent final
    {
        private:
            typedef std::shared_ptr<base::Timer> TimerPtr;
            typedef std::pair<uint64_t,TimerPtr> TimerPair;

            struct op
            {
                bool operator()(const TimerPair& lhs,const TimerPair& rhs)
                {return lhs.first < rhs.first;};
            };
        
        public:
            TimerEvent();
            TimerEvent(const TimerEvent& event) = delete;
            TimerEvent& operator=(const TimerEvent& event) = delete;
            TimerEvent(TimerEvent&& event);
            TimerEvent& operator=(TimerEvent&& event);
            ~TimerEvent();
            
            bool operator==(const TimerEvent& event){return u_timerfd==event.u_timerfd;};
            void addTimerWithLock(TimerPtr timer);
            void addTimer(TimerPtr timer);
            void start(){u_start = true;};
            void stop();
            bool isStart(){return u_start;};
            int getTimerfd() const{return u_timerfd;};

            void handleEvent();

        private:
            int u_timerfd;
            bool u_start;

            std::priority_queue<TimerPair,std::list<TimerPair>,op> u_timerHeap;
            base::MutexLock u_mutex;
    };
}

#endif

