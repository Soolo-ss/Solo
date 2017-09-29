//
// Created by pc4 on 2017/9/29.
//
#ifndef SOLO_NETWORKSTREAM_H
#define SOLO_NETWORKSTREAM_H

#include "Endpoint.h"

#include <list>

namespace net {

    class NetworkStream {
    public:
        NetworkStream() {
        }

        void addEndpoint(Endpoint& ep);

    private:
        Endpoint self;
        std::list<Endpoint> remote_eps;
    };
}

#endif //SOLO_NETWORKSTREAM_H
