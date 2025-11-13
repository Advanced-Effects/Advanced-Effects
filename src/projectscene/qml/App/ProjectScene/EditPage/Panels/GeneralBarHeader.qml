import QtQuick 2.8
import QtQuick.Controls 2.1

import Muse.UiComponents 1.0
import Muse.Ui 1.0

Control {
    id: root

    property bool expanded: false

    property string headerTitle: ""
    // The QtQuick component to render when widget is expanded
    property Component component: null

    function toggleExpandRequested() {
            root.expanded = !root.expanded
    }

    // The size that the text and FlatButtons occupy
    property int headerHeight: 40
    // The size that the Component occupies
    property int loaderHeight: root.expanded ? loader.implicitHeight : 0
    width: parent.width
    height: headerHeight + loaderHeight

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
        }

        text: root.headerTitle
        font: ui.theme.bodyBoldFont
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

        // This rectangle makes the widget have a greyish background
        Rectangle {
            id: mainContainer

            readonly property int padding: 1
            implicitHeight: 32 +
            (root.expanded ? loader.implicitHeight : 0)
            + 2 * padding
            implicitWidth: parent.width
            height: implicitHeight

            color: (root.hovered ? ui.theme.strokeColor : ui.theme.backgroundPrimaryColor)
        }

        // Input detection
        MouseArea {
                anchors.fill: parent

                // Clicking any part of the widget - not just the arrow button - should trigger a toggle.
                onClicked: root.toggleExpandRequested()
        }

        // Use Transitions to make the triggering animation smoother
        state: root.expanded ? "expanded" : "collapsed"

        property bool enableAnimations: true // !!! NOTE Set this programmatically (accessibility settings)
        property int expandDuration: 150

        states: [
            State {
                name: "collapsed"
                PropertyChanges { target: loader; visible: false; restoreEntryValues: false }
            },
            State {
                name: "expanded"
                PropertyChanges { target: loader; visible: true; restoreEntryValues: false }
            }
        ]

        transitions: [
            Transition {
                from: "collapsed"; to: "expanded"
                enabled: root.enableAnimations
                NumberAnimation {
                        target: root; property: "height";
                        from: headerHeight; to: headerHeight + loaderHeight;
                        easing.type: Easing.OutCubic;
                        duration: root.expandDuration
                }
            },
            Transition {
                from: "expanded"; to: "collapsed"
                enabled: root.enableAnimations
                SequentialAnimation {
                    PropertyAction { target: loader; property: "visible"; value: true } // temporarily set palette visible to animate it being hidden
                    NumberAnimation {
                            target: root; property: "height";
                            from: headerHeight + loaderHeight; to: headerHeight;
                            easing.type: Easing.OutCubic;
                            duration: root.expandDuration
                    }
                    PropertyAction { target: loader; property: "visible"; value: false } // make palette invisible again
                }
            }
        ]
}
