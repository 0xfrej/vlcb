set(SOURCES)

add_subdirectory(src/adapter)
add_subdirectory(src/iface)
add_subdirectory(src/packet)
add_subdirectory(src/socket)
add_subdirectory(src/storage)

add_library(vlcb_net ${CMAKE_CURRENT_SOURCE_DIR})
target_sources(vlcb_net PRIVATE ${SOURCES})
target_link_libraries(vlcb_net PUBLIC vlcb_common vlcb_platform)
unset(SOURCES)

# Install library and header
install(TARGETS vlcb_net
        EXPORT VLCBTargets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(DIRECTORY inc/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})