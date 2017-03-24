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
            connector(new Connector(serveraddr_)),
            ptr(nullptr)
        {
            connector->setConnectionCallBack(std::bind(&TcpClient::setTcpConnectionPtr,this,std::placeholders::_1));
            ptr->setReadCallBack(readcallback);
            ptr->setWriteCallBack(writecallback);
            ptr->setHandleDiedTcpConnection(std::bind(&TcpClient::handleDiedTcpConnection,this,std::placeholders::_1));
        };

    }
}
        
            

        
