

#include "Acceptor.h"

// void Acceptor::setConnentionCallback(EventCallback cb)
// {
//     acceptorChannel.setReadCallback(cb);
// }

Acceptor::Acceptor(Address &bindAddr, Eventloop *loop) : acceptSocket(Socket()),
                                                         acceptorChannel(acceptSocket.fd()),
                                                         mainLoop(loop)
{
    acceptSocket.bindAddress(bindAddr);
   
    acceptorChannel.setReadCallback(std::bind(&Acceptor::handleConnection, this));
    
    loop->updateChannels(&acceptorChannel);
    acceptSocket.listen();
}

void Acceptor::handleConnection()
{
    Address addr;
    int connfd = acceptSocket.acceptConn(addr);
    std::cout << "accept done!"
              << "   connection fd  " << connfd << std::endl;
    std::cout << "handle connection" << std::endl;
}