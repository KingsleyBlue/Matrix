cmake_minimum_required(VERSION 3.15)
project(Matrix
    VERSION 1.0
    DESCRIPTION "Matrix math library"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_EXAMPLES "Build examples" ON)

add_subdirectory(src)

if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

install(DIRECTORY include/
    DESTINATION include)
