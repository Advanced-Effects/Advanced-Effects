import QtQuick 2.15

import Muse.UiComponents

Item {
        id: root
        objectName: "QuickActionsTimeline"

        height: 36
        anchors.fill: parent.fill

        // Displays a counter that shows the current time in HH:mm.ss
        Text {
                id: currentTime

                text: "00:00.00"

                font.family: ui.theme.largeBodyBoldFont.family
                font.pointSize: 24

                color: ui.theme.accentColor

                // Center vertically
                anchors {
                        verticalCenter: root
                        left: root.left; leftMargin: 4
                        top: root.top
                        bottom: root.bottom
                }

                z: 999
        }

        TextInputField {
                id: searchBar
                width: 180

                hint: qsTrc("timeline", "Search...")

                anchors {
                        verticalCenter: root
                        left: currentTime.right
                        leftMargin: 8
                }
        }

        // Background color
        Rectangle {
                anchors.fill: root.fill

                color: ui.theme.backgroundSecondaryColor
        }
}
