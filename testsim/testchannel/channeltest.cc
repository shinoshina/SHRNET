#include "Channel.h"
#include <iostream>

using namespace std;


void TEST()
{
    cout<<"nimasile"<<endl;
}
int main()
{
    Channel channel(10);
    EventCallback cb = TEST;

    channel.setCloseCallback(cb);
    
    channel.handleEvent();

    return 0;


}