#include <iostream>

#include "Common/ObjectPool.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    solo::ObjectPool<int> pools;

    std::unique_ptr<int> obj = pools.createObject();

    std::cout << *obj << std::endl;

    return 0;
}