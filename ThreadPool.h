/*************************************************************************
	> File Name: ThreadPool.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年03月27日 星期一 23时19分53秒
 ************************************************************************/

#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#include"base/Mutex.h"
#include"base/Thread.h"

#include<memory>
#include<array>
#include<vector>
#include<tuple>

namespace unet
{
    /*
     * 尽可能的将线程池设计的灵活：
     * 1.每个运行的线程可以不尽相同，对每个线程具有控制权
     * 2.线程池之间的资源可以互换
     * 3.实现动态的资源迁移
     */
    
    static const int MAX_THREADS = 64;
    static const int INIT_THREADS = 8;
    
    class Timer;
    class ThreadPool final
    {
        public:
            typedef std::function<void()> ThreadFunc;
            typedef std::shared_ptr<base::Thread> ThreadPtr;
            typedef std::tuple<pthread_t,std::string,bool> ThreadDes;
            typedef std::shared_ptr<ThreadDes> ThreadDesPtr;
            typedef std::array<ThreadDesPtr,MAX_THREADS> TidList;

        public:
            explicit ThreadPool();
            ThreadPool(const ThreadPool& lhs) = delete;
            ThreadPool(ThreadPool&& lhs);
            ThreadPool& operator=(const ThreadPool& lhs) = delete;
            ThreadPool& operator=(ThreadPool&& lhs);
            ~ThreadPool();
            
            bool operator==(const ThreadPool& pool){return u_description[0] == pool.u_description[0];}
            
            /* Functionality:
             *      向线程池中添加一个线程
             * Parameters：
             *      1）[in]：添加的线程的运行主体
             *      2）[in]：添加的线程数量
             *      3）[in]：对添加的线程的描述
             * Returned Value：
             *      None
             */
            const TidList& addThread(const ThreadFunc& func,int size = 1,const char* des = "NULL");
            
            /* Functionality:
             *      在不重新创建线程的情况下，向线程池中添加新的成员
             * Paremeters：
             *      1）[in]：即将移动的Thread
             *      2）[in]：对Thread的描述
             * Returned Value：
             *      对整个线程池的描述
             */
            const TidList& addThread(std::shared_ptr<base::Thread>& thread,const char* des = "NULL"); 
            
            /* Functionality:
             *      从线程池中移除一个线程，包括线程对象的析构操作
             * Parameters:
             *      1)：移除的线程ID
             * Returned Value：
             *      对整个线程池的描述
             */
            const TidList& deleteThread(pthread_t tid);


            /* Functionality:
             *      将pool中所有的线程添加到本地的线程池中，资源移动
             * Parameters：
             *      1）[in]：合并的线程池
             * Returned Value：
             *      对整个线程池的描述
             */
            const TidList& addThreadPool(ThreadPool& pool);

            void startAll();
            void stopAll();
            void start(pthread_t);
            void stop(pthread_t);
            int threadSize() const{return u_threadSize;};
            int startThreadSize() const{return u_startSize;};
            const TidList& description() const{return u_description;};
            void setThreadDes(pthread_t,const char*);
            bool inPool(pthread_t) const;
            void setThreadFunc(pthread_t,const ThreadFunc&);

        private:
            
            /* Functionality:
             *      根据INIT_THREADS初始化线程，只创建线程对象，实体等待填充
             * Parameters：
             *      None
             * Parameters：
             *      None
             */
            void init();

            /* Functionality:
             *      在线程池中使用了这样一种策略：如果线程启动，des->id = thread
             *      id des->start = true，此后，如果线程使用被停止，des->id不变，
             *      des->start=false,持续30s，表示该线程在后续可能再次被启动，依然
             *      维持start的假象，应对频繁启动的情况。若在30s后依旧无动静，删除
             *      在线程池中占用的资源，依靠定时器来进行。
             * Parameters:
             *      None
             * Returned Value:
             *      None
             */
            void handleStopList();

            /* Functionality:
             *      返回在线程池中已经存在线程对象，但是线程无效的位置
             * Parameters:
             *      None
             * Returned Value:
             *      None
             */     
            int findAvailablePos();

            /* Functionality:
             *      返回线程池中线程对象不存在的位置
             * Parameters:
             *      None
             * Returned Value:
             *      None
             */
            int findFreePos();
            
            /*只用于内部的线程资源转移*/
            ThreadPtr getThread(int index);
            ThreadDesPtr getThreadDes(int index); 

        private:
            int u_threadSize;
            int u_startSize;

            /*线程对象是有上限的，默认为128*/
            /*这个对象全局无锁，只有主线程可以操作*/
            std::array<ThreadPtr,MAX_THREADS> u_thread;
            
            /*以下数据会在多线程中出现，需要用锁进行保护*/
            base::MutexLock u_mutex;
            TidList u_description;
            std::shared_ptr<Timer> u_timer;
            std::vector<int> u_stopList;
    };
}
#endif

