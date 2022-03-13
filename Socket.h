#ifndef _SHRNET_SOCKET
#define _SHRNET_SOCKET

#include <sys/socket.h>
#include "Address.h"

class Socket
{
public:
    explicit Socket()
    {
        //SET NONBLOCK SOCKET ALLOW TCP PROTOCOL 
        _socket = socket(PF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
    };

    void bindAddress(Address& addr);

    int acceptConn(Address * addr);

    int listen();

    int fd();

private:
    int _socket;
};

#endif /*_SHRNET_SOCKET*/