include(FetchContent)

# Allow using FetchContent_Populate
cmake_policy(SET CMP0169 OLD)

FetchContent_Declare(Framework
        GIT_REPOSITORY https://github.com/Advanced-Effects/framework.git
        GIT_TAG main)

FetchContent_Populate(Framework)

if (Framework_BINARY_DIR)
add_subdirectory(${Framework_SOURCE_DIR} ${Framework_BINARY_DIR})
else()
add_subdirectory(${Framework_SOURCE_DIR})
endif()
