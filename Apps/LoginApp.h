//
// Created by pc4 on 2017/10/10.
//

#ifndef SOLO_LOGINAPP_H
#define SOLO_LOGINAPP_H

#include "../Network/Endpoint.h"

class LoginApp {
public:
    LoginApp(int port);

private:
    int port_;

    net::Endpoint ep;

};


#endif //SOLO_LOGINAPP_H
