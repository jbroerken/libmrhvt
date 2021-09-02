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
project(libmrhvt VERSION 1.0.0
                 DESCRIPTION "Voice toolkit library for MRH platform applications"
                 LANGUAGES CXX)
set(LIB_SO_VERSION 1)

#########################################################################
#
#  PATHS
#
#########################################################################

###
#  Install Paths
#  -------------
#  GNU system paths for installation.
###
include(GNUInstallDirs)

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
#  Public API Path
#  ---------------
#  The path to the public api include folder.
###
set(PUBLIC_API_DIR_PATH "${INCLUDE_DIR_PATH}/libmrhvt")
					 
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
                      PREFIX "lib"
                      OUTPUT_NAME "mrhvt"
                      SUFFIX ".so"
                      VERSION ${PROJECT_VERSION}
                      SOVERSION ${LIB_SO_VERSION})

###
#  Required Libraries
#  ------------------
#  Libraries and / or headers required by this library.
###
find_library(libmrhbf NAMES mrhbf REQUIRED)
target_link_libraries(libmrhvt_Shared PUBLIC mrhbf)

###
#  Install
#  -------
#  Library installation.
###
install(TARGETS libmrhvt_Shared
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY "${PUBLIC_API_DIR_PATH}/"
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        FILES_MATCHING
        PATTERN "*.h")