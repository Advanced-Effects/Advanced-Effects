# Downloads and installs QtQuickOpenGLWidget, a library I written
# to show an OpenGL widget within a QtQuick application.

include(ExternalProject)

ExternalProject_Add(QtQuickOpenGLWidget
       GIT_REPOSITORY https://github.com/advanced-effects/qtQuick-OpenGL-Widget.git
       GIT_TAG main

       BUILD_COMMAND ${CMAKE_COMMAND} --build .
       INSTALL_COMMAND ${CMAKE_COMMAND} --install .

       # ! NOTE: We share the CMAKE_PREFIX_PATH with QtQuickOpenGLWidget
       # So that it can find Qt also (when it's installed to a custom location)
       CMAKE_ARGS -DCMAKE_PREFIX_PATH=${CMAKE_PREFIX_PATH}
)
