//
// Created by pc4 on 2017/9/29.
//

#ifndef SOLO_CHANNEL_H
#define SOLO_CHANNEL_H


#include "Endpoint.h"
#include "Bundle.h"

namespace net
{
    /*
     * 抽象了一个Socket连接
     */
    class Channel
    {
    public:
        using ChannelID = int;
        using Bundles = std::vector<Bundle>;

        Channel(Endpoint& ep, ChannelID id);

        void processBundles();

        void sendBundles();

    private:
        Bundles recvBundles_;
        Bundles sendBundles_;
    };
}


#endif //SOLO_CHANNEL_H
