//
// Created by 盛晟 on 2017/10/2.
//

#include "Socket.h"

namespace net
{

Socket::Socket()
    : sock_(UNREACHED_SCOKET)
{
    sock_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}


int Socket::bind(std::string address, uint8_t port) {
    sockaddr_in sockaddress;

    memset(&sockaddress, 0, sizeof(sockaddress));

    sockaddress.sin_family = AF_INET;
    sockaddress.sin_port = htons(port);
    inet_aton(address.c_str(), &sockaddress.sin_addr);

    return ::bind(sock_, (sockaddr*)&sockaddress, sizeof(sockaddress));
}

int Socket::listen(int backlog) {
    return ::listen(sock_, backlog);
}

int Socket::accept(void *addr, int addrlen) {
    return ::accept(sock_, (sockaddr_in*)addr, (socklen_t*)&addrlen);
}

int Socket::send(const void *msg, int len, int flags) {
    return ::send(sock_, msg, len, flags);
}

int Socket::recv(void *buff, int len, unsigned int flags) {
    return ::recv(sock_, buff, len, flags);
}

}