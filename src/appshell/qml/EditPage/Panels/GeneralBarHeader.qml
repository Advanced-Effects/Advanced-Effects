import QtQuick 2.8
import QtQuick.Controls 2.1

import Muse.UiComponents 1.0
import Muse.Ui 1.0

Item {
    id: root

    width: parent.width
    height: parent.height

    property bool expanded: false
    property bool hovered: false
    property string text: ""

    property bool isInVisibleArea: true

    property var modelIndex: null

    signal toggleExpandRequested()

    StyledTextLabel {
        id: textItem

        width: root.width
        height: root.height

        horizontalAlignment: Text.AlignHLeft
        anchors {
            left: parent.left; leftMargin: 4;
            right: parent.right
        }

        text: root.text
        font: ui.theme.bodyBoldFont
    }
}
