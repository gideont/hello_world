cmake_minimum_required (VERSION 3.1)

project (cpp_tutorial)
set (CMAKE_CXX_STANDARD 11)

find_package(Boost REQUIRED date_time system thread)
include_directories(${BOOST_INCLUDE_DIRS})
message("boost lib: ${Boost_LIBRARIES}")
message("boost inc:${Boost_INCLUDE_DIR}")


add_executable(example example.cpp)
target_link_libraries(example
        ${Boost_LIBRARIES}
        )

