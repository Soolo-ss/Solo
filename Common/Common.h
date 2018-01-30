//
// Created by 盛晟 on 2017/10/2.
//

#ifndef SOLO_COMMON_H
#define SOLO_COMMON_H


#include "Platform.h"

#include <array>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>

#include <iostream>

#include "Singleton.h"
#include "Datetime.h"
#include "ObjectPool.h"
#include "unique_ptr.h"

#define datetimeMgr solo::Singleton<solo::Datetime>::getInstance()

template <typename T>
using ObjectPool = solo::Singleton< solo::ObjectPool<T> >;


#endif //SOLO_COMMON_H
