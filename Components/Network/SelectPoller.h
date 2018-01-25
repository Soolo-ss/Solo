//
// Created by pc4 on 2018/1/24.
//

#ifndef SOLO_SELECTPOLLER_H
#define SOLO_SELECTPOLLER_H

#if SOLO_PLATFORM == SOLO_PLATFORM_WIN
#include <winsock2.h>
#else
#include <sys/select.h>
#endif

#include "Poller.h"

namespace solo
{
    class SelectPoller : public Poller
    {
    public:
        SelectPoller();

        ~SelectPoller() = default;

        bool registeReadEvent(int fd, EventCallback readCallback) override;
        bool registeWriteEvent(int fd, EventCallback writeCallback) override;

        bool unregisteReadEvent(int fd) override;
        bool unregisteWriteEvent(int fd) override;

        void poll() override;

    private:
        bool processEvents(fd_set& readSet, fd_set& writeSet);

    private:
        fd_set readSet_;
        fd_set writeSet_;
    };

}




#endif //SOLO_SELECTPOLLER_H
