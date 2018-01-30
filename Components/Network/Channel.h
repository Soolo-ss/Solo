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
        using BundlePtr = std::unique_ptr<Bundle>;

        Channel();

        Endpoint& ep();

        int64 channelID() const;

        void setEndpoint(std::unique_ptr<Endpoint> ep);
        void setNetwork(NetworkComponent* network);

    public:
        bool send(std::unique_ptr<Bundle> bundle);
        bool recv(std::unique_ptr<Bundle> bundle);

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
        std::unique_ptr<Endpoint> ep_;

        NetworkComponent* network_;

        std::vector<BundlePtr> sendBundles_;

        int64 channelID_;
    };

}




#endif //SOLO_CHANNEL_H
