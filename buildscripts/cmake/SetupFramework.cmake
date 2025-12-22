include(FetchContent)

FetchContent_Declare(Framework
        GIT_REPOSITORY https://github.com/Advanced-Effects/framework.git
        GIT_TAG main)

FetchContent_MakeAvailable(Framework)

set(MUSE_FRAMEWORK_PATH ${CMAKE_BINARY_DIR}/_deps/framework-src)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
		      ${MUSE_FRAMEWORK_PATH}/buildscripts
	      	      ${MUSE_FRAMEWORK_PATH}/buildscripts/cmake)

# Make "muse_create_module" macros available
include(DeclareModuleSetup)

