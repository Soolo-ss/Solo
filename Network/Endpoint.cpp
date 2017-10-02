//
// Created by pc4 on 2017/9/29.
//

#include "Endpoint.h"

namespace net {

    Endpoint::Endpoint(std::string address, int port, ENDPOINT_TYPE ep_type)
        : address_(address), port_(port), type_(type)
    {
    }


    int Endpoint::send(void *buff, size_t bufflen) {

    }
}