/*************************************************************************
	> File Name: TcpServer.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年06月02日 星期六 18时55分29秒
 ************************************************************************/

#ifndef _TCPSERVER_H
#define _TCPSERVER_H

#include"InetAddress.h"
#include"Buffer.h"
#include"TcpConnectionMap.h"
#include"EventMap.h"
#include"EventDemultiplexer.h"
#include"EventLoop.h"
#include"Accepter.h"
#include"TaskPool.h"
#include"TimerEvent.h"
#include"SignalEvent.h"
#include"SocketEvent.h"

namespace unet
{
    class TcpServer final
    {
        typedef std::shared_ptr<base::Buffer> BufferPtr;
        typedef std::function<void(BufferPtr)> ReadCallBack;
        typedef std::function<void(BufferPtr)> WriteCallBack;
        typedef std::function<void()> TimerEvent;

        public:
            explicit TcpServer(base::InetAddress& serverAddr,int size = 4);
            TcpServer(const TcpServer&) = delete;
            TcpServer(TcpServer&&);
            TcpServer& operator=(const TcpServer&) = delete;
            TcpServer& operator=(TcpServer&&);
            ~TcpServer();
            bool operator==(const TcpServer& server){return u_serverAddr==server.u_serverAddr;};
            void setReadCallBack(const ReadCallBack& cb){u_readCallBack = cb;};
            void setWriteCallBack(const WriteCallBack& cb){u_writeCallBack = cb;};
            void start();
            void stop();
            bool isStart() const{return u_start;};
            void addTimerEvent(bool repeat,double repeatTime,const TimerEvent&);

        private:
            void SaveListen(int);
            void EraseListen(int);
            void SaveConnect(int);
            void SeparationEvent();
            void ResetEvent(int);
            void AccepterHandleRead(){u_accepter.handleRead();};
            void EraseConnect(int);

        private:
            bool u_start;
            base::InetAddress u_serverAddr;
            TcpConnectionMap u_connectionMap; 
            EventMap u_eventMap;
            int u_eventDemuType;
            std::shared_ptr<EventDemultiplexer> u_eventDemu;
            EventLoop u_loop;
            Accepter u_accepter;
            TaskPool u_taskPool;
            int u_taskSize;

            /*Timer和Signal属于必须暴露的事件，不能由EventMap统一管理*/
            std::shared_ptr<Event> u_timerEventPtr;
//            static std::shared_ptr<SignalEvent> u_signalEventPtr; 
            std::vector<std::shared_ptr<Event>> u_eventPtrList;
            
            ReadCallBack u_readCallBack;
            WriteCallBack u_writeCallBack;
    };
}

#endif
