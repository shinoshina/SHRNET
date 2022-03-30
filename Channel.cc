#include "Channel.h"


void Channel::setCloseCallback(EventCallback cb)
{
    closeCallback = cb;
}

void Channel::setMessageCallback(EventCallback cb)
{
    messageCallback = cb;
}

void Channel::handleEvent()
{
    closeCallback();
}