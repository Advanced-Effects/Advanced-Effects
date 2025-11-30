import QtQuick
import QtQuick.Controls

import Muse.UiComponents

Item {
        id: root

        property string fileName
        property bool isEdited

        signal onRequestClose()
        signal onRequestFocus()

        Text {
                text: fileName

                anchors {
                        leftMargin: 8
                        left: root.left
                        verticalCenter: root
                }
        }

        FlatButton {
                icon: IconCode.CROSS

                anchors {
                        rightMargin: 4
                        right: root.right
                        verticalCenter: root
                }
        }


}
