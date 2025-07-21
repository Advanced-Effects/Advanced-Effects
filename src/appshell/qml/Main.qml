import QtQuick 2.15

import Muse.UiComponents

AppWindow {
    id: root

    AppTitlebar {
        id: appTitlebar

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

    WindowContents {
        id: windowContents

        anchors.top: appTitlebar.bottom
        anchors.left: root.left
        anchors.right: root.right
        anchors.bottom: root.bottom
    }
}
