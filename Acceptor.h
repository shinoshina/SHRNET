#ifndef _SHRNET_ACCEPTOR
#define _SHRNET_ACCEPTOR

#include "Channel.h"
#include "Socket.h"
#include "Address.h"




class Acceptor
{
public:

  Acceptor(Address& bindAddr);   

  void setConnentionCallback(EventCallback cb);

  void handleConnection();

  void testForAccept(Address& addr)
  {
      acceptSocket.acceptConn(addr);
      std::cout<<"accept done!"<<std::endl;
  }




private:
Socket acceptSocket;
Channel acceptorChannel;


};


#endif