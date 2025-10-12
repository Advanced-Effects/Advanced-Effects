import QtQuick 2.15
import QtQuick.Controls 2.15

import Muse.Ui 1.0
import Muse.UiComponents 1.0

Rectangle {
        id: root

        height: parent.height
        width: parent.width

        signal hideRequested()

        function apply() {
                return true
        }

        function reset() {}

        StyledFlickable {
                id: flickable
                anchors.fill: parent

                Item {
                        id: content
                        anchors.fill: parent
                }
        }
}
