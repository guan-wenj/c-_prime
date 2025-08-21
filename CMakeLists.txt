cmake_minimum_required(VERSION 4.0)
project(c__prime)

set(CMAKE_CXX_STANDARD 23)

add_executable(c__prime main.cpp
        linked_stack.h
        library.h
        library.cpp
        linked_queue.h
)
