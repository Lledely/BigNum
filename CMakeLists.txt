cmake_minimum_required(VERSION 3.20)
project(big_numbers)

set(CMAKE_CXX_STANDARD 17)

file (GLOB_RECURSE SOURCES "src/*.cpp")
add_library(big_num SHARED ${SOURCES})

target_include_directories(big_num PUBLIC headers)

add_executable(Main main.cpp)
target_link_libraries(Main PRIVATE big_num)
