//
// Created by pc4 on 2017/9/29.
//

#include "NetworkStream.h"

namespace net
{
    void NetworkStream::addEndpoint(Endpoint &ep) {
        remote_eps.emplace_back(ep);
    }
}
