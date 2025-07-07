import QtQuick 2.15

import AdvancedEffects.AppShell

Column {
    id: root
    objectName: "WindowContent"

    // Includes the tool selection bar, the fill and stroke bar...
    Topbar {
        id: topbar

        anchors.top: root.top
        anchors.left: root.left
        anchors.right: root.right
    }

    Row {
        anchors.top: topbar.bottom
        anchors.left: root.left
        anchors.right: root.right

        PropertiesBar {
            anchors.left: parent.left
        }
        CentralWidget {}
        GeneralBar {
            anchors.right: parent.right
        }
    }

    TimelineBar {
        anchors.left: root.left
        anchors.right: root.right
        anchors.bottom: root.bottom
    }
}
