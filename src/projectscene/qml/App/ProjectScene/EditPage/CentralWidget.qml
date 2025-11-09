import QtQuick 2.15
import QtQuick.Controls 2.15

import Muse.UiComponents

import App.AppShell
import App.ProjectScene

Item {
        id: root
        objectName: "CentralWidget"

        anchors.fill: parent.fill

        StyledTabBar {
                id: fileTabBar

                height: 32

                anchors.top: root.top
                anchors.left: root.left
                anchors.right: root.right
        }

        ApplicationCanvas {
                anchors.top: fileTabBar.top
                anchors.left: root.left
                anchors.right: root.right
                anchors.bottom: root.bottom
        }
}
