//
// Created by pc4 on 2018/1/23.
//
#include "Endpoint.h"

#if SOLO_PLATFORM == SOLO_PLATFORM_WIN
#include <ws2tcpip.h>

#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>>
#include <netinet/tcp.h>
#endif

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
        fd_ = ::socket(AF_INET, SOCK_STREAM, 0);

#if SOLO_PLATFORM == SOLO_PLATFORM_WIN
        if (fd_ == INVALID_SOCKET && WSAGetLastError() == WSANOTINITIALISED)
        {
            WSADATA wsadata;
            WSAStartup(0x202, &wsadata);

            fd_ = ::socket(AF_INET, SOCK_STREAM, 0);
        }
#endif



        return fd_;
    }

    int Endpoint::bind()
    {
        sockaddr_in localAddr;

        memset(&localAddr, 0, sizeof(sockaddr_in));

        localAddr.sin_addr.S_un.S_addr = inet_addr(address_.c_str());
        localAddr.sin_family = AF_INET;
        localAddr.sin_port = htons(port_);

        return ::bind(fd_, (sockaddr*)&localAddr, sizeof(sockaddr));
    }

    int Endpoint::listen(int backlog)
    {
        return ::listen(fd_, backlog);
    }

    unique_ptr<Endpoint> Endpoint::accept()
    {
        sockaddr_in  sockAddr;
        socklen_t addrLen = sizeof(sockaddr);

        int ret = ::accept(fd_, (sockaddr*)&sockAddr, &addrLen);

#if SOLO_PLATFORM == SOLO_PLATFORM_WIN
        if (ret == INVALID_SOCKET)
            return unique_ptr<Endpoint>(nullptr);
#else
        if (ret < 0)
            return nullptr;
#endif

        unique_ptr<Endpoint> ep = Singleton< ObjectPool<Endpoint> >::getInstance().createObject();

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

    int Endpoint::send(Packet &packet)
    {
        int send = packet.send(fd_);

        return send;
    }

}