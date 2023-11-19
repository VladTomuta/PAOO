add_library(cat STATIC cat.cc)

target_include_directories(cat PUBLIC "${PROJECT_SOURCE_DIR}/animal")