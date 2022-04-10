#include "Eventloop.h"
#include "Acceptor.h"


using namespace std;

int main()
{
    Epoller poller;
    Eventloop loop1(&poller);
    Address addr(4321);
    Acceptor acceptor(addr,&loop1);

    loop1.loop();
    return 0;

    


}