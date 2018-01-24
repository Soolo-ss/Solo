//
// Created by pc4 on 2018/1/23.
//

#if SOLO_PLATFORM == SOLO_PLATFORM_WIN
#include <winsock2.h>
#include <afxres.h>

#else
#include <socket>
#endif

#include "Endpoint.h"

namespace solo
{
    Endpoint::Endpoint()
    {

    }

    Endpoint::Endpoint(std::string address, int port)
        : address_(address), port_(port)
    {
    }

    int Endpoint::socket()
    {
#if SOLO_PLATFORM == SOLO_PLATFORM_WIN
        if (fd_ == INVALID_SOCKET && WSAGetLastError() == WSANOTINITIALISED)
        {
            WSADATA wsadata;
            WSAStartup(0x202, &wsadata);
        }
#endif

        fd_ = ::socket(AF_INET, SOCK_STREAM, 0);

        return fd_;
    }

    int Endpoint::bind()
    {
        sockaddr_in localAddr;

        memset(&localAddr, 0, sizeof(sockaddr_in));

        localAddr.sin_addr.S_un.S_addr = inet_addr(address_.c_str());
        localAddr.sin_family = AF_INET;
        localAddr.sin_port = port_;

        return ::bind(fd_, (sockaddr*)&localAddr, sizeof(sockaddr));
    }

    int Endpoint::listen(int backlog)
    {
        return ::listen(fd_, backlog);
    }

    std::unique_ptr<Endpoint> Endpoint::accept()
    {
        sockaddr_in  sockAddr;
        int addrLen = sizeof(sockaddr);

        int ret = ::accept(fd_, (sockaddr*)&sockAddr, &addrLen);

#if SOLO_PLATFORM == SOLO_PLATFORM_WIN
        if (ret == INVALID_SOCKET)
            return nullptr;
#else
        if (ret < 0)
            return nullptr;
#endif

        std::unique_ptr<Endpoint> ep = Singleton< ObjectPool<Endpoint> >::getInstance().createObject();

        ep->setFd(ret);
        ep->setAddress(inet_ntoa(sockAddr.sin_addr));
        ep->setPort(sockAddr.sin_port);
        ep->setNoDalay();
        ep->setNonBlocking();

        return ep;
    }

    int Endpoint::setReuseAddr()
    {
#if SOLO_PLATFORM == SOLO_PLATFORM_WIN
        bool reuse = true;
#else
        int reuse = 1;
#endif
        return ::setsockopt(fd_, SOL_SOCKET, SO_REUSEADDR, (char*)&reuse, sizeof(reuse));
    }

    int Endpoint::setNoDalay() {
        int nodelay = 1;
        return setsockopt(fd_, IPPROTO_TCP, TCP_NODELAY, (char*)&nodelay, sizeof(nodelay));
    }

    int Endpoint::setNonBlocking()
    {
#if SOLO_PLATFORM == SOLO_PLATFORM_WIN
        u_long  val = 1;
        return ::ioctlsocket(fd_, FIONBIO, &val);
#else
        int val = O_NONBLOCK;
        return ::fcntl(fd_, F_SETFL, val);
#endif
    }

    void Endpoint::setFd(int fd)
    {
        if (fd)
            fd_ = fd;
    }

    void Endpoint::setAddress(const char *address)
    {
        address_ = std::string(address);
    }

    void Endpoint::setPort(int port)
    {
        port_ = port;
    }


}