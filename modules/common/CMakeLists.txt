set(
        SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/can.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/node.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/opcode.c
)

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