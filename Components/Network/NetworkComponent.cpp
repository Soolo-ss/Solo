//
// Created by pc4 on 2018/1/24.
//

#include "NetworkComponent.h"
#include "SelectPoller.h"

namespace solo
{
    NetworkComponent::NetworkComponent(ComponentManager* manager)
        : Component(manager),
          poller_(nullptr)
    {

    }

    bool NetworkComponent::install()
    {
        return true;
    }

    bool NetworkComponent::uninstall()
    {
        return true;
    }

    bool NetworkComponent::init(int port)
    {
        listener_.init(port);

#if SOLO_PLATFORM == SOLO_PLATFORM_WIN
        poller_ = new SelectPoller();
#else

#endif

        return true;
    }

    void NetworkComponent::start()
    {
        poller_->poll();

        listener_.start(poller_);
    }

}