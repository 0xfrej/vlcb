cmake_minimum_required(VERSION 3.29)
project(vlcb LANGUAGES C VERSION 1.0.0)

set(CMAKE_C_STANDARD 99)

include_directories(${CMAKE_SOURCE_DIR}/lib)

file(GLOB_RECURSE SOURCES "lib/src/*.c")
file(GLOB_RECURSE SHARED_SOURCES "shared/*.c")

add_library(${PROJECT_NAME} STATIC lib/vlcb.h ${SOURCES} ${SHARED_SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR}
        LINKER_LANGUAGE C
        PUBLIC_HEADER lib/vlcb.h
)

add_subdirectory(example)