//
// Created by pc4 on 2017/9/29.
//

#ifndef SOLO_ENDPOINT_H
#define SOLO_ENDPOINT_H

#include "../Common/Common.h"
#include "Socket.h"

#define MAX_TCP_PACKET_LEN 1460

namespace  net {

    using byte = unsigned char;
    enum ENDPOINT_TYPE {
        ENDPOINT_TYPE_SERVER,
        ENDPOINT_TYPE_CLIENT
    };

    class Endpoint {
    public:
        Endpoint(std::string, int port, ENDPOINT_TYPE ep_type);

        constexpr ENDPOINT_TYPE type()
        {
            return type_;
        }

        int send(void* buff, size_t bufflen);
    private:
        Socket socket_;

        std::string address_;
        int port_;
        ENDPOINT_TYPE type_;
    };
}


#endif //SOLO_ENDPOINT_H
