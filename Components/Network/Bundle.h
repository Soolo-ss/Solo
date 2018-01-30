//
// Created by pc4 on 2018/1/17.
//

#ifndef SOLO_BUNDLE_H
#define SOLO_BUNDLE_H

#include <memory>
#include "Packet.h"
#include "../../Common/Common.h"
#include <assert.h>

namespace solo
{
    class Channel;

    class Bundle
    {
    public:
        using PacketPtr = unique_ptr<Packet>;
        using Packets = std::vector< PacketPtr >;

    public:
        template<typename V>
        Bundle &operator<<(V v)
        {
            size_t vSize = sizeof(V);

            onAppendData(vSize, toBytes(v));
        }

        int32 size()
        {
            return packets_.size();
        }

        int32 currentSendPos()
        {
            return currentSendPos_;
        }

        Packets& packets()
        {
            return packets_;
        }

        void setSendPos(int32 sendPos)
        {
            currentSendPos_ = sendPos;
        }

        void setSendChannel(Channel* channel)
        {
            currentSendChannel_ = channel;
        }

        bool send(Channel* channel);

        bool sendHead(Channel* channel);

    private:
        void CreatePacket()
        {
            std::cout << "new" << std::endl;

            auto newPacket = Singleton< ObjectPool<Packet> >::getInstance().createObject();

            packets_.push_back(std::move(newPacket));
        }

        int32 onAppendData(size_t size, std::vector<byte>&& bytes)
        {
            if (nowPacket_ == 0)
            {
                CreatePacket();
            }

            while (true)
            {
                size_t wSize = packets_[nowPacket_]->writeableSize();

                if (wSize < size)
                {
                    packets_[nowPacket_]->appendBytes(bytes);
                    bytes = std::vector<byte>(std::begin(bytes) + wSize, std::end(bytes));

                    CreatePacket();
                    nowPacket_++;
                }
                else
                {
                    packets_[nowPacket_]->appendBytes(bytes);
                    break;
                }
            }

            return 0;
        }


        template <typename T> std::vector<byte> toBytes(const T& object)
        {
            std::vector<byte> bytes(sizeof(T));

            const byte* begin = reinterpret_cast<const byte*>(std::addressof(object));
            const byte* end = begin + sizeof(T);
            std::copy(begin, end, std::begin(bytes));

            return bytes;
        }

        template <typename T> T& fromBytes(const std::vector<byte>& bytes, T& object)
        {
            static_assert(std::is_trivially_copyable<T>::value, "not a TriviallyCopyable type");

            byte* beginObj = reinterpret_cast<byte*>(std::addressof(object));
            std::copy(std::begin(bytes), std::end(bytes), beginObj);

            return object;
        }

    private:
        int32 nowPacket_ = 0;
        Packets packets_;

        int32 currentSendPos_ = 0;

        Channel* currentSendChannel_ = nullptr;
    };

}


#endif //SOLO_BUNDLE_H
