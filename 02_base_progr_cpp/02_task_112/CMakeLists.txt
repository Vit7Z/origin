cmake_minimum_required(VERSION 3.22.0)

project(02_task_112)

add_library (02_task_112_dll STATIC 02_task_112_dll.h 02_task_112_dll.cpp)

add_executable(02_task_112 02_task_112.cpp)

target_link_libraries(02_task_112 02_task_112_dll)