#ifndef _SHRNET_CHANNEL
#define _SHRNET_CHANNEL


#include<functional>

typedef std::function<void()> EventCallback;


class Channel
{
public:
    Channel(int socket) : socketfd(socket) {}

    void handleEvent();

    void setCloseCallback(EventCallback cb);
    void setMessageCallback(EventCallback cb);





private:
    int socketfd;

    EventCallback closeCallback;
    EventCallback messageCallback;
};

#endif /* _SHRNET_CHANNEL */ 