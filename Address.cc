

#include "Address.h"


Address::Address(uint16_t port)
{
    memset(&address,0,sizeof(sockaddr_in));

    address.sin_family = AF_INET;
    in_addr_t ip = INADDR_ANY;
    address.sin_addr.s_addr = ip;
    address.sin_port = htons(port);
}