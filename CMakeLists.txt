cmake_minimum_required(VERSION 3.20)
project(big_numbers)

set(CMAKE_CXX_STANDARD 17)

file (GLOB_RECURSE SOURCES "src/*.cpp")
add_library(big_num SHARED ${SOURCES})

target_include_directories(big_num PUBLIC headers)

add_executable(Main main.cpp)
target_link_libraries(Main PRIVATE big_num)

add_executable(Test_Math tests_math.cpp)
target_link_libraries(Test_Math PRIVATE big_num)

add_executable(Test_Logic tests_logic.cpp)
target_link_libraries(Test_Logic PRIVATE big_num)

add_executable(Test_Pi test_pi.cpp)
target_link_libraries(Test_Pi PRIVATE big_num)