cmake_minimum_required(VERSION 3.28.0)

project(04_task_0401)

find_package(Catch2 CONFIG REQUIRED)

add_executable(04_task_0401 04_task_0401.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)