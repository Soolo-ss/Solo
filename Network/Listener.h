//
// Created by pc4 on 2017/10/13.
//

#ifndef SOLO_LISTENER_H
#define SOLO_LISTENER_H

#include "Poller.h"
#include "Endpoint.h"

namespace  net {

    class Listener {

    };

    class WinListener : public Listener{
    public:
        WinListener(Endpoint ep);
    private:
        Endpoint ep;
        IOCPoller poller;
    };
}


#endif //SOLO_LISTENER_H
