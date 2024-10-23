cmake_minimum_required(VERSION 3.24)
project(
        vlcb
        VERSION 0.1.0
        DESCRIPTION "VLCB bus SDK"
        LANGUAGES C
)
# TODO: make useable on other platforms as well
#   https://github.com/doctest/doctest/blob/master/CMakeLists.txt
include(GNUInstallDirs)

set_property(GLOBAL PROPERTY C_STANDARD 99)

## do not enable testing when this project is used as external project
#if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
#endif()

add_subdirectory(modules)

# Enable support if testing is enabled
if(VLCB_TESTING_IS_ENABLED)
    include(CTest)
    add_subdirectory(test)
endif()

# Install CMake configurations for external usage
# Create and install the vlcbConfig.cmake file
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/vlcbConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMinorVersion
)

configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/vlcbConfig.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/vlcbConfig.cmake"
        @ONLY
)

install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/vlcbConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/vlcbConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vlcb
)
install(EXPORT VLCBTargets
        NAMESPACE vlcb::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vlcb
)

export(EXPORT VLCBTargets
        NAMESPACE vlcb::
        FILE "${CMAKE_CURRENT_BINARY_DIR}/vlcbTargets.cmake"
)
