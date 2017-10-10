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
        ENDPOINT_TYPE_SERVER = 1,
        ENDPOINT_TYPE_CLIENT = 2
    };

    /*
     * 抽象了一个服务器端点或者客户端端点
     */
    class Endpoint {
    public:
        using Endpoints = std::vector<Endpoint>;

        Endpoint() = delete;
        Endpoint(std::string address, int port, int type = 1);

        int type()
        {
            return type_;
        }

        int send(void* buff, size_t bufflen);

    private:
        void init();

    private:
        Socket socket_;
        Endpoints endpoints_;

        std::string address_;
        int port_;
        int type_;
    };
}


#endif //SOLO_ENDPOINT_H
