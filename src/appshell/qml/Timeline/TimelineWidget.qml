import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: root

    /*Item {
        id: topbar

        height: 32

        anchor.left: root.left
        anchor.right: root.right
        anchor.top: root.top

        PlaybackActions {
            id: playbackActions
            anchor.left: topbar.left
            anchor.top: topbar.top
            anchor.bottom: topbar.bottom
        }
        TimelineSecondsBar {
            id: secondsBar

            anchor.right: topbar.right
            anchor.top: topbar.top
            anchor.bottom: topbar.bottom
        }
    }

    ScrollView {
        anchor.top: topbar.bottom
        anchor.left: root.left
        anchor.right: root.right
        anchor.bottom: root.bottom

        ObjectsTreeView {
            id: treeView

            anchor.top: playbackActions.bottom
            anchor.right: playbackActions.right
            anchor.left: parent.left
            anchor.bottom: parent.bottom
        }
        KeysView {
            anchor.left: treeView.left
            anchor.top: secondsBar.bottom
            anchor.right: parent.right
            anchor.bottom: parent.bottom
        }

        anchor.left: root.left
        anchor.right: root.right
        anchor.bottom: root.bottom
        anchor.top: topbar.bottom
        }*/
}
