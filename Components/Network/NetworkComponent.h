//
// Created by pc4 on 2018/1/24.
//

#ifndef SOLO_NETWORKCOMPONENT_H
#define SOLO_NETWORKCOMPONENT_H

#include "../Component.h"
#include "Listener.h"

namespace solo
{
    class NetworkComponent : public Component
    {
    public:
        NetworkComponent(ComponentManager* manager);

        bool install() override;

        bool uninstall() override;

        bool init(int port);

        void start();

    private:
        Listener listener_;
        Poller* poller_;
    };
}

#endif //SOLO_NETWORKCOMPONENT_H
