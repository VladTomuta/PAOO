cmake_minimum_required(VERSION 3.10)

project(main VERSION 1.0)

add_executable(Main main.cc)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(cat)

target_link_libraries(Main PUBLIC cat)

target_include_directories(Main PUBLIC "${PROJECT_SOURCE_DIR}/cat")
