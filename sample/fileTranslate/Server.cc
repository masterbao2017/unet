/*************************************************************************
	> File Name: Server.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年03月31日 星期五 16时28分26秒
 ************************************************************************/

//这个例子处理两种情况的事件

//服务端主动给多个客户端发送文件
//多个客户端主动给服务端发送文件


#include"../../mutilServer/MutilTcpServer.h"
#include"../../File.h"

using namespace unet;
using namespace unet::thread;
using namespace unet::net;

void readCallBack(Buffer* inputbuffer,Buffer* outputbuffer)
{//服务端被动处理事务（适用于短连接）,只能在fd资源和内存资源中二选一
/*    char* buf;
    inputbuffer->readInSocket();
    buf = inputbuffer->getCompleteMessageInBuffer();

    if(buf != nullptr)
    {
        File chenuu("/home/uuchen/chenuu.jpeg");
        chenuu.writen(buf,strlen(buf));
        ::free(buf);
    }
*/}

void writeCallBack(Buffer* inputbuffer,Buffer* outputbuffer)
{


}

void drivedCallBack(Buffer* inputbuffer,Buffer* outputbuffer)
{//服务端主动发送文件，及时服务
    char buf[1024];
    bzero(buf,1024);
    File uuchen(argv[1]);
//    int confd = inputbuffer->getFd();

    while(1)
    {
        uuchen.readn(static_cast<void*>(buf),1024);
        if(uuchen.getReadSize() > 0)
        {
            outputbuffer->appendInBuffer(static_cast<const void*>(buf));
            outputbuffer->writeInSocket();
/*            
            ::write(confd,buf,1024);
            ::sleep(0.5);
            perror("writeInSocket!\n");
*/
        }
        else
            break;
    }
}


int main(int argc,char** argv)
{
    InetAddress serveraddr(7777);
    MutilTcpServer server(&serveraddr);

    server.setReadCallBack(std::bind(&readCallBack,std::placeholders::_1,std::placeholders::_2));
    server.setWriteCallBack(std::bind(&writeCallBack,std::placeholders::_1,std::placeholders::_2));
    server.setDrivedCallBack(std::bind(&drivedCallBack,std::placeholders::_1,std::placeholders::_2));

    server.start();

    return 0;
}



