//
// Created by pc4 on 2018/1/24.
//

#include "Listener.h"
#include "Channel.h"
#include "NetworkComponent.h"

namespace solo
{
    Listener::Listener(NetworkComponent* network)
        : port_(0),
          ep_(),
          network_(network)
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
        {
            std::cout << WSAGetLastError() << std::endl;

            return;
        }

        if (ep_.setNoDalay() < 0)
        {
            std::cout << "set delay error" << std::endl;
            return;
        }

        if (ep_.setReuseAddr() < 0)
        {
            std::cout << "set reuse addr error" << std::endl;
            return;
        }

        if (ep_.bind() < 0)
        {
            std::cout << "bind error" << std::endl;
            return;
        }

        registeToPoller(poller);

        if (ep_.listen() < 0)
        {
            std::cout << "listen error" << std::endl;
            return;
        }
    }

    void Listener::registeToPoller(Poller* poller)
    {
        if (!poller->registeReadEvent(ep_.fd(), std::bind(&accpetHandler, this, std::placeholders::_1)))
            std::cout << "error to registe read event " << std::endl;
    }

    void Listener::accpetHandler(int fd)
    {
        std::unique_ptr<Endpoint> newEp = ep_.accept();

        ChannelPtr newChannel = std::make_shared< Channel >();
        newChannel->setEndpoint(std::move(newEp));
        newChannel->setNetwork(network_);

        network_->registeChannel(newChannel);

        newChannel->registeReadToPoller();
    }
}