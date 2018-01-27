//
// Created by pc4 on 2018/1/24.
//

#include "SelectPoller.h"

#include <iostream>

namespace solo
{
    SelectPoller::SelectPoller()
        : readSet_(),
          writeSet_()
    {
        FD_ZERO(&readSet_);
        FD_ZERO(&writeSet_);
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
        time.tv_usec = (int)(0.05 * 1000000.0);

        int readyCount = 0;

        int maxFdSize = std::max(readSet.fd_count, writeSet.fd_count);

#if SOLO_PLATFORM == SOLO_PLATFORM_WIN
        if (maxFdSize == 0)
            Sleep((int)0.05 * 1000.0);
#endif

        readyCount = select(maxFdSize + 1, &readSet, &writeSet, NULL, &time);

        if (readyCount > 0)
        {
            std::cout << readyCount << std::endl;
            processEvents(readSet, writeSet);
        }
    }

    bool SelectPoller::processEvents(fd_set& readSet, fd_set& writeSet)
    {
#if SOLO_PLATFORM == SOLO_PLATFORM_WIN
        for(const int32& fd : readSet.fd_array)
#elif SOLO_PLATFORM == SOLO_PLATFORM_OSX
        for(const int32& fd : readSet.fds_bits)
#endif
        {
            EventMap::iterator iter = fdReadEvents_.find(fd);

            if (iter == std::end(fdReadEvents_))
            {
                continue;
            }
            else
            {
                EventCallback readCallback = fdReadEvents_[fd];
                readCallback(fd);
            }
        }

#if SOLO_PLATFORM == SOLO_PLATFORM_WIN
        for(const int32& fd : writeSet.fd_array)
#elif SOLO_PLATFORM == SOLO_PLATFORM_OSX
        for(const int32& fd : writeSet.fds_bits)
#endif
        {
            EventMap::iterator iter = fdWriteEvents_.find(fd);

            if (iter == std::end(fdWriteEvents_))
            {
                continue;
            }
            else
            {
                EventCallback writeCallback = fdWriteEvents_[fd];
                writeCallback(fd);
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