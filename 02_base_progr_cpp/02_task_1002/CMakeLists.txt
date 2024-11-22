cmake_minimum_required(VERSION 3.22.0)

set(SOURCES 
02_task_102.cpp
equilateral_triangle.cpp 
figure.cpp 
isosceles_triangle.cpp
parallelogram.cpp
print_info.cpp
quadrilateral.cpp
rectangle_t.cpp
rhomb.cpp
right_angled_triangle.cpp
scalene_triangle.cpp
square.cpp
equilateral_triangle.h
figure.h
isosceles_triangle.h
parallelogram.h
print_info.h
quadrilateral.h
rectangle_t.h
rhomb.h
right_angled_triangle.h
scalene_triangle.h
square.h)

project(02_task_102)

add_executable(02_task_102 ${SOURCES})