# Downloads and installs QtQuickOpenGLWidget, a library I written
# to show an OpenGL widget within a QtQuick application.

include(ExternalProject)

ExternalProject_Add(QtQuickOpenGLWidget
       GIT_REPOSITORY https://github.com/advanced-effects/qtQuick-OpenGL-Widget.git
       GIT_TAG main
)
