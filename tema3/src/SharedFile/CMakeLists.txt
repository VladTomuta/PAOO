add_library(SharedFile STATIC SharedFile.cpp)

target_include_directories(SharedFile PUBLIC "${PROJECT_SOURCE_DIR}/Semaphore")
target_include_directories(SharedFile PUBLIC "${PROJECT_SOURCE_DIR}/Message")
target_include_directories(SharedFile PUBLIC "${PROJECT_SOURCE_DIR}/Mutex")