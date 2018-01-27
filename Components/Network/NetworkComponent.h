//
// Created by pc4 on 2018/1/24.
//

#ifndef SOLO_NETWORKCOMPONENT_H
#define SOLO_NETWORKCOMPONENT_H

#include <unordered_map>

#include "../Component.h"
#include "Listener.h"
#include "Channel.h"

namespace solo
{
    using ChannelPtr = std::shared_ptr< Channel >;
    using ChannelMap = std::unordered_map< int64, ChannelPtr >;

    class NetworkComponent : public Component
    {
    public:
        NetworkComponent(ComponentManager* manager);

        bool install() override;

        bool uninstall() override;

        bool init(int port);

        void processNetwork();

        void registeReadEndpointToPoller(Endpoint* endpoint, std::function<void(int)> readCallback);
        void registeWriteEndpointToPoller(Endpoint* endpoint, std::function<void(int)> writeCallback);

    public:
        void registeChannel(ChannelPtr channel);
        void unregisteChannel(int64 channelID);

    private:
        Listener listener_;
        Poller* poller_;

        static  int64 channelID;
        ChannelMap channels_;
    };


}

#endif //SOLO_NETWORKCOMPONENT_H
