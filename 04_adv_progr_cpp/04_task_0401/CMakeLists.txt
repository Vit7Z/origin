cmake_minimum_required(VERSION 3.29)

set(SOURCES
  04_task_0401.cpp
  04_task_0401.h)

project(04_task_0401)

#ищем библиотеку для подключения Catch2 из vcpkg: 
find_package(Catch2 CONFIG REQUIRED)

#добавляем запускаемый файл с именем проекта
add_executable(04_task_0401 ${SOURCES})

#линкуем библиотеки Catch2 
target_link_libraries(04_task_0401 PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)