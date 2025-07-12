import QtQuick 2.15

Column {
    id: root

    Row {
        id: topbar

        PlaybackActions {
            id: playbackActions
            anchor.left: root.left
            anchor.top: root.top
        }
        TimelineSecondsBar {
            id: secondsBar

            anchor.right: root.right
            anchor.top: root.top
        }
    }

    ScrollView {
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
    }
}
