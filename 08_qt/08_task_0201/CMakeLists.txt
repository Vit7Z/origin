cmake_minimum_required(VERSION 3.27)

project(08_task_0201 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS
  Core
  Network
  Sql
)

add_executable(08_task_0201
  main.cpp
)

target_link_libraries(08_task_0201 PRIVATE
  Qt6::Core
  Qt6::Network
  Qt6::Sql
)


include(GNUInstallDirs)
install(TARGETS 08_task_0201
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
