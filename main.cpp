#include <iostream>
#include <memory>

#include "Components/Network/NetworkComponent.h"
#include "Components/ComponentManager.h"

using namespace solo;

int main() {

    std::shared_ptr<ComponentManager> manager = std::make_shared<ComponentManager>();

    NetworkComponent netComp(manager.get());


    netComp.init(20015);

    while (true)
        netComp.processNetwork();


    /*
    {
        int beforesize = ObjectPool<solo::Bundle>::getInstance().size();

        solo::unique_ptr <solo::Bundle> obj = ObjectPool<solo::Bundle>::getInstance().createObject();

        int afterSize = ObjectPool<solo::Bundle>::getInstance().size();

        std::cout << "before size " << beforesize << std::endl;
        std::cout << "after size" << afterSize << std::endl;
    }

    int finalySize = ObjectPool<solo::Bundle>::getInstance().size();

     */


    return 0;
}