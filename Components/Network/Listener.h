//
// Created by pc4 on 2018/1/24.
//

#ifndef SOLO_LISTENER_H
#define SOLO_LISTENER_H

#include "Endpoint.h"
#include "Poller.h"

namespace solo
{
    class Listener
    {
    public:
        Listener();

        void init(int port);

        void start(Poller* poller);

        void accpetHandler(int newFd);

    private:
        void registeToPoller(Poller* poller);

    private:
        int port_;

        Endpoint ep_;
    };
}




#endif //SOLO_LISTENER_H
