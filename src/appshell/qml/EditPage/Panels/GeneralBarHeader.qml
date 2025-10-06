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
    property bool unresolved: false
    property string text: ""

    property bool isInVisibleArea: true

    property var modelIndex: null

    signal toggleExpandRequested()

    FlatButton {
        id: paletteExpandArrow

        z: 1000
        width: height
        visible: !root.unresolved // TODO: make a separate palette placeholder component
        activeFocusOnTab: false // same focus object as parent palette
        icon: root.expanded ? IconCode.SMALL_ARROW_DOWN : IconCode.SMALL_ARROW_RIGHT
        transparent: true

        enabled: paletteExpandArrow.visible
        navigation.panel: root.navigationPanel
        navigation.row: root.navigationRow
        navigation.column: 1
        navigation.accessible.name: root.expanded
                                    //: Collapse a tree item
                                    ? qsTrc("global", "Collapse")
                                    //: Expand a tree item
                                    : qsTrc("global", "Expand")

        onClicked: root.toggleExpandRequested()
    }

    StyledTextLabel {
        id: textItem

        z: 999

        width: root.width
        height: root.height

        horizontalAlignment: Text.AlignHLeft
        anchors {
            left: paletteExpandArrow.right; leftMargin: 4;
            right: root.right
        }

        text: root.text
        font: ui.theme.bodyBoldFont
    }

    Rectangle {
        id: mainContainer
        readonly property int padding: 1
        implicitHeight: 32 + 2 * padding
        implicitWidth: parent.width
        height: implicitHeight
        border { width: 1; color: ui.theme.strokeColor }
    }
}
