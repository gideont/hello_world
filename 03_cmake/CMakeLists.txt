# Example from: http://derekmolloy.ie/hello-world-introductions-to-cmake/

cmake_minimum_required(VERSION 2.8.9)
project(hello_world)
set(CMAKE_BUILD_TYPE Release)

#Bring the headers, such as Student.h into the project
include_directories(include)

#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.c")

#Generate the shared library from the sources
add_library(foo SHARED ${SOURCES})
install(TARGETS foo DESTINATION /home/gideon/Development/hello/hello_03_cmake/build/lib)

#For the shared library:
set ( PROJECT_LINK_LIBS libfoo.so )
link_directories( ~/Development/hello/hello_03_cmake/build/ )

add_executable(hello_world ${SOURCES})
target_link_libraries(hello_world ${PROJECT_LINK_LIBS} )
