#include "Epoller.h"
#include <iostream>

void Epoller::fillChannels(ChannelList *channels, int eventNums)
{
    //to do  ¼ì²âlistenfd
    for (int i = 0; i < eventNums; i++)
    {

        Channel tmpchannel = *find(eventList[i].data.fd);
        tmpchannel.setEvent(eventList[i].events);
        channels->push_back(tmpchannel);
    }
}

void Epoller::updateMonitorChannel(Channel *channel)
{
     std::cout << "k" << std::endl;
    struct epoll_event ev;
    ev.events = (readEvent | ergentRead);
    ev.data.fd = channel->getFd();
 std::cout << channel->getFd() << std::endl;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, channel->getFd(), &ev);

    channelList.push_back(*channel);
    std::cout << channel->getFd() << std::endl;
}

int Epoller::epoll(ChannelList *channels)
{

    int eventNums = ::epoll_wait(epollfd, &(*eventList.begin()), eventList.size(), 10000);

    std::cout << "event" << eventList[0].events << std::endl;

    if (eventNums > 0)
    {
        fillChannels(channels, eventNums);
        std::cout << "fill success"
                  << "   channel size:" << (*channels).size() << std::endl;
    }

    return eventNums;
}

Channel* Epoller::find(int fd)
{
    for(int i =0;i<channelList.size();i++)
    {
        if(fd == channelList[i].getFd()) return &channelList[i];
    }
}