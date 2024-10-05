cmake_minimum_required(VERSION 3.29)
project(vlcb LANGUAGES C VERSION 1.0.0)

set(CMAKE_C_STANDARD 99)

if(TARGET_GROUP STREQUAL production)
    add_subdirectory(lib)
elseif(TARGET_GROUP STREQUAL test)
    include(CTest)

    add_subdirectory(lib)
    add_subdirectory(vendor)
    add_subdirectory(test)
elseif(TARGET GROUP STREQUAL example)
    add_subdirectory(lib)
    add_subdirectory(example)
else()
    include(CTest)

    add_subdirectory(lib)
    add_subdirectory(vendor)
    add_subdirectory(test)
    add_subdirectory(example)
endif()