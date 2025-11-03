cmake_minimum_required(VERSION 3.24)

cmake_policy(SET CMP0091 OLD) # not set MSVC default args

project(AdvancedEffects LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

###########################################
# Muse Framework
###########################################

set(MUSE_FRAMEWORK_PATH ${PROJECT_SOURCE_DIR}/thirdparty)
set(MUSE_FRAMEWORK_SRC_PATH ${MUSE_FRAMEWORK_PATH}/framework)

# Sets the paths where cmake scripts ("include" calls) will be looked up in
set(CMAKE_MODULE_PATH
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/buildscripts/cmake
    ${MUSE_FRAMEWORK_PATH}/buildscripts/cmake
    ${CMAKE_MODULE_PATH}
    )

include(${MUSE_FRAMEWORK_SRC_PATH}/cmake/MuseDeclareOptions.cmake)

# Installs 'declare_module' calls etc. (Module System)
include(DeclareModuleSetup)

# Installs 'muse_framework_config.h' from an input file
include(${MUSE_FRAMEWORK_SRC_PATH}/cmake/MuseSetupConfiguration.cmake)

include(GetPlatformInfo)

###########################################
# Setup option and build settings
###########################################
include(GetPaths)

set(AU4_BUILD_CONFIGURATION "app" CACHE STRING "Build configuration")
# Possible values:
# - app             - for desktop app
# - app-portable    - for desktop portable app (Windows build for PortableApps.com)
# - utest           - for unit tests (for CI)

set(AU4_BUILD_MODE "dev" CACHE STRING "Build mode")
# Possible values:
# - dev     - for development/nightly builds
# - testing - for testing versions (alpha, beta, RC)
# - release - for stable release builds

set(AU4_REVISION "" CACHE STRING "Build revision")

set(MUSE_ENABLE_UNIT_TESTS ON)
set(MUSE_MODULE_ACCESSIBILITY ON)
set(MUSE_MODULE_ACTIONS ON)
set(MUSE_MODULE_AUDIO OFF)
set(MUSE_MODULE_AUDIOPLUGINS OFF)
set(MUSE_MODULE_AUTOBOT ON) # If turned on, project doesn't compile
set(MUSE_MODULE_CLOUD OFF)
set(MUSE_MODULE_CLOUD_MUSESCORECOM OFF CACHE BOOL "Enable MuseScore.com account" FORCE)
set(MUSE_MODULE_DIAGNOSTICS ON)
set(MUSE_MODULE_DRAW ON)
set(MUSE_MODULE_DRAW_TESTS OFF)
set(MUSE_MODULE_EXTENSIONS ON)
set(MUSE_MODULE_GLOBAL ON)
set(MUSE_MODULE_GLOBAL_TESTS OFF)
set(MUSE_MODULE_LANGUAGES ON)
set(MUSE_MODULE_LEARN ON)
set(MUSE_MODULE_MIDI OFF)
set(MUSE_MODULE_MPE OFF)
set(MUSE_MODULE_MULTIINSTANCES ON)
set(MUSE_MODULE_MUSESAMPLER OFF)
set(MUSE_MODULE_NETWORK ON)
set(MUSE_MODULE_SHORTCUTS ON)
set(MUSE_MODULE_UI ON)
set(MUSE_MODULE_UI_TESTS OFF)
set(MUSE_MODULE_UPDATE OFF)
set(MUSE_MODULE_WORKSPACE ON)

# Modules (alphabetical order please)
option(AU4_BUILD_APPSHELL_MODULE "Build appshell module" ON)

# === Setup ===

option(GLAXNIMATE_SYSTEM_POTRACE "Get potrace from the system. If OFF (default), we build it ourselves from thirdparty/potrace." OFF)

# === Pack ===
option(MU_RUN_LRELEASE "Generate .qm files" ON)

# === Compile ===
option(MU_COMPILE_BUILD_MACOS_APPLE_SILICON "Build for Apple Silicon architecture. Only applicable on Macs with Apple Silicon, and requires suitable Qt version." OFF)
option(MU_COMPILE_INSTALL_QTQML_FILES "Whether to bundle qml files along with the installation (relevant on MacOS only)" ON)
option(MUSE_COMPILE_USE_UNITY "Use unity build." ON)
option(MUSE_COMPILE_USE_CCACHE "Try use ccache" ON)


###########################################
# Setup Configure
###########################################

# default
set(QT_ADD_LINGUISTTOOLS ON)
set(QT_ADD_CONCURRENT ON)
set(QT_QPROCESS_SUPPORTED ON)

# "SetupConfigure" sets useful CMake variables such as: MUSE_APP_INSTALL_PREFIX, etc.

if(EXISTS "${CMAKE_CURRENT_LIST_DIR}/SetupConfigure.local.cmake")
        include(${CMAKE_CURRENT_LIST_DIR}/SetupConfigure.local.cmake)
else()
        include(SetupConfigure)
endif()

###########################################
# Setup compiler and build environment
###########################################

include(SetupBuildEnvironment)
include(GetPlatformInfo)
if (MUE_COMPILE_USE_CCACHE)
        include(TryUseCcache)
endif(MUE_COMPILE_USE_CCACHE)


###########################################
# Setup external dependencies
###########################################
set(QT_MIN_VERSION "6.9.2")
include(SetupQt6)

###########################################
# Add source tree
###########################################
if (MUSE_ENABLE_UNIT_TESTS)
        enable_testing()
        message(STATUS "Enabled testing")
endif()

add_subdirectory(share)
add_subdirectory(thirdparty)
add_subdirectory(src)

if (MSVC)
        # Now that the `app` target is defined, we can set it as the startup project in Visual Studio.
        set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT app)
endif()

###########################################
# Setup Packaging
###########################################
if (OS_IS_LIN)
        include(${CMAKE_CURRENT_LIST_DIR}/buildscripts/packaging/Linux+BSD/SetupAppImagePackaging.cmake)
endif(OS_IS_LIN)
