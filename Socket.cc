




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

int Socket::acceptConn(Address* addr)
{
    struct sockaddr_in peeraddr;
    socklen_t addrlen = static_cast<socklen_t>(sizeof peeraddr);
    memset(&peeraddr,0,sizeof(peeraddr));
    int connsock = ::accept4(this->fd(),(sockaddr*)&peeraddr,&addrlen, SOCK_NONBLOCK | SOCK_CLOEXEC);
    return connsock;
}

int Socket::listen()
{
    int ret = ::listen(this->fd(),SOMAXCONN);
}