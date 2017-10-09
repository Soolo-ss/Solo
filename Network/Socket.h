//
// Created by 盛晟 on 2017/10/2.
//

#ifndef SOLO_SOCKET_H
#define SOLO_SOCKET_H

#include "../Common/Common.h"

#if SOLO_PLATFORM == SOLO_PLATFORM_OSX

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#elif SOLO_PLATFORM == SOLO_PLATFORM_WIN

#include <winsock2.h>
#include <ws2tcpip.h>

#endif

namespace net {
#define UNREACHED_SCOKET ~0

#if SOLO_PLATFORM == SOLO_PLATFORM_OSX
    using SOCK = int;
#elif SOLO_PLATFORM == SOLO_PLATFORM_WIN
    using SOCK = ::SOCKET;
#endif

    /*
     * 封装了各平台的socket细节
     */
    class Socket {
    public:
        Socket();

        int bind(std::string address, uint8_t port);

        int listen(int backlog = 5);

        int accept(void* addr, int addrlen);

        int send(const void* msg, int len, int flags);

        int recv(void* buff, int len, unsigned int flags);

    private:
        SOCK sock_;
    };

}

#endif //SOLO_SOCKET_H
