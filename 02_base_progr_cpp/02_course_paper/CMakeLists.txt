cmake_minimum_required(VERSION 3.22.0)

project(02_course_paper)

add_library (02_racing simulator SHARE 02_task_111_static_lib.h 02_task_111_static_lib.cpp)

add_executable(02_course_paper 02_course_paper.cpp)

target_link_libraries(02_course_paper 02_task_111_static_lib)