#include <iostream>
#include <memory>

#include "Components/Network/NetworkComponent.h"
#include "Components/ComponentManager.h"

using namespace solo;

int main() {
    std::shared_ptr<ComponentManager> manager = std::make_shared<ComponentManager>();

    NetworkComponent netComp(manager.get());


    netComp.init(20015);

    netComp.start();

    return 0;
}