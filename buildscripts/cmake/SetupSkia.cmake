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

add_library(Skia::Skia SHARED IMPORTED GLOBAL)

# Set the .dll file and include path IN THE LINKING PHASE
# (so that, when this is looked for, libskia-friction.so already exists)
set_target_properties(Skia::Skia PROPERTIES
	IMPORTED_LOCATION ${SKIA_LIBRARIES}
	INTERFACE_INCLUDE_DIRECTORIES ${SKIA_INCLUDE_DIRS})

