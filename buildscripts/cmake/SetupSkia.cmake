include(FetchContent)

FetchContent_Declare(skia
        GIT_REPOSITORY https://github.com/friction2d/skia.git
        GIT_TAG m83f)
FetchContent_MakeAvailable(skia)

# we have to include this directory globally because fetchcontent
# isn't adding the include dir and
# we can't include directories on another project's target
include_directories("${CMAKE_BINARY_DIR}/_deps/skia-src")
