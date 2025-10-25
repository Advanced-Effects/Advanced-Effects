import QtQuick 2.15

import Muse.UiComponents 1.0

import App.AppShell 1.0
import "./TitleBar"

AppWindow {
    id: root

    PlatformDetails {
            id: platform
    }

    // Make window frameless
    property bool isFrameless: platform.isWindows() ? Qt.FramelessWindowHint : Qt.Window
    flags: isFrameless

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
