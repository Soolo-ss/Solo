//
// Created by pc4 on 2017/9/29.
//

#include "Endpoint.h"

namespace net {

Endpoint::Endpoint()
    : socket()
{

}

Endpoint::Endpoint(Endpoint &&ep)
    : socket(std::move(ep.socket))
{

}



}