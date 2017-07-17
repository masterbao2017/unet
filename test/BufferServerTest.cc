/*************************************************************************
	> File Name: BufferServerTest.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年07月15日 星期六 19时36分07秒
 ************************************************************************/

#include<iostream>
#include"../Socket.h"
#include"../Buffer.h"

using namespace unet;

int main(int argc,char** argv)
{
    net::socket::InetAddress serverAddr(7777);
    net::socket::Socket listenfd(net::socket::LISTEN);
    net::socket::bind(listenfd,serverAddr);
    net::socket::listen(listenfd);

    int confd = net::socket::accept(listenfd);
    std::cout << "confd is: " << confd << std::endl;
    
    net::Buffer serverBuffer(confd);

    serverBuffer.recvFile("/home/uuchen/chenuu.jpeg");

    return 0;
}
