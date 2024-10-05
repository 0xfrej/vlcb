

file(GLOB_RECURSE SOURCES "src/*.c")
file(GLOB_RECURSE SHARED_SOURCES "../shared/*.c")

add_library(vlcb STATIC vlcb.h ${SOURCES} ${SHARED_SOURCES})
target_include_directories(vlcb PUBLIC ${CMAKE_CURRENT_LIST_DIR})
set_target_properties(vlcb PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR}
        LINKER_LANGUAGE C
        PUBLIC_HEADER vlcb.h
)