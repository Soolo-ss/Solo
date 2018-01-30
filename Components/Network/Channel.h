//
// Created by pc4 on 2018/1/26.
//

#ifndef SOLO_CHANNEL_H
#define SOLO_CHANNEL_H

#include "Endpoint.h"
#include "Bundle.h"

namespace solo
{
    class NetworkComponent;

    class Channel
    {
    public:
        using BundlePtr = unique_ptr<Bundle>;

        Channel();

        Endpoint& ep();

        int64 channelID() const;

        void setEndpoint(unique_ptr<Endpoint> ep);
        void setNetwork(NetworkComponent* network);
        void setChannelID(int64 channelID);

    public:
        bool send(unique_ptr<Bundle> bundle);
        bool recv(unique_ptr<Bundle> bundle);

        void registeReadToPoller();
        void registeWriteToPoller();
        void unregisteReadToPoller();
        void unregisteWriteToPoller();

    private:
        void onRecvData(int fd);
        void onSendData(int fd);

        void pushSendBundle(BundlePtr bundle);
        bool sendAllBundles();

    private:
        unique_ptr<Endpoint> ep_;

        NetworkComponent* network_;

        std::vector<BundlePtr> sendBundles_;

        int64 channelID_;
    };

}




#endif //SOLO_CHANNEL_H
