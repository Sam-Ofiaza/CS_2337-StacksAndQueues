cmake_minimum_required(VERSION 3.17)
project(stack_and_queue_template)

set(CMAKE_CXX_STANDARD 14)

add_executable(stack_and_queue_template main.cpp LinkedList.cpp LinkedListItem.cpp Queue.cpp Stack.cpp TestRunner.cpp)