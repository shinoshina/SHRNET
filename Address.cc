

#include "Address.h"


//     /* Structure describing an Internet socket address.  */
//     struct sockaddr_in
//     {
//         sa_family_t    sin_family; /* address family: AF_INET */
//         uint16_t       sin_port;   /* port in network byte order */
//         struct in_addr sin_addr;   /* internet address */
//     };

//     /* Internet address. */
//     typedef uint32_t in_addr_t;
//     struct in_addr
//     {
//         in_addr_t       s_addr;     /* address in network byte order */
//     };


Address::Address(uint16_t port)
{
    memset(&address,0,sizeof(sockaddr_in));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(port);

    std::cout<<port<<std::endl;
}


void Address::setSockaddr(const struct sockaddr_in& addr)
{
    address = addr;
}