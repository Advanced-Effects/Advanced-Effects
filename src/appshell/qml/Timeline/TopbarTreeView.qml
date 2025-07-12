import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: root

    // 00:00.00 by default
    Label {
        id: currentPlaybackSecondsCount

        anchors.left: root.left
        anchors.top: root.top
        anchors.bottom: root.bottom
    }

    // Playback actions mean: pause button, play button... in timeline widget
    PlaybackActions {
        anchors.right: root.right
        anchors.top: root.top
        anchors.bottom: root.bottom
    }
}
