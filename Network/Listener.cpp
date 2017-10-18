//
// Created by pc4 on 2017/10/13.
//

#include "Listener.h"

namespace  net
{
    WinListener::WinListener(Endpoint ep)
        : ep(std::move(ep)), poller()
    {
        ep.init();
    }


}