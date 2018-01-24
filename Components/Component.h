//
// Created by pc4 on 2018/1/24.
//

#ifndef SOLO_COMPONENT_H
#define SOLO_COMPONENT_H

#include "ComponentManager.h"

namespace solo
{
    class Component
    {
    public:
        Component(ComponentManager* manager)
            : manager_(manager)
        {

        }

        virtual bool install() = 0;
        virtual bool uninstall() = 0;

    protected:
        ComponentManager* manager_;

    };
}




#endif //SOLO_COMPONENT_H
