//
// Created by pc4 on 2018/1/19.
//

#ifndef SOLO_DATETIME_H
#define SOLO_DATETIME_H

#include <chrono>

namespace solo
{
    class Datetime
    {
    public:

        double now()
        {
            std::time_t st = std::time(nullptr);

            auto millies = static_cast<std::chrono::milliseconds>(st).count();

            return static_cast<uint64_t>(millies);
        }

    };

}

#endif //SOLO_DATETIME_H
