//
// Created by pc4 on 2017/9/29.
//

#ifndef SOLO_ENDPOINT_H
#define SOLO_ENDPOINT_H

#include "../Common/Common.h"
#include "Socket.h"
#include "Channel.h"
#include <memory>

#define MAX_TCP_PACKET_LEN 1460

namespace  net {
    class Endpoint
    {
    public:
        Endpoint();
        //只允许移动 不允许拷贝
        Endpoint(const Endpoint& ep) = delete;
        Endpoint(Endpoint&& ep);

        Endpoint& operator=(const Endpoint& ep) = delete;
        Endpoint& operator=(Endpoint&& ep);

    private:
        Socket socket;
    };
}


#endif //SOLO_ENDPOINT_H
