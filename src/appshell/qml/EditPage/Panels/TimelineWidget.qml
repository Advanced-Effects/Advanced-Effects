import QtQuick 2.15
import QtQuick.Controls 2.15

import "../../Timeline/"

Item {
        id: root
        objectName: "TimelineWidget"

        LeftNavigation {
                id: leftNavigation

                anchors.right: keysView.left
                anchors.left: root.left
                anchors.top: root.top
                anchors.bottom: root.bottom

                width: 256 + 128
        }

        KeysView {
                id: keysView

                anchors.left: leftNavigation.right
                anchors.right: root.right
                anchors.top: root.top
                anchors.bottom: root.bottom
        }
}
