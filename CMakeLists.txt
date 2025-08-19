cmake_minimum_required(VERSION 4.0)
project(c__prime)

set(CMAKE_CXX_STANDARD 23)

add_executable(c__prime main.cpp
        linked_queue.h
        linked_queue.cpp
        linked_stack.h
        linked_stack.cpp)
