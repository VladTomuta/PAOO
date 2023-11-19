add_library(dog STATIC dog.cc)

target_include_directories(dog PUBLIC "${PROJECT_SOURCE_DIR}/animal")