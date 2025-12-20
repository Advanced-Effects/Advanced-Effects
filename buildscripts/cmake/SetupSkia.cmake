include(FetchContent)

FetchContent_Declare(skia
        GIT_REPOSITORY https://github.com/Advanced-Effects/skia.git
        GIT_TAG kaixoo12-patch-1)
FetchContent_MakeAvailable(skia)

set(SKIA_LIBRARIES_DIRS ${CMAKE_BINARY_DIR}/_deps/skia-build)
set(SKIA_INCLUDE_DIRS ${CMAKE_BINARY_DIR}/_deps/skia-src)
if (WIN32)
	set(SKIA_LIBRARIES skia
			   user32
			   opengl32)
	add_definitions(-DSKIA_DLL)
else ()
	set(SKIA_LIBRARIES skia-friction)
	
endif()

# Warning: shitty CMake code bullshit
# This is a shitty trick to make it possible to link to libskia-friction file directly
add_custom_target(skia
    COMMAND ""
    DEPENDS skialib
    BYPRODUCTS ${SKIA_LIBRARIES}
)

# TODO: using this imported library does not work with Qt AUTOMOC for some reason
# so, DO NOT use IT!
add_library(Skia::Skia SHARED IMPORTED GLOBAL)

set_target_properties(Skia::Skia PROPERTIES
	IMPORTED_LOCATION ${SKIA_LIBRARIES}
	INTERFACE_INCLUDE_DIRECTORIES ${SKIA_INCLUDE_DIRS})

