file(GLOB MATRIX_SOURCES CONFIGURE_DEPENDS *.cpp)

message(STATUS "Sources: ${MATRIX_SOURCES}")

add_library(Matrix ${MATRIX_SOURCES})

target_include_directories(Matrix PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_compile_features(Matrix PUBLIC cxx_std_17)