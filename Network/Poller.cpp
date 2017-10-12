//
// Created by pc4 on 2017/10/11.
//

#include "Poller.h"

namespace net {

    void Poller::addEndpoint(Endpoint* ep) {
        eps_.push_back(ep);
    }
}
