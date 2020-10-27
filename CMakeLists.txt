cmake_minimum_required(VERSION 3.17)
project(stack_and_queue_template)

set(CMAKE_CXX_STANDARD 14)

add_executable(stack_and_queue_template main.cpp Queue.cpp Stack.cpp TestRunner.cpp LinkedListException.h Queue.cpp Queue.h Stack.cpp Stack.h TestRunner.cpp cmake-build-debug/TestRunner.h TestRunner.h LinkedList.cpp LinkedList.h LinkedListItem.cpp LinkedListItem.h)