//
// Created by pc4 on 2018/1/23.
//

#ifndef SOLO_ENDPOINT_H
#define SOLO_ENDPOINT_H

#include <winsock2.h>
#include "../../Common/Common.h"


namespace solo
{
    class Endpoint
    {
    public:
        Endpoint();
        Endpoint(std::string address, int port);

        int socket();

        int bind();

        int listen(int backlog = 5);

        std::unique_ptr<Endpoint> accept();

        void setFd(int fd);
        void setAddress(const char* address);
        void setPort(int port);

        int setReuseAddr();
        int setNoDalay();
        int setNonBlocking();

        int send();

        int recv();

        int fd()
        {
            return fd_;
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
