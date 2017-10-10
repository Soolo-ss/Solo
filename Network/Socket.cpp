//
// Created by 盛晟 on 2017/10/2.
//

#include "Socket.h"

namespace net
{

    Socket::Socket()
        : sock_(UNREACHED_SCOKET)
    {

    }

    int Socket::socket() {
        setFileDesc(::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP));
    }

    int Socket::bind(std::string address, uint8_t port) {
        sockaddr_in sockaddress;

        memset(&sockaddress, 0, sizeof(sockaddress));

        sockaddress.sin_family = AF_INET;
        sockaddress.sin_port = htons(port);
    #if SOLO_PLATFORM == SOLO_PLATFORM_WIN
        sockaddress.sin_addr.S_un.S_addr = inet_addr(address.c_str());
    #else
        inet_aton(address.c_str(), &sockaddress.sin_addr);
    #endif

        return ::bind(sock_, (sockaddr*)&sockaddress, sizeof(sockaddress));
    }

    int Socket::listen(int backlog) {
        return ::listen(sock_, backlog);
    }

    std::shared_ptr<Socket> Socket::accept() {
        sockaddr_in sin;
        socklen_t sinLen = sizeof(sin);

        int ret = (int)::accept(sock_, (sockaddr*)&sin, &sinLen);

#if SOLO_PLATFORM == SOLO_PLATFORM_WIN
        if (ret == INVALID_SOCKET)
            return nullptr;
#else
        if (ret == -1)
            return nullptr;
#endif

        auto pNew = std::make_shared<Socket>();

        pNew->setFileDesc(ret);

        return pNew;
    }

    int Socket::send(const void *msg, int len, int flags) {
#if SOLO_PLATFORM == SOLO_PLATFORM_WIN
        return ::send(sock_, (char*)msg, len, flags);
#else
        return ::send(sock_, msg, len, flags);
#endif
    }

    int Socket::recv(void *buff, int len, unsigned int flags) {
#if SOLO_PLATFORM == SOLO_PLATFORM_WIN
        return ::recv(sock_, (char*)buff, len, flags);
#else
        return ::recv(sock_, buff, len, flags);
#endif
    }

    int Socket::connect(std::string address, uint8_t port) {
        sockaddr_in sockaddress;

        memset(&sockaddress, 0, sizeof(sockaddress));

        sockaddress.sin_family = AF_INET;
        sockaddress.sin_port = htons(port);
#if SOLO_PLATFORM == SOLO_PLATFORM_WIN
        sockaddress.sin_addr.S_un.S_addr = inet_addr(address.c_str());
#else
        inet_aton(address.c_str(), &sockaddress.sin_addr);
#endif
        return ::connect(sock_, (sockaddr*)&sockaddress, sizeof(sockaddress));
    }

    void Socket::setFileDesc(int fd) {
        sock_ = fd;
    }

}