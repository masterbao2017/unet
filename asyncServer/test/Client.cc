/*************************************************************************
	> File Name: Client.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年04月15日 星期六 17时12分46秒
 ************************************************************************/

#include"../../Buffer.h"
#include"../../Socket.h"

using namespace unet;

int main(int argc,char** argv)
{
    while(1)
    {
        sleep(1);
        net::socket::InetAddress server("127.0.0.1",7777);
        net::socket::Socket confd(net::socket::CONNECT);
        net::socket::connect(confd,server);
        
        std::string message("hello,server!");
        net::Buffer buffer(confd.getFd());
        buffer.appendInBuffer(message);
        buffer.writeInSocket();

        std::cout << "client already send message!" << std::endl;
    }
    
    return 0;
}










