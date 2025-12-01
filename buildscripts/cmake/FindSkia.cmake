include(FindPackageHandleStandardArgs)
include(FetchContent)

set(PACKAGE_NAME Skia)
set(PACKAGE_SRC "${CMAKE_BINARY_DIR}/_deps/skia-src")
set(PACKAGE_BUILD "${CMAKE_BINARY_DIR}/_deps/skia-build")

FetchContent_Declare(skia
        GIT_REPOSITORY https://github.com/friction2d/skia.git
        GIT_TAG m83f)
FetchContent_MakeAvailable(skia)

set(Skia_FOUND TRUE)

set(Skia_LIBRARY ${PACKAGE_BUILD}/libskia-friction.so)
set(Skia_INCLUDE_DIR ${PACKAGE_SRC})

add_library(${PACKAGE_NAME}::${PACKAGE_NAME} SHARED IMPORTED)
set_target_properties(${PACKAGE_NAME}::${PACKAGE_NAME} PROPERTIES
    IMPORTED_LOCATION ${Skia_LIBRARY}
    INTERFACE_INCLUDE_DIRECTORIES ${Skia_INCLUDE_DIR}
)
