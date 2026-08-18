cmake_minimum_required(VERSION 3.15)

project(Matrix
    VERSION 1.0
    DESCRIPTION "Matrix math library"
    LANGUAGES CXX
)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(src)


# =========================
# 安装头文件
# =========================

install(
    DIRECTORY include/
    DESTINATION include
)


# =========================
# 安装库
# =========================

install(
    TARGETS Matrix
    EXPORT MatrixTargets

    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)


# =========================
# 导出target
# =========================

install(
    EXPORT MatrixTargets
    FILE MatrixTargets.cmake
    NAMESPACE Matrix::
    DESTINATION lib/cmake/Matrix
)


# =========================
# 生成MatrixConfig.cmake
# =========================

include(CMakePackageConfigHelpers)


configure_package_config_file(
    cmake/MatrixConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/MatrixConfig.cmake

    INSTALL_DESTINATION
    lib/cmake/Matrix
)


write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/MatrixConfigVersion.cmake

    VERSION ${PROJECT_VERSION}

    COMPATIBILITY SameMajorVersion
)


install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/MatrixConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/MatrixConfigVersion.cmake

    DESTINATION
        lib/cmake/Matrix
)