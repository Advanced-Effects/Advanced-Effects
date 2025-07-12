import QtQuick 2.15

// Here is the widget in which the OpenGL canvas is rendered
Item {
    id: root

    OpenGLContainer {
        anchors.fill: root
    }
}
