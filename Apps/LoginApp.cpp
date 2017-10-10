//
// Created by pc4 on 2017/10/10.
//

#include "LoginApp.h"

LoginApp::LoginApp(int port)
    : port_(port),
      ep("127.0.0.1", port_, net::ENDPOINT_TYPE::ENDPOINT_TYPE_SERVER)
{
    
}
