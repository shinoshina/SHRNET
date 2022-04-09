

#include "Socket.h"

class Address;

int Socket::fd()
{
    return _socket;
}

void Socket::bindAddress(Address &addr)
{
    int err = ::bind(_socket, (struct sockaddr *)(addr.sockAddr()), sizeof(sockaddr_in));
    if (err < 0)
    {
        std::cout << err << std::endl;
        std::cout << "bind error" << std::endl;
    }
}

int Socket::acceptConn(Address &addr)
{
    struct sockaddr_in peeraddr;
    socklen_t addrlen = sizeof(peeraddr);
    memset(&peeraddr, 0, sizeof(peeraddr));
    int connsock = ::accept4(this->fd(), (sockaddr *)&peeraddr, &addrlen, SOCK_NONBLOCK | SOCK_CLOEXEC);
    if (connsock != -1)
        std::cout << connsock << std::endl;
    if (connsock >= 0)
    {
        addr.setSockaddr(peeraddr);
        std::cout<<"accept success"<<std::endl;
    }
    return connsock;
}

int Socket::listen()
{
    int ret = ::listen(this->fd(), SOMAXCONN);
    std::cout<<"listening"<<std::endl;
}