//
// Created by pc4 on 2018/1/24.
//

#include "NetworkComponent.h"
#include "SelectPoller.h"

namespace solo
{
    int64 NetworkComponent::channelID = 0;

    NetworkComponent::NetworkComponent(ComponentManager* manager)
        : Component(manager),
          poller_(nullptr),
          listener_(this)
    {

    }

    bool NetworkComponent::install()
    {
        return true;
    }

    bool NetworkComponent::uninstall()
    {
        return true;
    }

    bool NetworkComponent::init(int port)
    {
        listener_.init(port);

        poller_ = new SelectPoller();
        poller_->setRun(true);

        listener_.start(poller_);

        return true;
    }

    void NetworkComponent::processNetwork()
    {
        poller_->poll();
    }

    void NetworkComponent::registeChannel(ChannelPtr channel)
    {
        ++channelID;
        channels_.insert(std::make_pair(channelID, channel));
    }

    void NetworkComponent::unregisteChannel(int64 channelID)
    {
        if (channels_.find(channelID) != std::end(channels_))
        {
            channels_.erase(channelID);
        }
    }

    void NetworkComponent::registeReadEndpointToPoller(Endpoint* endpoint, std::function<void(int)> readCallback)
    {
        poller_->registeReadEvent(endpoint->fd(), readCallback);
    }

    void NetworkComponent::registeWriteEndpointToPoller(Endpoint *endpoint, std::function<void(int)> writeCallback)
    {
        poller_->registeWriteEvent(endpoint->fd(), writeCallback);
    }

}