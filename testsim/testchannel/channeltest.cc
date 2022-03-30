#include "Channel.h"
#include <iostream>

using namespace std;

int main()
{
    Channel channel(10);

    channel.setCloseCallback([](){
        cout<<"success"<<endl;
    });
    
    channel.handleEvent();

    return 0;


}