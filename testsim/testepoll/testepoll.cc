#include "Address.h"
#include "Socket.h"
#include "Epoller.h"
#include <fstream>

int listenfD;

using namespace std;
int main()
{
    ofstream out("countout.txt");
    std::cout.rdbuf(out.rdbuf());
    Socket listenfd;
    Address seraddr(4321);
    listenfd.bindAddress(seraddr);
    listenfd.listen();

    Epoller epoller;

    listenfD = listenfd.fd();
    // new connection event is a readable event
    Channel acceptChannel(listenfd.fd());

    EventCallback readcallback = [acceptChannel]() -> void
    {
        sockaddr_in client;
        socklen_t addrlen = sizeof(client);
        int connectfd = accept(acceptChannel.getFd(), (struct sockaddr *)&client, &addrlen);
    };

    acceptChannel.setReadCallback(readcallback);
    epoller.updateMonitorChannel(&acceptChannel);

    ChannelList channelList;

    while (1)
    {
        epoller.epoll(&channelList);

        ChannelList::iterator it;
        std::cout << "begin to handle" << std::endl;
        for (it = channelList.begin(); it != channelList.end(); it++)
        {
            (*it).handleEvent();
            std::cout << "handlling" << std::endl;
        }
    }
    std::cout << listenfd.fd() << std::endl;

    /// to do �Ǹ��½���channellistΪ�գ�����������϶�û�лص����������ܸ�ֵ�����ʱ��ѻص��������ƹ�ȥ�������и��õ�д��
}