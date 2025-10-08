import QtQuick 2.15

import Muse.UiComponents

Item {
        id: root
        objectName: "QuickActionsTimeline"

        anchors.fill: parent.fill

        // Displays a counter that shows the current time in HH:mm.ss
        Text {
                id: currentTime

                text: "00:00.00"

                font.pointSize: 24
                color: ui.theme.accentColor

                // Center vertically
                anchors.centerIn: root
                anchors.left: root.left
                anchors.top: root.top
                anchors.bottom: root.bottom

                z: 999
        }

        // Background color
        Rectangle {
                anchors.fill: root.fill

                color: ui.theme.backgroundSecondaryColor
        }
}
