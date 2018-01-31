//
// Created by pc4 on 2018/1/26.
//

#include "Packet.h"
#include "Channel.h"
#include "NetworkComponent.h"

#include <assert.h>

namespace solo
{

    Channel::Channel()
        : network_(nullptr),
          ep_()
    {

    }

    Endpoint& Channel::ep()
    {
        return *ep_;
    }

    int64 Channel::channelID() const
    {
        return channelID_;
    };

    void Channel::setEndpoint(unique_ptr<Endpoint> ep)
    {
        ep_ = std::move(ep);
    }

    void Channel::setNetwork(NetworkComponent *network)
    {
        network_ = network;
    }

    void Channel::setChannelID(int64 channelID)
    {
        channelID_ = channelID;
    }

    void Channel::registeReadToPoller()
    {
        this->network_->registeReadEndpointToPoller(ep_.get(), std::bind(Channel::onRecvData, this, std::placeholders::_1));
    }

    void Channel::registeWriteToPoller()
    {
        network_->registeWriteEndpointToPoller(ep_.get(), std::bind(Channel::onSendData, this, std::placeholders::_1));
    }

    void Channel::unregisteReadToPoller()
    {
        network_->unregisteReadEndpointToPoller(ep_.get());
    }

    void Channel::unregisteWriteToPoller()
    {
        network_->unregisteWriteEndpointToPoller(ep_.get());
    }

    void Channel::onRecvData(int fd)
    {
        if (fd != (ep_->fd()))
            return;

        unique_ptr<Packet> packet = Singleton< ObjectPool<Packet> >::getInstance().createObject();

        int readSize = packet->recv(fd);

        LOG(DEBUG) << "recvSize : " << readSize;
        LOG(DEBUG) << "recvStr : " << packet->str();

        if (readSize == 0)
        {
            LOG(WARNING) << "Client Reset Connection";

            unregisteReadToPoller();
            network_->unregisteChannel(channelID_);
        }
        else if (readSize == -1)
        {
            return;
        }
    }

    void Channel::onSendData(int fd)
    {
        assert(fd == ep_->fd());

        //成功发送完所有数据 取消Poller关注
        if (sendAllBundles())
        {
            unregisteWriteToPoller();
        }
    }

    bool Channel::send(BundlePtr bundle)
    {
        //尝试直接发送
        for (int i = bundle->currentSendPos(); i != bundle->packets().size(); ++i)
        {
            auto sp = *(bundle->packets()[i]);

            int sendSize = sp.readableSize();

            int size = ep_->send(sp);

            if (size != sendSize)
            {
                bundle->setSendPos(i);
                break;
            }
            else
            {
                bundle->setSendPos(i + 1);
            }
        }

        //没有发送完
        if (bundle->currentSendPos() != bundle->size())
        {
            pushSendBundle(std::move(bundle));

            registeWriteToPoller();
        }
    }

    void Channel::pushSendBundle(BundlePtr bundle)
    {
        bundle->setSendChannel(this);
        sendBundles_.push_back(std::move(bundle));
    }

    bool Channel::sendAllBundles()
    {
        auto iter = std::begin(sendBundles_);

        for ( ; iter != std::end(sendBundles_); )
        {
            if (!(*iter)->send(this))
            {
                break;
            }
            else
            {
                iter = sendBundles_.erase(iter);
            }
        }

        return sendBundles_.size() == 0;
    }
}