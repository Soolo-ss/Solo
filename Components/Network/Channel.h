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
        Channel();

        void setEndpoint(std::unique_ptr<Endpoint> ep);
        void setNetwork(NetworkComponent* network);

    public:
        bool send(std::unique_ptr<Bundle> bundle);
        bool recv(std::unique_ptr<Bundle> bundle);

        void registeReadToPoller();
        void registeWriteToPoller();

    private:
        void onRecvData(int fd);

    private:
        std::unique_ptr<Endpoint> ep_;

        NetworkComponent* network_;
    };

}




#endif //SOLO_CHANNEL_H
