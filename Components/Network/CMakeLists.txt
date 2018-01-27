cmake_minimum_required(VERSION 3.5)

message("Create Network Lib")

set(ImportFiles Bundle.cpp Bundle.h Packet.cpp Packet.h Poller.h Endpoint.h Endpoint.cpp Endpoint.h SelectPoller.cpp SelectPoller.h Listener.cpp Listener.h NetworkComponent.cpp NetworkComponent.h Poller.cpp Channel.cpp Channel.h)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(NetworkLib STATIC ${ImportFiles})