cmake_minimum_required(VERSION 3.8)
project(Solo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Network/Channel.cpp Network/Channel.h Network/Endpoint.cpp Network/Endpoint.h Network/NetworkStream.cpp Network/NetworkStream.h Network/Bundle.cpp Network/Bundle.h)
add_executable(Solo ${SOURCE_FILES})