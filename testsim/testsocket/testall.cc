#include "Address.h"
#include "Socket.h"

int main()
{
    Socket listenfd;

    Address seraddr(4321);

    listenfd.bindAddress(seraddr);

    listenfd.listen();
    std::cout << listenfd.fd() << std::endl;

    Address cliaddr;

    while (1)
    {
        int connfd = listenfd.acceptConn(cliaddr);
    }
    std::cout << listenfd.fd() << std::endl;
}