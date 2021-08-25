#########################################################################
#
#  CMAKE
#
#########################################################################

###
#  Minimum Version
#  ---------------
#  The CMake version required.
###
cmake_minimum_required(VERSION 3.1)

###
#  CMake Configuration
#  -------------------
#  Configuration settings for CMake.
#
#  NOTE:
#  These settings have to be applied before the project() setting!
###
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 14)

###
#  Project Info
#  ------------
#  General simple information about our project.
###
project(libmrhvt VERSION 1.0
                 DESCRIPTION "Voice toolkit library for MRH platform applications"
                 LANGUAGES CXX)

#########################################################################
#
#  PATHS
#
#########################################################################

###
#  Binary Paths
#  ------------
#  The paths for our created binary file(s).
###
set(BIN_DIR_PATH "${CMAKE_SOURCE_DIR}/lib/")
file(MAKE_DIRECTORY ${BIN_DIR_PATH})

###
#  Build Paths
#  -----------
#  The paths for the cmake build.
###
set(BUILD_DIR_PATH "${CMAKE_SOURCE_DIR}/build/")
file(MAKE_DIRECTORY ${BUILD_DIR_PATH})

###
#  Source Paths
#  ------------
#  The paths to the source files to use.
###
set(SRC_DIR_PATH "${CMAKE_SOURCE_DIR}/src/")
set(INCLUDE_DIR_PATH "${CMAKE_SOURCE_DIR}/include/")

set(SRC_LIST_INPUT "${SRC_DIR_PATH}/libmrhvt/Input/MRH_Trigger.cpp"
                   "${SRC_DIR_PATH}/libmrhvt/Input/MRH_InputTrigger.cpp"
                   "${INCLUDE_DIR_PATH}/libmrhvt/libmrhvt/Input/MRH_Trigger.h"
                   "${INCLUDE_DIR_PATH}/libmrhvt/libmrhvt/Input/MRH_InputTrigger.h")
					
set(SRC_LIST_OUTPUT "${SRC_DIR_PATH}/libmrhvt/Output/MRH_Word.cpp"
                    "${SRC_DIR_PATH}/libmrhvt/Output/MRH_Placement.cpp"
                    "${SRC_DIR_PATH}/libmrhvt/Output/MRH_Sentence.cpp"
                    "${SRC_DIR_PATH}/libmrhvt/Output/MRH_OutputGenerator.cpp"
                    "${INCLUDE_DIR_PATH}/libmrhvt/libmrhvt/Output/MRH_Word.h"
                    "${INCLUDE_DIR_PATH}/libmrhvt/libmrhvt/Output/MRH_Placement.h"
                    "${INCLUDE_DIR_PATH}/libmrhvt/libmrhvt/Output/MRH_Sentence.h"
                    "${INCLUDE_DIR_PATH}/libmrhvt/libmrhvt/Output/MRH_OutputGenerator.h")
					
set(SRC_LIST_STRING "${SRC_DIR_PATH}/libmrhvt/String/Compare/MRH_DefaultCompare.cpp"
                    "${SRC_DIR_PATH}/libmrhvt/String/Compare/MRH_Levenshtein.cpp"
                    "${SRC_DIR_PATH}/libmrhvt/String/Clean/MRH_CleanSet.cpp"
                    "${SRC_DIR_PATH}/libmrhvt/String/MRH_Convert.cpp"
                    "${SRC_DIR_PATH}/libmrhvt/String/MRH_Clean.cpp"
                    "${SRC_DIR_PATH}/libmrhvt/String/MRH_LocalisedPath.cpp"
                    "${SRC_DIR_PATH}/libmrhvt/String/MRH_SpeechString.cpp"
                    "${INCLUDE_DIR_PATH}/libmrhvt/libmrhvt/String/Compare/MRH_DefaultCompare.h"
                    "${INCLUDE_DIR_PATH}/libmrhvt/libmrhvt/String/Compare/MRH_Levenshtein.h"
                    "${INCLUDE_DIR_PATH}/libmrhvt/libmrhvt/String/Clean/MRH_CleanSet.h"
                    "${INCLUDE_DIR_PATH}/libmrhvt/libmrhvt/String/MRH_Compare.h"
                    "${INCLUDE_DIR_PATH}/libmrhvt/libmrhvt/String/MRH_Convert.h"
                    "${INCLUDE_DIR_PATH}/libmrhvt/libmrhvt/String/MRH_Clean.h"
                    "${INCLUDE_DIR_PATH}/libmrhvt/libmrhvt/String/MRH_LocalisedPath.h"
                    "${INCLUDE_DIR_PATH}/libmrhvt/libmrhvt/String/MRH_SpeechString.h")
					
set(SRC_LIST_GLOBAL "${SRC_DIR_PATH}/libmrhvt/MRH_VTRevision.cpp"
                    "${INCLUDE_DIR_PATH}/libmrhvt/libmrhvt/MRH_VTException.h"
                    "${INCLUDE_DIR_PATH}/libmrhvt/libmrhvt/MRH_VTRevision.h"
                    "${INCLUDE_DIR_PATH}/libmrhvt/libmrhvt.h")
					
###
#  Library Paths
#  -------------
#  The paths to the external libraries to use. 
#  Both the binary and include paths should be set here.
#  Add OS specific libraries in their own lists.
###
set(LIB_DIR_PATH "${CMAKE_SOURCE_DIR}/lib/")
# Include dir path is defined with the sources!

set(LIB_BIN_LIST "${LIB_DIR_PATH}/libmrhbf.a")
set(LIB_INCLUDE_LIST "${INCLUDE_DIR_PATH}/mrhshared"
                     "${INCLUDE_DIR_PATH}/libmrhbf")
					 
#########################################################################
#
#  TARGET
#
#########################################################################

###
#  Target
#  ------
#  The target(s) to build.
###
add_library(libmrhvt_Shared SHARED ${SRC_LIST_GLOBAL}
                                   ${SRC_LIST_STRING}
                                   ${SRC_LIST_OUTPUT}
                                   ${SRC_LIST_INPUT})
set_target_properties(libmrhvt_Shared
                      PROPERTIES
                      PREFIX ""
                      OUTPUT_NAME "libmrhvt"
                      SUFFIX ".so"
                      ARCHIVE_OUTPUT_DIRECTORY ${BIN_DIR_PATH}
                      LIBRARY_OUTPUT_DIRECTORY ${BIN_DIR_PATH}
                      RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR_PATH})
					  
add_library(libmrhvt_Static STATIC ${SRC_LIST_GLOBAL}
                                   ${SRC_LIST_STRING}
                                   ${SRC_LIST_OUTPUT}
                                   ${SRC_LIST_INPUT})
set_target_properties(libmrhvt_Static
                      PROPERTIES
                      PREFIX ""
                      OUTPUT_NAME "libmrhvt"
                      SUFFIX ".a"
                      ARCHIVE_OUTPUT_DIRECTORY ${BIN_DIR_PATH}
                      LIBRARY_OUTPUT_DIRECTORY ${BIN_DIR_PATH}
                      RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR_PATH})

###
#  Required Libraries
#  ------------------
#  Libraries and / or headers required by this library.
###
target_link_libraries(libmrhvt_Shared PUBLIC ${LIB_BIN_LIST})
target_link_libraries(libmrhvt_Static PUBLIC ${LIB_BIN_LIST})

include_directories(${LIB_INCLUDE_LIST})