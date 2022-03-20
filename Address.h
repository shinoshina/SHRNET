#ifndef _SHRNET_ADDRESS
#define _SHRNET_ADDRESS

#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <netdb.h>
#include <string.h>  //for memset
#include <string>

class Address
{

public:
    explicit Address(uint16_t port);

    Address(std::string ip, uint16_t port);

    Address() = default;

    struct sockaddr_in* sockAddr()
    {
        return &address;
    }

    void setSockaddr(const struct sockaddr_in& addr);

    
private:
    sockaddr_in address;
};


#endif /* _SHRNET_ADDRESS */