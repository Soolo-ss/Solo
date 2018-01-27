cmake_minimum_required(VERSION 3.5)
project(Solo)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(Components)
add_subdirectory(Common)

message(${CMAKE_CURRENT_SOURCE_DIR}/libNetworkLib.a)

link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/cmake-build-debug/Components/Network/libNetworkLib.a)

if (WIN32)
    link_libraries(ws2_32.lib)
endif()

add_executable(Solo main.cpp)
