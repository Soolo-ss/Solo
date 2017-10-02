//
// Created by 盛晟 on 2017/10/2.
//

#ifndef SOLO_PLATFORM_H
#define SOLO_PLATFORM_H

#define SOLO_PLATFORM_WIN   0
#define SOLO_PLATFORM_OSX   1
#define SOLO_PLATFORM_UNIX  2
#define SOLO_PLATFORM_LINUX 3

#ifdef _WIN32
#define SOLO_PLATFORM SOLO_PLATFORM_WIN

#elif __APPLE__
#define SOLO_PLATFORM SOLO_PLATFORM_OSX

#elif __linux__
#define SOLO_PLATFORM SOLO_PLATFORM_LINUX

#elif __unix__
#define SOLO_PLATFORM SOLO_PLATFORM_UNIX

#else
#   error "Unknown platform"

#endif


#endif //SOLO_PLATFORM_H
