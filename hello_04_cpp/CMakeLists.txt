# Example from: http://derekmolloy.ie/hello-world-introductions-to-cmake/

cmake_minimum_required(VERSION 2.8.9)
project(hello_world)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 11)

#include the headers such as foo.h
include_directories(include)

#Can manually add the sources using the set command as follows:
#set(SOURCES src/main.cpp src/foo.cpp)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

add_executable(hello_world ${SOURCES})
