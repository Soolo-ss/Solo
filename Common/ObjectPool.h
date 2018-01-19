//
// Created by pc4 on 2018/1/17.
//

#ifndef SOLO_OBJECTPOOL_H
#define SOLO_OBJECTPOOL_H

#include <list>
#include <memory>

const int OBJECT_POOL_INIT_OBJ_SIZE = 16;
const int OBJECT_POOL_MAX_OBJ_SIZE = 1024;

namespace solo {
    template <typename T>
    class ObjectPool
    {
    public:
        using ObjectList = std::list< std::unique_ptr<T> >;

        ObjectPool()
        {
            assignObjs();
        }

        //对象池中的对象数量
        size_t size() const { objs_.size(); }

        //返回一个对象，如果对象池为空，那么创建一个新的对象
        std::unique_ptr<T> createObject()
        {
            while (true)
            {
                if (objs_.size() > 0)
                {
                    std::unique_ptr<T> t = std::move(*objs_.begin());

                    objs_.pop_front();

                    return t;
                }
                else
                {
                    assignObjs();
                }
            }

        }

        //回收一个对象
        void reclaimObject(std::unique_ptr<T> t)
        {
            if (objs_.size() > OBJECT_POOL_MAX_OBJ_SIZE)
            {
                return;
            }
            else
            {
                objs_.push_back(std::move(t));
            }
        }

    private:
        void assignObjs(size_t  objSize = OBJECT_POOL_INIT_OBJ_SIZE)
        {
            for (int i = 0; i < objSize; ++i)
            {
                objs_.push_back(std::unique_ptr<T>(new T()));
            }
        }


    private:
        ObjectList objs_;
    };
}


#endif //SOLO_OBJECTPOOL_H
