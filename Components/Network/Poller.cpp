//
// Created by pc4 on 2018/1/25.
//

#include "Poller.h"

namespace solo
{
    Poller::Poller()
        : fdReadEvents_(),
          fdWriteEvents_(),
          isRun_(false)
    {

    }

    bool Poller::registeReadEvent(int fd, EventCallback readCallback)
    {
        if (fdReadEvents_.find(fd) == std::end(fdReadEvents_))
            fdReadEvents_[fd] = readCallback;
    }

    bool Poller::registeWriteEvent(int fd, EventCallback writeCallback)
    {
        if (fdWriteEvents_.find(fd) == std::end(fdWriteEvents_))
            fdWriteEvents_[fd] = writeCallback;
    }

    bool Poller::unregisteReadEvent(int fd) {
        if (fdReadEvents_.find(fd) != std::end(fdReadEvents_))
            fdReadEvents_.erase(fd);
    }

    bool Poller::unregisteWriteEvent(int fd) {
        if (fdWriteEvents_.find(fd) != std::end(fdWriteEvents_))
            fdWriteEvents_.erase(fd);
    }

    void Poller::pollUntilBreak()
    {
        while (isRun_)
        {
            poll();
        }
    }

    void Poller::setRun(bool isRun)
    {
        isRun_ = isRun;
    }
}