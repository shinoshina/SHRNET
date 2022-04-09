

#include "Acceptor.h"


// void Acceptor::setConnentionCallback(EventCallback cb)
// {
//     acceptorChannel.setReadCallback(cb);
// }

Acceptor::Acceptor(Address& bindAddr):acceptSocket(Socket()),
                     acceptorChannel(acceptSocket.fd())
{
    acceptSocket.bindAddress(bindAddr);
    acceptSocket.listen();
    std::cout<<"not execept"<<std::endl;
    acceptorChannel.setReadCallback(std::bind(&Acceptor::handleConnection,this));
}

void Acceptor::handleConnection()
{
    std::cout<<"handle connection"<<std::endl;
}