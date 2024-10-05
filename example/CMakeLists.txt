# Find all example applications (each .c file in this directory is a separate app)
file(GLOB_RECURSE EXAMPLES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.c")

list(FILTER EXAMPLE_SOURCES EXCLUDE REGEX "adapter/")

foreach(EXAMPLE ${EXAMPLES})
    # Get the filename without the extension (e.g., app1, app2, etc.) and the dir
    get_filename_component(EXAMPLE_NAME ${EXAMPLE} NAME_WE)
    get_filename_component(EXAMPLE_DIR ${EXAMPLE} DIRECTORY)

    # Create a unique name for the executable using the full path without extension
    string(CONCAT EXAMPLE_NAME ${EXAMPLE_DIR} "/" ${EXAMPLE_NAME})
    string(REPLACE "/" "_" EXAMPLE_NAME ${EXAMPLE_NAME})

    add_executable(${EXAMPLE_NAME} ${EXAMPLE})
    target_link_libraries(${EXAMPLE_NAME} vlcb)
endforeach()
