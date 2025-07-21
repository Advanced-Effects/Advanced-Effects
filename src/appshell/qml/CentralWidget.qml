import QtQuick 2.15

Column {
    id: root

    FileTabBar {
        id: fileTabBar

        anchors.left: root.left
        anchors.right: root.right
        anchors.top: root.top
    }
    ViewCanvas {
        anchors.left: root.left
        anchors.right: root.right
        anchors.top: fileTabBar.bottom
        anchors.bottom: root.bottom
    }
}
