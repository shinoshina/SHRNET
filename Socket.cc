


#include "Socket.h"


class Address;

int Socket::fd()
{
    return _socket;
}

void Socket::bindAddress(Address& addr)
{
    ::bind(_socket,addr.sockAddr(),sizeof(addr.sockAddr()));
}