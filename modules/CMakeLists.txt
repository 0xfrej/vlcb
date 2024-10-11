# SDK modules live here

# All targets in the lib tree should be included with a directory prefix:
#	#include <vlcb/header.h>
# To accomplish this, we automatically set `target_include_directories` for library
# targets so this scheme can be used.
#
# Library targets themselves should NOT set public/interface includes within the library tree
function(add_library target module_dir)
    # Forward all arguments to the original add_library
    _add_library(${target} ${ARGN})
    # Ensure this directory is included as an interface include
    target_include_directories(
            ${target}
            PRIVATE ${module_dir}/src
            PUBLIC $<BUILD_INTERFACE:${module_dir}/inc>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    )
endfunction()

#############
# Libraries #
#############

add_subdirectory(common)
add_subdirectory(platform)
add_subdirectory(net)
add_subdirectory(module)