//
// Created by pc4 on 2018/1/17.
//

#ifndef SOLO_OBJECTPOOL_H
#define SOLO_OBJECTPOOL_H

#include <list>
#include <memory>
#include <assert.h>

const int OBJECT_POOL_INIT_OBJ_SIZE = 16;
const int OBJECT_POOL_MAX_OBJ_SIZE = 1024;

namespace solo {

    template <typename T>
    struct pool_deleter;

    class PoolObject;

    template <typename T, typename D = pool_deleter<T> >
    class ObjectPool
    {
    public:
        using ObjectPtr = std::unique_ptr<T, D>;

        using ObjectList = std::list<ObjectPtr>;

        ObjectPool()
            : objs_()
        {
            assignObjs();
        }

        //对象池中的对象数量
        size_t size() const { objs_.size(); }

        //返回一个对象，如果对象池为空，那么创建一个新的对象
        ObjectPtr createObject()
        {
            static_assert(std::is_base_of<PoolObject, T>::value, "not derived from PoolObject");

            while (true)
            {
                if (objs_.size() > 0)
                {
                    ObjectPtr t = std::move(*objs_.begin());

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
        void reclaimObject(ObjectPtr t)
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
                objs_.push_back(ObjectPtr(new T()));
            }
        }

    private:
        ObjectList objs_;
    };

    class PoolObject
    {
    public:
        PoolObject() { }

        virtual ~PoolObject() { }

        virtual void clear() = 0;
    };

    template<typename T>
    struct pool_deleter
    {
        void operator()(T* tp)
        {
            static_assert(!std::is_void<T>::value, "can't delete incomplete type");

            Singleton< ObjectPool<T> >::getInstance().reclaimObject(std::unique_ptr<T, pool_deleter<T> >(tp));
        }
    };
}


#endif //SOLO_OBJECTPOOL_H
