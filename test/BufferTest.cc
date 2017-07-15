/*************************************************************************
	> File Name: BufferTest.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年07月15日 星期六 19时54分51秒
 ************************************************************************/

//测试Buffer的安全性，联网测试另见

#include<iostream>
#include"../Buffer.h"

using namespace unet::net;

int main(int argc,char** argv)
{
    std::string message;
    Buffer buffer(10,2);

    buffer.appendInBuffer("hello,world!");
    buffer.printBufferMessage();
    buffer.appendInBuffer("hello,FLY!");
    buffer.printBufferMessage();
    buffer.appendInBuffer("hello,DXJ!");
    buffer.printBufferMessage();
        
    buffer.getCompleteMessageInBuffer(message);
    buffer.printBufferMessage();
    
    buffer.getCompleteMessageInBuffer(message);
    buffer.printBufferMessage();

    buffer.getCompleteMessageInBuffer(message);
    buffer.printBufferMessage();

    return 0;
}

