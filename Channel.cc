#include "Channel.h"

void Channel::setCloseCallback(EventCallback cb) { closeCallback = std::move(cb); }

void Channel::setReadCallback(EventCallback cb) { readCallback = std::move(cb); }

void Channel::setWriteCallback(EventCallback cb) { writeCallback = std::move(cb); }

void Channel::handleEvent()
{
    if (currentEvent & (readEvent | ergentRead))
    {
        if (readCallback)
            readCallback();
    }
    if (currentEvent & writeEvent)
    {
        if (writeCallback)
            writeCallback();
    }
}

void Channel::setEvent(int event)
{
    currentEvent = event;
}

int Channel::getFd()
{
    return socketfd;
}