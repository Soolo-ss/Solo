//
// Created by pc4 on 2018/1/24.
//

#include "Listener.h"

namespace solo
{
    Listener::Listener()
    {

    }

    void Listener::init(int port)
    {
        ep_.socket();

        ep_.setAddress("0.0.0.0");
        ep_.setPort(port);
    }

    void Listener::start(Poller* poller)
    {
        if (ep_.setNonBlocking() < 0)
            return;

        if (ep_.setNoDalay() < 0)
            return;

        if (ep_.setReuseAddr() < 0)
            return;

        if (ep_.bind() < 0)
            return;

        registeToPoller(poller);

        ep_.listen();
    }

    void Listener::registeToPoller(Poller* poller)
    {
        poller->registeReadEvent(ep_.fd(), std::bind(&accpetHandler, this, std::placeholders::_1));
    }

    void Listener::accpetHandler(int newFd)
    {
        std::cout << "new fd here" << std::endl;
    }
}