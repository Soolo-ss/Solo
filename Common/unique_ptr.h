//
// Created by pc4 on 2018/1/30.
//

#ifndef SOLO_UNIQUE_PTR_H
#define SOLO_UNIQUE_PTR_H

#include <memory>
#include "ObjectPool.h"

namespace solo
{
    template <typename T, typename D = pool_deleter<T> >
    using unique_ptr = std::unique_ptr<T, D>;
}

#endif //SOLO_UNIQUE_PTR_H
