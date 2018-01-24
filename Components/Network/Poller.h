//
// Created by pc4 on 2018/1/23.
//

#ifndef SOLO_POLLER_H
#define SOLO_POLLER_H

#include <functional>
#include <unordered_map>

namespace solo
{
    class Poller
    {
    public:
        using EventCallback = std::function<void(int)>;
        using EventMap = std::unordered_map<int, EventCallback >;

        virtual void poll() = 0;

        virtual bool registeReadEvent(int fd, EventCallback readCallback);
        virtual bool registeWriteEvent(int fd, EventCallback writeCallback);

        virtual bool unregisteReadEvent(int fd);
        virtual bool unregisteWriteEvent(int fd);

    protected:
        EventMap fdReadEvents_;
        EventMap fdWriteEvents_;
    };
}




#endif //SOLO_POLLER_H
