file(GLOB MATRIX_SOURCES CONFIGURE_DEPENDS *.cpp)

add_library(Matrix ${MATRIX_SOURCES})


target_include_directories(Matrix
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)


target_compile_features(Matrix PUBLIC cxx_std_17)