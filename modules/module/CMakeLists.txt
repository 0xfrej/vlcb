set(
        SOURCES
        src/module.c
        src/state_machine.c
)

add_library(vlcb_module ${CMAKE_CURRENT_SOURCE_DIR})
target_sources(vlcb_module PRIVATE ${SOURCES})
target_link_libraries(vlcb_module PUBLIC vlcb_common vlcb_platform vlcb_net)
unset(SOURCES)

# Install library and header
install(TARGETS vlcb_module
        EXPORT VLCBTargets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(DIRECTORY inc/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})