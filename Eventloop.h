#ifndef _SHRNET_EVENTLOOP
#define _SHRNET_EVENTLOOP

#include "Epoller.h"
#include <iostream>


class Eventloop
{
public: // Eventloop();
  
  Eventloop(Epoller * epoller):poller(epoller){}
  void loop();

  void updateChannels(Channel *channel);

private:
  Epoller *poller;
  ChannelList activeChannels;
};

#endif /* _SHRNET_EVENTLOOP */