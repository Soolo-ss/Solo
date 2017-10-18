//
// Created by pc4 on 2017/10/11.
//

#include "Poller.h"

#include <ws2tcpip.h>

namespace net {

    void Poller::addEndpoint(Endpoint* ep) {
        eps_.push_back(ep);
    }


    IOCPoller::IOCPoller()
        : Poller()
    {
        iocpHandle = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
    }
}
