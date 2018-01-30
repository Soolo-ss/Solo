#include <iostream>
#include <memory>

#include "Components/Network/NetworkComponent.h"
#include "Components/ComponentManager.h"

int main() {
    /*
    std::shared_ptr<ComponentManager> manager = std::make_shared<ComponentManager>();

    NetworkComponent netComp(manager.get());


    netComp.init(20015);

    while (true)
        netComp.processNetwork();
    */

    ObjectPool<int>::getInstance().createObject();


    {
        std::cout << ObjectPool<int>::getInstance().size() << std::endl;

        ObjectPool<int>::getInstance().createObject();

        std::cout << ObjectPool<int>::getInstance().size() << std::endl;
    }

    std::cout << ObjectPool<int>::getInstance().size() << std::endl;


    return 0;
}