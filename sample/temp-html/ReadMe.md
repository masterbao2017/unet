#程序简介
- 一个运行在服务器端和客户端（Linux内核）的中间层通信软件，用于将底层硬件收集的数据通过TCP/IP协议栈交给WEB
- 依赖于unet网络库以及RapidJSON解析生成库
- 服务端为事件驱动的非阻塞IO模型
- 客户端为事件驱动的异步非阻塞IO模型
- 其余技术细节参考unet源码

#目前存在的问题
- TcpServer的IO线程>=2的话，无法正确的将生成的Channel放入Epoller中，目前只开一条IO线程
