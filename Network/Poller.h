//
// Created by pc4 on 2017/10/11.
// 封装各平台的io函数
//

#ifndef SOLO_POLLER_H
#define SOLO_POLLER_H

#include "Endpoint.h"

namespace net {
    using Endpoints = std::vector<Endpoint*>;

    class Poller {
    public:
        Poller();

        virtual void poll() = 0;

        void addEndpoint(Endpoint* ep);
    private:
        Endpoints eps_;
    };


    class Epoller : public Poller {

    };

#if SOLO_PLATFORM == SOLO_PLATFORM_WIN
    class IOCPoller : public  Poller {
    public:
        IOCPoller();

    private:
        HANDLE iocpHandle;
    };

#endif

}
#endif //SOLO_POLLER_H
