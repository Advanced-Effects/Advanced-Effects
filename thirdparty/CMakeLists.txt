if(NOT GLAXNIMATE_SYSTEM_POTRACE)
        add_subdirectory(potrace)
endif()

add_subdirectory(QtAppSetup)

add_subdirectory(framework)

add_subdirectory(skia)
