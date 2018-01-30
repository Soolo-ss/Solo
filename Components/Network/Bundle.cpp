//
// Created by pc4 on 2018/1/17.
//

#include "Bundle.h"
#include "Channel.h"

#include <algorithm>

namespace solo
{
    bool Bundle::send(Channel* channel)
    {
        assert(currentSendPos_ <= packets_.size());

        if (!sendHead(channel))
            return false;

        for (int i = currentSendPos(); i != packets_.size(); ++i)
        {
            auto sp = *(this->packets_[i]);

            int sendSize = sp.readableSize();

            int realSize = channel->ep().send(sp);

            if (realSize != sendSize)
            {
                setSendPos(i);
                break;
            }
            else
            {
                setSendPos(i + 1);
            }
        }

        return currentSendPos_ == packets_.size();
    }

    bool Bundle::sendHead(Channel *channel)
    {
        int64 channelID = channel->channelID();
        int32 bundleSize = 0;

        std::for_each(packets_.begin() + currentSendPos_, packets_.end(), [&](PacketPtr& n){
            bundleSize += n->readableSize();
        });

        auto channelBytes = toBytes(channelID);
        auto bundleSizeBytes = toBytes(bundleSize);
        channelBytes.insert(channelBytes.end(), bundleSizeBytes.begin(), bundleSizeBytes.end());

        auto headPacket = Singleton< ObjectPool<Packet> >::getInstance().createObject();
        headPacket->appendBytes(channelBytes);

        int headSize = channel->ep().send(*headPacket);

        if (headSize != (sizeof(channelID) + sizeof(bundleSize)))
            return false;

        return true;
    }
}