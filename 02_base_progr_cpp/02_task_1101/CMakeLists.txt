cmake_minimum_required(VERSION 3.22.0)

project(02_task_111)

add_library (02_task_111_static_lib STATIC 02_task_111_static_lib.h 02_task_111_static_lib.cpp)

add_executable(02_task_111 02_task_111.cpp)

target_link_libraries(02_task_111 02_task_111_static_lib)