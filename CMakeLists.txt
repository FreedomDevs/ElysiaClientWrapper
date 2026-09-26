cmake_minimum_required(VERSION 3.21)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

project(ElysiaClientWrapper LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(ElysiaClientWrapper
    main.cpp
)

target_link_libraries(ElysiaClientWrapper PRIVATE
    Qt6::Widgets
)

get_target_property(QT_INCLUDE_DIR Qt6::Core INTERFACE_INCLUDE_DIRECTORIES)

target_include_directories(ElysiaClientWrapper PRIVATE
    ${QT_INCLUDE_DIR}
)
