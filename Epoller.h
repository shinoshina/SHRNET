#ifndef _SHRNET_EPOLLER
#define _SHRNET_EPOLLER

#include "Channel.h"
#include <vector>

/*** epoll_event***/
// struct epoll_event
// {
//   uint32_t events;
//   epoll_data_t data;
// };
/*******************/

/*** epoll_data ***/
// typedef union epoll_data
// {
//   void *ptr;
//   int fd;
//   uint32_t u32;
//   uint64_t u64;
// } epoll_data_t;
/******************/

using ChannelList = std::vector<Channel>;
using EventList = std::vector<struct epoll_event>;

class Epoller
{
public:
    Epoller():eventList(16)
    {
        // epoll_create() is ignored since linux2.6.8
        //EPOLL_CLOEXEC means close-on-exec
        epollfd = epoll_create1(EPOLL_CLOEXEC);
    }

    void fillChannels(ChannelList* channels,int eventNums);
    void updateMonitorChannel(Channel *channel);

    void epoll(ChannelList* channels);

    void debug()
    {
        channelList[0].handleEvent();
    }

    Channel* find(int fd);


private:
    ChannelList channelList;
    EventList eventList;
    int epollfd;
};

#endif /* _SHRNET_EPOLLER */