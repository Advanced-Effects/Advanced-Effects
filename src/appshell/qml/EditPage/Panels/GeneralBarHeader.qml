import QtQuick 2.8
import QtQuick.Controls 2.1

import Muse.UiComponents 1.0
import Muse.Ui 1.0

Item {
    id: root

    width: parent.width
    height: 40 + (root.expanded ? loader.implicitHeight : 0)

    property bool expanded: false
    property bool hovered: false

    property string headerTitle: ""
    // The QtQuick component to render when widget is expanded
    property Component component: null

    function toggleExpandRequested() {
            root.expanded = !root.expanded
    }

    FlatButton {
        id: paletteExpandArrow

        z: 1000
        width: height
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

    // Clicking any part of the widget - not just the arrow button - should trigger a toggle.
    MouseArea {
            anchors.fill: parent

            onClicked: root.toggleExpandRequested()
    }

    StyledTextLabel {
        id: textItem

        z: 999

        width: root.width
        height: 32

        horizontalAlignment: Text.AlignHLeft
        anchors {
            left: paletteExpandArrow.right; leftMargin: 4;
            right: root.right
            top: root.top
            bottom: root.bottom
        }

        text: root.headerTitle
        font: ui.theme.bodyBoldFont
    }

    // This rectangle makes the widget have a greyish background
    Rectangle {
        id: mainContainer

        readonly property int padding: 1
        implicitHeight: 32 +
        (root.expanded ? loader.implicitHeight : 0)
        + 2 * padding
        implicitWidth: parent.width
        height: implicitHeight

        color: root.hovered ? ui.theme.strokeColor : ui.theme.backgroundColor
        border { width: 1; color: ui.theme.strokeColor }
    }

    // Shows the `component` dynamically
    Loader {
            id: loader
            sourceComponent: root.component

            visible: root.expanded

            anchors.top: textItem.bottom
            anchors.left: root.left
            anchors.right: root.right
            anchors.bottom: root.bottom

            z: 999
        }
}
