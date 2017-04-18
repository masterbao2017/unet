/*************************************************************************
	> File Name: TcpClient.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年03月21日 星期二 20时32分19秒
 ************************************************************************/

#include"TcpClient.h"

namespace unet
{
    namespace net
    {
        TcpClient::TcpClient(InetAddress* serveraddr_) :
            serveraddr(serveraddr_),
            connector(new ConnectorThread()),
            ptr(nullptr)
        {
            connector->setConnectionCallBack(std::bind(&TcpClient::newConnectionCallBack,this,std::placeholders::_1));
            connector->setHandleAsyncBufferCallBack(std::bind(&TcpClient::handleAsyncBuffer,this,ptr->getOutputBuffer()));     
        };

        Channel* TcpClient::newConnectionCallBack(int fd_)
        {
            Channel* channel = new Channel(fd_,true);
            TcpConnectionPtr ptr(channel->getTcpConnectionPtr());

            if(readcallback)
                ptr->setReadCallBack(readcallback);
            if(writecallback)
                ptr->setWriteCallBack(writecallback);
            if(drivedcallback)
                ptr->setDrivedCallBack(drivedcallback);
            
            ptr->setHandleDiedTcpConnection(std::bind(&TcpClient::handleDiedTcpConnection,this,std::placeholders::_1));
            tcpconnectionptrmap.insert({fd_,ptr});
            
            return channel;
        }

        void TcpClient::handleDiedTcpConnection(int fd_)
        { 
            thread::MutexLockGuard guard(lock);
            tcpconnectionptrmap[fd_]->handleChannel();
            tcpconnectionptrmap[fd_].reset();
            tcpconnectionptrmap.erase(fd_);
        }

    }
}
        
            

        
