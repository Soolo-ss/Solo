//
// Created by pc4 on 2018/1/22.
//

#include "Packet.h"

#include <winsock2.h>

namespace solo
{
    int Packet::recv(int fd)
    {
        int readSize = ::recv(fd, (char*)&buffer_[wpos_], writeableSize(), 0);

        if (readSize == -1)
            return 0;

        wpos_ += readSize;

        return readSize;
    }
}


