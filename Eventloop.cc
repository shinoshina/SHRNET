


#include "Eventloop.h"


void Eventloop::loop()
{
    while(1)
    {
        int activeChannelNums = poller->epoll(&activeChannels);

        ChannelList::iterator it;
        for(it = activeChannels.begin();it != activeChannels.end();++it)
        {
            (*it).handleEvent();
        }
    }
}

void Eventloop::updateChannels(Channel* channel)
{
     std::cout << "n" << std::endl;
    poller->updateMonitorChannel(channel);
     std::cout << "p" << std::endl;
}