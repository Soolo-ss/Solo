cmake_minimum_required(VERSION 3.8)

message("Create Network Lib")

set(ImportFiles Bundle.cpp Bundle.h Packet.cpp Packet.h)

add_library(NetworkLib STATIC ${ImportFiles})