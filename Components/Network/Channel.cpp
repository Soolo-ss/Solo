//
// Created by pc4 on 2018/1/26.
//

#include "Channel.h"
#include "NetworkComponent.h"

namespace solo
{

    Channel::Channel()
        : network_(nullptr),
          ep_()
    {

    }


    void Channel::setEndpoint(std::unique_ptr<Endpoint> ep)
    {
        ep_ = std::move(ep);
    }

    void Channel::setNetwork(NetworkComponent *network)
    {
        network_ = network;
    }

    void Channel::registeReadToPoller()
    {
        this->network_->registeReadEndpointToPoller(ep_.get(), std::bind(Channel::onRecvData, this, std::placeholders::_1));
    }

    void Channel::onRecvData(int fd)
    {
        std::cout <<"on recv data" << std::endl;

        if (fd != (ep_->fd()))
            return;

        std::unique_ptr<Packet> packet = Singleton< ObjectPool<Packet> >::getInstance().createObject();

        int readSize = packet->recv(fd);

        for (size_t i = packet->rpos(); i != packet->wpos(); ++i)
        {
            std::cout << packet->buffer()[i];
        }

        std::cout << std::endl;
    }
}