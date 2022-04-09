#include "Acceptor.h"


using namespace std;


int main()
{
    Address addr(4321);
    Acceptor acceptor(addr);

    Address cliaddr;
    acceptor.testForAccept(cliaddr);

    return 0;

}