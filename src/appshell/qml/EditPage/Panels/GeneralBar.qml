import QtQuick 2.15
import QtQuick.Controls 2.15

import Muse.UiComponents

Column {
        id: root
        objectName: "GeneralBar"

        GeneralBarHeader {
                text: "Align"
                component: Text { text: "Align!" }
        }

        GeneralBarHeader {
                text: "Fill & Stroke"
                component: Text { text: "F&S!" }
        }
}
