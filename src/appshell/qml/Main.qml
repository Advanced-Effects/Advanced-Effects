import QtQuick 2.15

import Muse.UiComponents 1.0

import App.AppShell
import "./TitleBar"

AppWindow {
    id: root

    // Make window frameless
    flags: Qt.Window | Qt.FramelessWindowHint
    // Allow frameless window to be movable
    FramelessWindowModel {
            id: framelessModel

            titleBarMoveArea: appTitleBar.titleMoveAreaRect
    }

    Component.onCompleted: {
            framelessModel.init(this)
    }

    function toggleMaximized() {
        if (root.visibility === Window.Maximized) {
            root.showNormal()
        } else {
            root.showMaximized()
        }
    }

    AppTitlebar {
        id: appTitleBar

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        height: 48
        title: root.title

        onShowWindowMinimizedRequested: {
            root.showMinimized()
        }

        onToggleWindowMaximizedRequested: {
            root.toggleMaximized()
        }

        onCloseWindowRequested: {
            root.close()
        }
    }

    WindowContent {
        id: window

        anchors.top: appTitleBar.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
    }
}
