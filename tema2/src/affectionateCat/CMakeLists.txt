add_library(affectionateCat STATIC affectionateCat.cc)

target_include_directories(affectionateCat PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(affectionateCat PUBLIC "${PROJECT_SOURCE_DIR}/cat")
target_include_directories(affectionateCat PUBLIC "${PROJECT_SOURCE_DIR}/animal")

target_link_libraries(affectionateCat PUBLIC cat)