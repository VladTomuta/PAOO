cmake_minimum_required(VERSION 3.10)

project(main VERSION 1.0)

add_executable(Main main.cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(Semaphore)
add_subdirectory(SharedFile)

target_link_libraries(Main PUBLIC Semaphore)
target_link_libraries(Main PUBLIC SharedFile)

target_include_directories(Main PUBLIC "${PROJECT_SOURCE_DIR}/Semaphore")
target_include_directories(Main PUBLIC "${PROJECT_SOURCE_DIR}/SharedFile")