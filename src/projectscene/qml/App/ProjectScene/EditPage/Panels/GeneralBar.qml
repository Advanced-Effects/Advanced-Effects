import QtQuick 2.15
import QtQuick.Controls 2.15

import Muse.Ui
import Muse.UiComponents

Column {
        id: root
        objectName: "GeneralBar"

        GeneralBarHeader {
                headerTitle: qsTrc("generalPanel", "Align")
                component: Text { text: "Align stuff! Enable/disable snapping!" }
        }

        GeneralBarHeader {
                headerTitle: qsTrc("generalPanel", "Preview")
                component: Text { text: "Start / stop playback." }
        }

        GeneralBarHeader {
                headerTitle: qsTrc("generalPanel", "Fill & Stroke")
                component: Text { text: "F&S!" }
        }

        GeneralBarHeader {
                headerTitle: qsTrc("generalPanel", "Object Properties")
                component: Text { text: "You can change the object's properties to animate the objects here!" }
        }

        GeneralBarHeader {
                headerTitle: qsTrc("generalPanel", "Effects")
                component: Text { text: "Apply and undo effects!" }
        }
}
