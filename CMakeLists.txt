###########################################
# Base project setup
###########################################

cmake_minimum_required(VERSION 3.20)

cmake_policy(SET CMP0091 OLD) # not set MSVC default args

set(APP_TITLE AdvancedEffects)
set(APP_VERSION 0.1)

project(${APP_TITLE} VERSION ${APP_VERSION} LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

###########################################
# Modules (alphabetical order please)
###########################################
option(MUE_BUILD_APPSHELL_MODULE "Build appshell module" ON)
option(MUE_BUILD_BRAILLE_MODULE "Build braille module" ON)
option(MUE_BUILD_BRAILLE_TESTS "Build braille tests" ON)
option(MUE_BUILD_CONVERTER_MODULE "Build converter module" ON)
option(MUE_BUILD_ENGRAVING_TESTS "Build engraving tests" ON)
option(MUE_BUILD_ENGRAVING_DEVTOOLS "Build engraving devtools" ON)
option(MUE_BUILD_ENGRAVING_PLAYBACK "Build engraving playback" ON)
option(MUE_BUILD_IMPORTEXPORT_MODULE "Build importexport module" ON)
option(MUE_BUILD_IMPORTEXPORT_TESTS "Build importexport tests" ON)
option(MUE_BUILD_VIDEOEXPORT_MODULE "Build videoexport module" OFF)
option(MUE_BUILD_IMAGESEXPORT_MODULE "Build imagesexport module" ON)
option(MUE_BUILD_INSPECTOR_MODULE "Build inspector module" ON)
option(MUE_BUILD_INSTRUMENTSSCENE_MODULE "Build instruments scene module" ON)
option(MUE_BUILD_MUSESOUNDS_MODULE "Build muse sounds module" ON)
option(MUE_BUILD_NOTATION_MODULE "Build notation module" ON)
option(MUE_BUILD_NOTATION_TESTS "Build notation tests" ON)
option(MUE_BUILD_PALETTE_MODULE "Build palette module" ON)
option(MUE_BUILD_PLAYBACK_MODULE "Build playback module" ON)
option(MUE_BUILD_PLAYBACK_TESTS "Build playback tests" ON)
option(MUE_BUILD_PROJECT_MODULE "Build project module" ON)
option(MUE_BUILD_PROJECT_TESTS "Build project tests" ON)

# === Setup ===
option(MUE_DOWNLOAD_SOUNDFONT "Download the latest soundfont version as part of the build process" OFF)

# === Pack ===
option(MUE_RUN_LRELEASE "Generate .qm files" ON)
option(MUE_INSTALL_SOUNDFONT "Install sound font" OFF)

# === Compile ===
option(MU_COMPILE_BUILD_MACOS_APPLE_SILICON "Build for Apple Silicon architecture. Only applicable on Macs with Apple Silicon, and requires suitable Qt version." OFF)
option(MU_COMPILE_INSTALL_QTQML_FILES "Whether to bundle qml files along with the installation (relevant on MacOS only)" ON)
option(MU_COMPILE_USE_PCH "Use precompiled headers." ON)
option(MU_COMPILE_USE_UNITY "Use unity build." ON)
option(MU_COMPILE_USE_CCACHE "Try use ccache" ON)

# === Debug ===
option(MU_ENABLE_STRING_DEBUG_HACK "Enable string debug hack (only clang)" ON)

###########################################
# Setup "environment" variables
###########################################

set(MUSE_FRAMEWORK_PATH ${CMAKE_CURRENT_LIST_DIR}/thirdparty/Muse)
set(MUSE_FRAMEWORK_SRC_PATH ${MUSE_FRAMEWORK_PATH}/framework)

message("MUSE_FRAMEWORK_SRC_PATH: ${MUSE_FRAMEWORK_SRC_PATH}")
message("MUSE_FRAMEWORK_PATH: ${MUSE_FRAMEWORK_PATH}")

###########################################
# Include build scripts for them to be importable by include()
###########################################

set(CMAKE_MODULE_PATH
    ${CMAKE_CURRENT_LIST_DIR}
    ${MUSE_FRAMEWORK_PATH}/buildscripts/cmake
    ${MUSE_FRAMEWORK_SRC_PATH}/cmake
    ${CMAKE_MODULE_PATH}
)

###########################################
# Setup option and build settings
###########################################

include(GetPaths)

set(APP_BUILD_CONFIGURATION "app" CACHE STRING "Build configuration")
# Possible values:
# - app             - for desktop app
# - app-portable    - for desktop portable app (Windows build for PortableApps.com)
# - utest           - for unit tests (for CI)

set(APP_BUILD_MODE "dev" CACHE STRING "Build mode")
# Possible values:
# - dev     - for development/nightly builds
# - testing - for testing versions (alpha, beta, RC)
# - release - for stable release builds

set(APP_REVISION "" CACHE STRING "Build revision")

set(MUSE_MODULE_AUTOBOT OFF)
set(MUSE_MODULE_DRAW OFF)
set(MUSE_MODULE_UPDATE OFF)

###########################################
# Add declare_module functions
###########################################

include(DeclareModuleSetup)
include(MuseDeclareOptions)

###########################################
# Setup external dependencies
###########################################

set(QT_MIN_VERSION "6.9.1")
set(QT_ADD_STATEMACHINE ON)

include(SetupQt6)

qt_policy(SET QTP0001 NEW)
qt_policy(SET QTP0002 NEW)
qt_policy(SET QTP0003 NEW) # Qt 6.7
qt_policy(SET QTP0004 NEW) # Qt 6.8

###########################################
# Setup Configure
###########################################

add_definitions(-DQT_SUPPORT)
add_definitions(-DKORS_LOGGER_QT_SUPPORT)

set(MUSE_APP_INSTALL_NAME "\"App\"")
set(MUSE_APP_INSTALL_PREFIX "\"\"")
set(MUSE_APP_INSTALL_SUFFIX "\"\"")
set(MUSE_APP_VERSION "4.0.0")

include(MuseSetupConfiguration)

###########################################
# Setup compiler and build environment
###########################################

include(SetupBuildEnvironment)
include(GetPlatformInfo)
if (MUE_COMPILE_USE_CCACHE)
    include(TryUseCcache)
endif(MUE_COMPILE_USE_CCACHE)

###########################################
# Include MuseScore framework (UI library + utilities)
###########################################

add_subdirectory(${MUSE_FRAMEWORK_SRC_PATH} ${MUSE_FRAMEWORK_PATH})

###########################################
# Add source tree
###########################################

add_subdirectory(src)
