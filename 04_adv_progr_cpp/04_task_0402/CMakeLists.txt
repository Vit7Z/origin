cmake_minimum_required(VERSION 3.30) 

project(04_task_0402)

#ищем библиотеку для подключения Catch2 из vcpkg: 
find_package(Catch2 CONFIG REQUIRED)

#добавляем запускаемый файл с именем проекта
add_executable(04_task_0402 04_task_0402.cpp)

#линкуем библиотеки Catch2 
target_link_libraries(04_task_0402 PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)