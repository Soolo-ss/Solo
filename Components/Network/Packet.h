//
// Created by pc4 on 2018/1/22.
//

#ifndef SOLO_PAKCET_H
#define SOLO_PAKCET_H

#include <array>

#include "../../Common/Common.h"

namespace solo
{
    const size_t MAX_TCP_PACKET_SIZE = 1460;

    class Packet
    {
    public:
        size_t appendBytes(std::vector<byte> bytes)
        {
            size_t copySize = 0;

            if (bytes.size() > writeableSize())
                copySize = writeableSize();
            else
                copySize = bytes.size();

            std::copy(std::begin(bytes), std::begin(bytes) + copySize, std::begin(buffer_) + wpos_);

            wpos_ += copySize;

            return copySize;
        }

        int recv(int fd);
        int send(int fd);

        const std::array<byte, solo::MAX_TCP_PACKET_SIZE>& buffer()
        {
            return buffer_;
        };

    public:
        size_t wpos()
        {
            return wpos_;
        }

        size_t rpos()
        {
            return rpos_;
        }

        size_t writeableSize()
        {
            return MAX_TCP_PACKET_SIZE - wpos_;
        }

        size_t readableSize()
        {
            return wpos_ - rpos_;
        }

    private:
        std::array<byte, solo::MAX_TCP_PACKET_SIZE> buffer_;

        size_t wpos_ = 0;
        size_t rpos_ = 0;

    };
}


#endif //SOLO_PAKCET_H
