#ifndef _SHRNET_CHANNEL
#define _SHRNET_CHANNEL


#include<functional>
#include<sys/epoll.h>

using  EventCallback = std::function<void()>;

const int readEvent = EPOLLIN;
const int writeEvent = EPOLLOUT;
const int ergentRead = EPOLLPRI;


class Channel
{
public:
    Channel(int socket) : socketfd(socket) {}

    void handleEvent();

    void setCloseCallback(EventCallback cb);
    void setReadCallback(EventCallback cb);
    void setWriteCallback(EventCallback cb);

    void update();

    void setEvent(int event);

    int getFd();





private:
    int socketfd;

    int currentEvent;

    EventCallback closeCallback;
    EventCallback readCallback;
    EventCallback writeCallback;
};

#endif /* _SHRNET_CHANNEL */ 