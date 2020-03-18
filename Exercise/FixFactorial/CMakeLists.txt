# CSS Linux Lab only has cmake 3.5
cmake_minimum_required(VERSION 3.5)

project(factorial)

# Minimum c++14
set(CMAKE_CXX_STANDARD 14)

# have compiler give warnings, but not for signed/unsigned
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -Wno-sign-compare")

add_executable(factorial main.cpp factorialtest.cpp factorial.cpp)
