set(SOURCES)
add_subdirectory(src/can)
add_subdirectory(src/node)
add_subdirectory(src/opcode)

add_library(vlcb_common ${CMAKE_CURRENT_SOURCE_DIR})
target_sources(vlcb_common PRIVATE ${SOURCES})
unset(SOURCES)

# Install library and header
install(TARGETS vlcb_common
        EXPORT VLCBTargets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(DIRECTORY inc/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})