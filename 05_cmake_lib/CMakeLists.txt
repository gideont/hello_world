cmake_minimum_required(VERSION 2.8)

project(libhello_project)

add_library(
	mylib SHARED
	mylib.hpp
	mylib.cpp
	)

add_executable(hello hello.cpp)

target_link_libraries(hello PRIVATE mylib)

#install(TARGETS test DESTINATION lib)
#install(FILES test.h DESTINATION include)
