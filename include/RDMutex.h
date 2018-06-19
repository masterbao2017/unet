/*************************************************************************
	> File Name: RDMutex.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月29日 星期二 05时21分07秒
 ************************************************************************/

#ifndef _RDMUTEX_H
#define _RDMUTEX_H

#include<pthread.h>
#include"Global.h"

/*2018.05.29 测试完成*/
namespace unet
{
    namespace base
    {
        /*RDLock存在三种状态*/
        /*读写锁的抽象很漂亮，不过我不用*/
        class RDMutexLock final
        {
            friend bool operator==(const RDMutexLock&,const RDMutexLock&);
            
            public:
                explicit RDMutexLock();
                RDMutexLock(const RDMutexLock&& ) = delete;
                RDMutexLock& operator=(const RDMutexLock&) = delete;
                RDMutexLock(RDMutexLock&&);
                RDMutexLock& operator=(RDMutexLock&&);
                ~RDMutexLock();
                
                bool isLockInThisThread(const RDMutexLock& lock) const
                {return u_tid == lock.u_tid;};
                
                pthread_t getLockThreadId() const{return u_tid;};

                void rdLock();
                void wrLock();
                void unLock();
            private:
                pthread_t u_tid;
                pthread_rwlock_t u_mutex;
        };
        
        enum LockType{RDLOCK,WRLOCK};

        class RDMutexLockGuard final
        {
            public:
                RDMutexLockGuard(RDMutexLock&,enum LockType);
                RDMutexLockGuard(RDMutexLockGuard&&) = delete;
                RDMutexLockGuard(const RDMutexLockGuard&) = delete;
                RDMutexLockGuard& operator=(const RDMutexLockGuard&) = delete;
                RDMutexLockGuard& operator=(RDMutexLockGuard&&) = delete;
                ~RDMutexLockGuard();

            private:
                RDMutexLock& u_lock;
        };
    }
}

#endif
