#include "Epoller.h"

void Epoller::fillChannels(ChannelList *channels, int eventNums)
{
    for (int i = 0; i < eventNums; i++)
    {
        Channel tmpchannel(eventList[i].data.fd);
        tmpchannel.setEvent(eventList[i].events);

        (*channels).push_back(tmpchannel);
    }
}

void Epoller::updateMonitorChannel(Channel channel)
{
    struct epoll_event ev;
    ev.events = (readEvent | ergentRead);
    ev.data.fd = channel.getFd();

    epoll_ctl(epollfd, EPOLL_CTL_ADD, channel.getFd(), &ev);

    channelList.push_back(channel);
}

void Epoller::epoll(ChannelList *channels)
{

    int eventNums = ::epoll_wait(epollfd, &(*eventList.begin()), eventList.size(), 10000);

    if (eventNums > 0)
    {
        fillChannels(channels, eventNums);
    }
}