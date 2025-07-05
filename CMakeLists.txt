###########################################
# Base project setup
###########################################

cmake_minimum_required(VERSION 3.20)

project(AdvancedEffects VERSION 0.8 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

###########################################
# Include build scripts for them to be importable by include()
###########################################
set(CMAKE_MODULE_PATH
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/buildscripts
    ${CMAKE_CURRENT_LIST_DIR}/buildscripts/cmake
    ${CMAKE_MODULE_PATH}
)

###########################################
# Add declare_module functions
###########################################
include(DeclareModuleSetup)

###########################################
# Setup "environment" variables
###########################################

set(AE_FRAMEWORK_PATH ${CMAKE_CURRENT_LIST_DIR})
set(AE_FRAMEWORK_SRC_PATH ${CMAKE_CURRENT_LIST_DIR}/src/framework)

###########################################
# Setup external dependencies
###########################################

set(QT_MIN_VERSION "6.2.4")
set(QT_ADD_STATEMACHINE ON)

include(SetupQt6)

###########################################
# Add source tree
###########################################

add_subdirectory(src)

###########################################
# Setup Packaging
###########################################

if (OS_IS_LIN)
    include(packaging/Linux+BSD/SetupAppImagePackaging)
endif(OS_IS_LIN)

if (OS_IS_WIN)
    include(packaging/Windows/SetupWindowsPackaging)
endif(OS_IS_WIN)
