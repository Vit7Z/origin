cmake_minimum_required(VERSION 3.29)

set(PostgreSQL_ADDITIONAL_VERSIONS "17")

add_subdirectory("c:\\dev\\libpqxx-7.9.2\\" pqxx-build)

set(SOURCES
  05_task_0501.cpp
  0501_client_manager.cpp
  0501_client_manager.h
)

add_executable(05_task_0501 ${SOURCES})

target_compile_features(05_task_0501 PRIVATE cxx_std_17)

target_link_libraries(05_task_0501 pqxx)