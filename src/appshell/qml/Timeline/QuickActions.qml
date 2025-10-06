import QtQuick 2.15

import Muse.UiComponents

Item {
        id: root
        objectName: "QuickActionsTimeline"

        height: 32
        anchors.fill: parent.fill

        // Displays a counter that shows the current time in HH:mm.ss
        Text {
                id: currentTime

                text: "00:00.00"

                font.pointSize: 24

                anchors.centerIn: root
                anchors.left: root.left
        }

        Rectangle {
                anchors.fill: root.fill

                border.width: 200
                border.color: "black"
        }
}
