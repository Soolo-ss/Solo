//
// Created by pc4 on 2018/1/24.
//

#include "SelectPoller.h"

namespace solo
{
    SelectPoller::SelectPoller()
        : readSet_(),
          writeSet_()
    {
        FD_ZERO(&readSet_);
        FD_ZERO(&writeSet_);
    }

    SelectPoller::~SelectPoller()
    {

    }

    void SelectPoller::poll()
    {
        fd_set readSet;
        fd_set writeSet;

        FD_ZERO(&readSet);
        FD_ZERO(&writeSet);

        readSet = readSet_;
        writeSet = writeSet_;

        timeval time;
        time.tv_sec = 0;
        time.tv_usec = 0;

        int readyCount = 0;

        readyCount = select(0, &readSet, &writeSet, NULL, &time);

        if (readyCount > 0)
        {
            processEvents(readSet, writeSet);
        }
    }

    bool SelectPoller::processEvents(fd_set& readSet, fd_set& writeSet)
    {
        for (int i = 0; i != readSet.fd_count; ++i)
        {
            int readFd = readSet.fd_array[i];

            EventMap::iterator iter = fdReadEvents_.find(readFd);

            if (iter == std::end(fdReadEvents_))
            {
                continue;
            }
            else
            {
                EventCallback readCallback = fdReadEvents_[readFd];
                readCallback(readFd);
            }
        }

        for (int i = 0; i != writeSet.fd_count; ++i)
        {
            int writeFd = writeSet.fd_array[i];

            EventMap::iterator iter = fdWriteEvents_.find(writeFd);

            if (iter == std::end(fdWriteEvents_))
            {
                continue;
            }
            else
            {
                EventCallback writeCallback = fdWriteEvents_[writeFd];
                writeCallback(writeFd);
            }
        }
    }

    bool SelectPoller::registeReadEvent(int fd, EventCallback readCallback)
    {
#if SOLO_PLATFORM == SOLO_PLATFORM_WIN
        if (readSet_.fd_count > FD_SETSIZE)
        {
            return false;
        }
#endif

        if (FD_ISSET(fd, &readSet_))
        {
            return false;
        }

        if (fdReadEvents_.find(fd) != fdReadEvents_.end())
        {
            return false;
        }

        FD_SET(fd, &readSet_);
        fdReadEvents_[fd] = readCallback;

        return true;
    }

    bool SelectPoller::registeWriteEvent(int fd, EventCallback writeCallback)
    {
#if SOLO_PLATFORM == SOLO_PLATFORM_WIN
        if (writeSet_.fd_count > FD_SETSIZE)
        {
            return false;
        }
#endif

        if (FD_ISSET(fd, &writeSet_))
        {
            return false;
        }

        if (fdWriteEvents_.find(fd) != fdWriteEvents_.end())
        {
            return false;
        }

        FD_SET(fd, &writeSet_);
        fdWriteEvents_[fd] = writeCallback;

        return true;
    }

    bool SelectPoller::unregisteReadEvent(int fd)
    {
        if (!FD_ISSET(fd, &readSet_))
            return false;

        if (fdReadEvents_.find(fd) == std::end(fdReadEvents_))
            return false;

        FD_CLR(fd, &readSet_);

        fdReadEvents_.erase(fd);

        return true;
    }

    bool SelectPoller::unregisteWriteEvent(int fd)
    {
        if (!FD_ISSET(fd, &writeSet_))
            return false;

        if (fdWriteEvents_.find(fd) == std::end(fdWriteEvents_))
            return false;

        FD_CLR(fd, &writeSet_);

        fdWriteEvents_.erase(fd);

        return true;
    }

}