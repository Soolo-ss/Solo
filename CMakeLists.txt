cmake_minimum_required(VERSION 3.8)
project(Solo)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(Network)
add_subdirectory(Common)

add_executable(Solo main.cpp)