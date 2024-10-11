cmake_minimum_required(VERSION 3.24)

##########################################################################
# tools to beused for programming the AVR
##########################################################################
set(AVR_UPLOADTOOL avrdude)
set(AVR_PROGRAMMER avrispmkII)
set(AVR_UPLOADTOOL_PORT usb)

##########################################################################
# AVR and fuses to be set
##########################################################################
set(AVR_MCU atmega328)
set(AVR_H_FUSE 0xd9)
set(AVR_L_FUSE 0x62)

### END TOOLCHAIN SETUP AREA #############################################

include(cmake/avr-gcc-toolchain.cmake)

##########################################################################
# name your project
##########################################################################
project(vlcb_template_avr)

##########################################################################
# set C standard
##########################################################################
set(CMAKE_C_STANDARD 11)

##########################################################################
# status messages
##########################################################################
message(STATUS "Current uploadtool is: ${AVR_UPLOADTOOL}")
message(STATUS "Current programmer is: ${AVR_PROGRAMMER}")
message(STATUS "Current upload port is: ${AVR_UPLOADTOOL_PORT}")
message(STATUS "Current uploadtool options are: ${AVR_UPLOADTOOL_OPTIONS}")
message(STATUS "Current MCU is set to: ${AVR_MCU}")
message(STATUS "Current H_FUSE is set to: ${AVR_H_FUSE}")
message(STATUS "Current L_FUSE is set to: ${AVR_L_FUSE}")

##########################################################################
# set build type
##########################################################################
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

# needs to be defined for AVR toolchain
##########################################################################
set(MCU_SPEED "8000000UL")

##########################################################################
# some cmake cross-compile necessities
##########################################################################
if(DEFINED ENV{AVR_FIND_ROOT_PATH})
	set(CMAKE_FIND_ROOT_PATH $ENV{AVR_FIND_ROOT_PATH})
else(DEFINED ENV{AVR_FIND_ROOT_PATH})
	if(EXISTS "/opt/local/avr")
		set(CMAKE_FIND_ROOT_PATH "/opt/local/avr")
	elseif(EXISTS "/usr/avr")
		set(CMAKE_FIND_ROOT_PATH "/usr/avr")
	elseif(EXISTS "/usr/lib/avr")
		set(CMAKE_FIND_ROOT_PATH "/usr/lib/avr")
	elseif(EXISTS "/usr/local/CrossPack-AVR")
		set(CMAKE_FIND_ROOT_PATH "/usr/local/CrossPack-AVR")
	else(EXISTS "/opt/local/avr")
		message(FATAL_ERROR "Please set AVR_FIND_ROOT_PATH in your environment.")
	endif(EXISTS "/opt/local/avr")
endif(DEFINED ENV{AVR_FIND_ROOT_PATH})
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
# not added automatically, since CMAKE_SYSTEM_NAME is "generic"
set(CMAKE_SYSTEM_INCLUDE_PATH "${CMAKE_FIND_ROOT_PATH}/include")
set(CMAKE_SYSTEM_LIBRARY_PATH "${CMAKE_FIND_ROOT_PATH}/lib")

##########################################################################
# status messages for generating
##########################################################################
message(STATUS "Set CMAKE_FIND_ROOT_PATH to ${CMAKE_FIND_ROOT_PATH}")
message(STATUS "Set CMAKE_SYSTEM_INCLUDE_PATH to ${CMAKE_SYSTEM_INCLUDE_PATH}")
message(STATUS "Set CMAKE_SYSTEM_LIBRARY_PATH to ${CMAKE_SYSTEM_LIBRARY_PATH}")

##########################################################################
# set compiler options for build types
##########################################################################
if(CMAKE_BUILD_TYPE MATCHES Release)
	set(CMAKE_C_FLAGS_RELEASE "-Os")
	set(CMAKE_CXX_FLAGS_RELEASE "-Os")
endif(CMAKE_BUILD_TYPE MATCHES Release)

if(CMAKE_BUILD_TYPE MATCHES RelWithDebInfo)
	set(CMAKE_C_FLAGS_RELWITHDEBINFO "-Os -save-temps -g -gdwarf-3 -gstrict-dwarf")
	set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-Os -save-temps -g -gdwarf-3 -gstrict-dwarf")
endif(CMAKE_BUILD_TYPE MATCHES RelWithDebInfo)

if(CMAKE_BUILD_TYPE MATCHES Debug)
	set(CMAKE_C_FLAGS_DEBUG "-O0 -save-temps -g -gdwarf-3 -gstrict-dwarf")
	set(CMAKE_CXX_FLAGS_DEBUG "-O0 -save-temps -g -gdwarf-3 -gstrict-dwarf")
endif(CMAKE_BUILD_TYPE MATCHES Debug)

##########################################################################
# compiler options for all build types
##########################################################################
# TODO: enable LTO and test if it helped

add_definitions("-DF_CPU=${MCU_SPEED}")
add_definitions("-fpack-struct")
add_definitions("-fshort-enums")
add_definitions("-Wall")
add_definitions("-Werror")
add_definitions("-pedantic")
add_definitions("-pedantic-errors")
add_definitions("-funsigned-char")
add_definitions("-funsigned-bitfields")
add_definitions("-ffunction-sections")
add_definitions("-c")
add_definitions("-std=gnu99")

##########################################################################
# include search paths
##########################################################################
include_directories(${AVR-EXAMPLE_SOURCE_DIR}/include)

# install to local directory instead of system (we can use this to install external projects)
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/local)
# add local includes from installed projects to search path
include_directories(${CMAKE_SOURCE_DIR}/local/include)

##########################################################################
# building library and application in their subdirectories
##########################################################################

# allow use of FetchContent and ExternalProject
include(FetchContent)
include(ExternalProject)

add_avr_executable(
		${PROJECT_NAME}
		src/main.c
)
# hack that will get out the proper target name to add dependencies for later
get_target_property(DEPENDENCY_TARGET ${PROJECT_NAME} OUTPUT_NAME)

# find_library(M_LIB m)
# message(STATUS "avr-libm: ${M_LIB}")

find_library(C_LIB c)
message(STATUS "avr-libc: ${C_LIB}")
avr_target_link_libraries(${PROJECT_NAME} ${C_LIB})

# Add VLCB SDK
message("vlcb: fetching")
# We use FetchContent to download the source
FetchContent_Declare(
		vlcb
		# you can use SOURCE_DIR to use local SDK distribution
		# it's recommended to use the git version in most cases
		SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/../.."
#		GIT_REPOSITORY "git@github.com:0xfrej/vlcb.git"
#		GIT_TAG "origin/main"
#		GIT_SUBMODULES "" # skip submodules (necessary)
		OVERRIDE_FIND_PACKAGE # this is to make find_package work
)
FetchContent_MakeAvailable(vlcb)
message("vlcb: fetched")
set(VLCB_VERSION 0.1.0)
message("vlcb: version ${VLCB_VERSION}")
find_package(vlcb ${VLCB_VERSION} REQUIRED)
# we need to use this as the toolchain version is bugged with libraries defined in FetchContent libraries
target_link_libraries(${DEPENDENCY_TARGET} vlcb_common)
message("vlcb: linked")
# end Add VLCB SDK
