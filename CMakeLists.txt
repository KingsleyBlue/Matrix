cmake_minimum_required(VERSION 3.10)
project(main)

file(GLOB SRC_FILES
    "${PROJECT_SOURCE_DIR}/src/*.hpp"
    "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES})

target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_17)
