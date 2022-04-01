#include "Channel.h"
#include <iostream>
void Channel::setCloseCallback(EventCallback cb) { closeCallback = cb; }

void Channel::setReadCallback(EventCallback cb) { readCallback = cb; }

void Channel::setWriteCallback(EventCallback cb) { writeCallback = cb; }

void Channel::handleEvent()
{

    std::cout << "readEvent" << readEvent << std::endl;

    if (currentEvent & (readEvent | ergentRead))
    {
        if (readCallback)
            readCallback();
    }
    else if (currentEvent & writeEvent)
    {
        if (writeCallback)
            writeCallback();
    }
}

void Channel::setEvent(int event)
{
    currentEvent = event;
}

int Channel::getFd() const
{
    return socketfd;
}