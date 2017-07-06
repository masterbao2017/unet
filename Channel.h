/*************************************************************************
	> File Name: Channel.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年03月09日 星期四 20时56分13秒
 ************************************************************************/

#ifndef _CHANNEL_H
#define _CHANNEL_H

//核心思想在于Channel不负责fd的生命期，只负责其上事件的处理

//并且Channel拥有TcpConnection对象的weak_ptr，用弱指向判断TcpConnection对象是否还存在

//确信讨论一点，当一个连接建立起来之后，关注的事件应该不会再变了

//confd关注可写和可读事件，listenfd关注可读事件,timefd关注可读事件

//由于listenchannel与普通的channel不同（没有TcpConnection）,用一个bool类型进行判断

/* 设计理念：Channel只关注fd上的事件的处理
 * 1.
 * 
 * 
 * 
 * 
 * 
 */


#include"TcpConnectionMap.h"

class Channel;

namespace unet
{
    namespace net
    {
        static const int KNoneEvent = 0;//关注的事件的处理方式
        static const int KReadEvent = EPOLLIN;
        static const int KWriteEvent = EPOLLOUT;
        
        enum ChannelType{LISTEN,CONNECT,CLOCK};
        
        class Channel final
        {
            typedef std::function<void()> ReadCallBack;
            typedef std::function<void()> CloseCallBack;

            public:
                explicit Channel(int fd_,ChannelType type_);
                Channel(const Channel& lhs) = delete;
                Channel(Channel&& lhs);
                Channel& operator=(const Channel& lhs)  = delete;
                Channel& operator=(Channel&& lhs);
                ~Channel();
                
                void handleEvent(TcpConnectionMap& tcpconnectionMap);//处理事件的主体函数
                
                inline int getFd() const; 
                inline void setEvent();
                inline int getEvent() const;
                inline void setRevent(int revent_); 
                inline int getType() const;
                inline void setReadCallBack(const ReadCallBack& lhs);
                inline void setcloseCallBack(const CloseCallBack& lhs);

                inline bool isNoneEvent() const;
                inline bool isReading() const;
                inline bool isWriting() const;
                
            private:
                int fd;
                int event;//关注的事件
                int revent;//正在发生的事件
                bool handleEventing;
                ChannelType type;

                ReadCallBack readCallBack;
                CloseCallBack closeCallBack;
        };
    }
}

#endif

