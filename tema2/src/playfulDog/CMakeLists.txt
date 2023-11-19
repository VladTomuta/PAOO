add_library(playfulDog STATIC playfulDog.cc)

target_include_directories(playfulDog PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(playfulDog PUBLIC "${PROJECT_SOURCE_DIR}/dog")
target_include_directories(playfulDog PUBLIC "${PROJECT_SOURCE_DIR}/animal")

target_link_libraries(playfulDog PUBLIC dog)