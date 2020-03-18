cmake_minimum_required(VERSION 3.14)
project(memory_leaks_r_us)

set(CMAKE_CXX_STANDARD 14)

add_executable(memory_leaks_r_us main.cpp test1.cpp test2.cpp test3.cpp)