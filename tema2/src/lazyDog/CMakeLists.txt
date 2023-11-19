add_library(lazyDog STATIC lazyDog.cc)

target_include_directories(lazyDog PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(lazyDog PUBLIC "${PROJECT_SOURCE_DIR}/dog")
target_include_directories(lazyDog PUBLIC "${PROJECT_SOURCE_DIR}/animal")

target_link_libraries(lazyDog PUBLIC dog)