# Find all test files (assuming .c extension)
file(GLOB TEST_SOURCES "*.c")

# Loop over each test source file
foreach(TEST_SOURCE ${TEST_SOURCES})

    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    add_executable(${TEST_NAME}_app ${TEST_SOURCE})

    target_link_libraries(${TEST_NAME}_app
            vlcb
            Unity
    )
    add_test(NAME ${TEST_NAME}_test COMMAND ${TEST_NAME}_app)

endforeach()