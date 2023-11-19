add_library(scaredCat STATIC scaredCat.cc)

target_include_directories(scaredCat PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(scaredCat PUBLIC "${PROJECT_SOURCE_DIR}/cat")
target_include_directories(scaredCat PUBLIC "${PROJECT_SOURCE_DIR}/animal")

target_link_libraries(scaredCat PUBLIC cat)