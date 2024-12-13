set(VLCB_TIME_IMPL ${CMAKE_CURRENT_SOURCE_DIR}/src/arch/generic/time.c)
# if(CMAKE_SYSTEM_PROCESSOR STREQUAL "avr")
#   set(VLCB_TIME_IMPL ${CMAKE_CURRENT_SOURCE_DIR}/src/arch/avr/time.c)
# endif()

set(
        SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/log.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/driver/led.c
        ${VLCB_TIME_IMPL}
)

add_library(vlcb_platform ${CMAKE_CURRENT_LIST_DIR})
target_sources(vlcb_platform PRIVATE ${SOURCES})
target_link_libraries(vlcb_platform PUBLIC vlcb_common)
unset(SOURCES)

# Install library and header
install(TARGETS vlcb_platform
        EXPORT VLCBTargets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(DIRECTORY inc/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
