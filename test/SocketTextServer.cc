/*************************************************************************
	> File Name: SocketTextServer.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年03月17日 星期五 19时36分18秒
 ************************************************************************/

#include"../Socket.h"
#include"../InetAddress.h"
#include<iostream>
#include<string>
#include<sys/epoll.h>
#include<sys/poll.h>

int main(int argc,char** argv)
{
    int listenfd = unet::net::socket::socket();
    unet::net::InetAddress addr(7777);

    unet::net::socket::bind(listenfd,&addr);
    unet::net::socket::listen(listenfd);
    std::cout << "listenfd: " << listenfd << std::endl;

    int confd = unet::net::socket::accept(listenfd);
    std::cout << "confd: " << confd << std::endl;
    
    char buf[16] = "hello,client!";
    while(1)
    {
        sleep(1);
        std::cout << "sending~" << std::endl;
        ::write(confd,buf,16);
    }
/*    
    int epollfd = ::epoll_create(5);
    std::cout << "epollfd: " << epollfd << std::endl;
    
    struct epoll_event event,event_;
    bzero(&event,sizeof(event));
    bzero(&event_,sizeof(event_));
    event.events = EPOLLIN && EPOLLOUT;
    event.data.fd = confd;
    
    int n = ::epoll_ctl(epollfd,EPOLL_CTL_ADD,confd,&event);
    if(n < 0)
        std::cout << "epoll_ctl error!" << std::endl;
    else
        std::cout << "epoll_ctl success!" << std::endl;
    
    int count = ::epoll_wait(epollfd,&event_,5,-1);
    std::cout << "count: " << count << std::endl; 

    
    if(count == 1)
    {
        if(event_.events & EPOLLIN)
            std::cout << "Server confd can read!" << std::endl;
        else if(event_.events & EPOLLOUT)
            std::cout << "Server confd can write!" << std::endl;
        else
            std::cout << "error!" << std::endl;
    }
    else
        std::cout << "nothing happened!" << std::endl;
*/

/*    
    struct pollfd pfd;
    pfd.fd = confd;
    pfd.events = POLLOUT && POLLIN;
    int count = ::poll(&pfd,1,64000);

    if(count == 1)
    {
        if(pfd.revents & POLLIN)
            std::cout << "Client confd can read!" << std::endl;
        else if(pfd.revents & POLLOUT)
            std::cout << "Client confd can write!" << std::endl;
        else
            std::cout << "error!" << std::endl;
    }
    else
        std::cout << "nothing happened!" << std::endl;
*/    
    sleep(30);
    unet::net::socket::close(listenfd);
    std::cout << "listen socket close" << std::endl;
    unet::net::socket::close(confd);
    std::cout << "server confd close" << std::endl;
    return 0;
}

































