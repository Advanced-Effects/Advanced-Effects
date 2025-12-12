include(FetchContent)

FetchContent_Declare(Framework
        GIT_REPOSITORY https://github.com/Advanced-Effects/framework.git
        GIT_TAG main)

FetchContent_Populate(Framework)

if (Framework_BINARY_DIR)
add_subdirectory(${Framework_SOURCE_DIR} ${Framework_BINARY_DIR})
else()
add_subdirectory(${Framework_SOURCE_DIR})
endif()
