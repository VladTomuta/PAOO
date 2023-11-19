cmake_minimum_required(VERSION 3.10)

project(main VERSION 1.0)

add_executable(Main main.cc)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-elide-constructors")

add_subdirectory(animal)
add_subdirectory(cat)
add_subdirectory(affectionateCat)
add_subdirectory(scaredCat)
add_subdirectory(dog)
add_subdirectory(lazyDog)
add_subdirectory(playfulDog)

target_link_libraries(Main PUBLIC animal)
target_link_libraries(Main PUBLIC cat)
target_link_libraries(Main PUBLIC affectionateCat)
target_link_libraries(Main PUBLIC scaredCat)
target_link_libraries(Main PUBLIC dog)
target_link_libraries(Main PUBLIC lazyDog)
target_link_libraries(Main PUBLIC playfulDog)

target_include_directories(Main PUBLIC "${PROJECT_SOURCE_DIR}/animal")
target_include_directories(Main PUBLIC "${PROJECT_SOURCE_DIR}/cat")
target_include_directories(Main PUBLIC "${PROJECT_SOURCE_DIR}/affectionateCat")
target_include_directories(Main PUBLIC "${PROJECT_SOURCE_DIR}/scaredCat")
target_include_directories(Main PUBLIC "${PROJECT_SOURCE_DIR}/dog")
target_include_directories(Main PUBLIC "${PROJECT_SOURCE_DIR}/lazyDog")
target_include_directories(Main PUBLIC "${PROJECT_SOURCE_DIR}/playfulDog")