cmake_minimum_required(VERSION 3.8)

message("Create Network Lib")

set(ImportFiles Bundle.cpp Bundle.h Packet.cpp Packet.h Poller.cpp Poller.h Endpoint.h Endpoint.cpp Endpoint.h SelectPoller.cpp SelectPoller.h)

add_library(NetworkLib STATIC ${ImportFiles})