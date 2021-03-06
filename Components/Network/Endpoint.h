//
// Created by pc4 on 2018/1/23.
//

#ifndef SOLO_ENDPOINT_H
#define SOLO_ENDPOINT_H

#include "../../Common/Common.h"
#include "Packet.h"

#if SOLO_PLATFORM == SOLO_PLATFORM_WIN
#include <winsock2.h>
#endif

namespace solo
{
    class Endpoint : public PoolObject
    {
    public:
        Endpoint();
        Endpoint(std::string address, int port);

        int socket();

        int bind();

        int listen(int backlog = 5);

        unique_ptr<Endpoint> accept();

        void setFd(int fd);
        void setAddress(const char* address);
        void setPort(int port);

        int setReuseAddr();
        int setNoDalay();
        int setNonBlocking();

        int send(Packet& packet);

        int recv();

        int fd()
        {
            return fd_;
        }

        void clear() override
        {

        }

    private:
        std::string address_;
        int port_;
#if SOLO_PLATFORM == SOLO_PLATFORM_WIN
        int fd_ = INVALID_SOCKET;
#else
        int fd_ = -1;
#endif
    };
}




#endif //SOLO_ENDPOINT_H
