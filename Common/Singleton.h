//
// Created by pc4 on 2018/1/17.
//

#ifndef SOLO_SINGLETON_H
#define SOLO_SINGLETON_H

namespace solo {
    template <typename T>
    class Singleton
    {
    public:
        static T& getInstance()
        {
            static T instance;

            return instance;
        }

        Singleton(T const&) = delete;
        void operator=(T const &) = delete;
    };
}

#endif //SOLO_SINGLETON_H

