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
            LOG(ERROR) << "Socket set nonblocking failed";
            return;
        }

        if (ep_.setNoDalay() < 0)
        {
            LOG(ERROR) << "Socket set delay error";
            return;
        }

        if (ep_.setReuseAddr() < 0)
        {
            LOG(ERROR) << "Socket set reuse addr error";
            return;
        }

        if (ep_.bind() < 0)
        {
            LOG(ERROR) << "Socket bind error";
            return;
        }

        registeToPoller(poller);

        if (ep_.listen() < 0)
        {
            LOG(ERROR) << "Socket listen error";
            return;
        }
    }

    void Listener::registeToPoller(Poller* poller)
    {
        if (!poller->registeReadEvent(ep_.fd(), std::bind(&accpetHandler, this, std::placeholders::_1)))
            LOG(ERROR) << "Listener::registeToPoller Failed";
    }

    void Listener::accpetHandler(int fd)
    {
        unique_ptr<Endpoint> newEp = ep_.accept();

        ChannelPtr newChannel = std::make_shared< Channel >();
        newChannel->setEndpoint(std::move(newEp));
        newChannel->setNetwork(network_);

        network_->registeChannel(newChannel);

        newChannel->registeReadToPoller();
    }
}