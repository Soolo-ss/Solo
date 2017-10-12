//
// Created by pc4 on 2017/9/29.
//

#include "Endpoint.h"

namespace net {

    Endpoint::Endpoint(std::string address, int port, int type)
        : address_(address), port_(port), type_(type)
    {

    }

    void Endpoint::init(){
        socket_.socket();

        if (type_ == ENDPOINT_TYPE::ENDPOINT_TYPE_SERVER) {
            if (socket_.bind(address_, port_) == -1) {
                std::cout << "Endpoint bind error" << std::endl;
            }

            if (socket_.listen() == -1) {
                std::cout << "Endpoint listen error" << std::endl;
            }
        }
        else {
            if (socket_.connect(address_, port_) == -1) {
                std::cout << "Endpoint connect error" << std::endl;
            }
        }
    }


}