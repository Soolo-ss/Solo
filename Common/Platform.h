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
#error "Unknown platform"

#endif

#if SOLO_PLATFORM == SOLO_PLATFORM_WIN

#include <stdio.h>

using int64 = signed __int64;
using int32 = signed __int32;
using int16 = signed __int16;
using int8 = signed __int8;

using uint64 = unsigned __int64;
using uint32 = unsigned __int32;
using uint16 = unsigned __int16;
using uint8 = unsigned __int8;

using byte = unsigned char;

#else

#include <stdint.h>

using int64 = int64_t;
using int32 = int32_t;
using int16 = int16_t;
using int8 = int8_t;
using uint64 = uint64_t;
using uint32 = uint32_t;
using uint16 = uint16_t;
using uint8 = uint8_t;

using byte = uint8;

#endif


#endif //SOLO_PLATFORM_H
