import QtQuick 2.15

import Muse.Ui
import Muse.UiComponents

import App.AppShell

Item {
        /* === Properties === */
        id: root

        property alias orientation: gridView.orientation

        property bool floating: false

        property int maximumWidth: 0
        property int maximumHeight: 0

        width: gridView.isHorizontal ? childrenRect.width : 76
        height: !gridView.isHorizontal ? childrenRect.height : 40

        property NavigationPanel navigationPanel: NavigationPanel {
                name: "ToolSelection"
                enabled: root.enabled && root.visible
        }

        ToolSelectionModel {
                id: toolSelectionModel
        }

        Component.onCompleted: {
                toolSelectionModel.load()
        }

        // GridViewSectional is a more ergonomical way to place items in a GridView
        // Rather than placing each UI element manually in a Grid,
        // Data is extracted from a Model and rendered by each element
        // You can think of this like a .map() or a .forEach()
        GridViewSectional {
                id: gridView
                // Properties
                sectionRole: "section"

                rowSpacing: 4
                columnSpacing: 4

                cellWidth: 32
                cellHeight: cellWidth

                clip: true

                sectionDelegate: SeparatorLine {
                        orientation: gridView.orientation
                        visible: itemIndex !== 0
                }

                // From this model (muse::AbstractMenuModel)
                model: toolSelectionModel

                // Render this
                itemDelegate: FlatButton {
                        id: btn

                        readonly property QtObject item: Boolean(itemModel) ? itemModel.itemRole : null
                        readonly property bool hasMenu: Boolean(item) && item.subitems.length !== 0

                        width: gridView.cellWidth
                        height: gridView.cellWidth

                        enabled: toolSelectionModel.isInputAllowed

                        accentButton: (Boolean(item) && item.checked) || menuLoader.isMenuOpened
                        transparent: !accentButton

                        icon: Boolean(item) ? item.icon : IconCode.NONE
                        iconFont: ui.theme.toolbarIconsFont

                        toolTipTitle: Boolean(item) ? item.title : ""
                        toolTipDescription: Boolean(item) ? item.description : ""
                        toolTipShortcut: Boolean(item) ? item.shortcuts : ""

                        navigation.panel: root.navigationPanel
                        navigation.name: Boolean(item) ? item.id : ""
                        //navigation.order: Boolean(itemModel) ? itemModel.order : 0
                        isClickOnKeyNavTriggered: false
                        navigation.onTriggered: {
                                if (btn.hasMenu) {
                                        toggleMenuOpened()
                                } else {
                                        handleMenuItem()
                                }
                        }

                        function toggleMenuOpened() {
                                menuLoader.toggleOpened(item.subitems)
                        }

                        function handleMenuItem() {
                                Qt.callLater(toolSelectionModel.handleMenuItem, item.id)
                        }

                        onClicked: {
                                if (btn.hasMenu) {
                                        toggleMenuOpened()
                                } else {
                                        handleMenuItem()
                                }
                        }

                        mouseArea.onPressAndHold: function(event) {
                                if (menuLoader.isMenuOpened || !btn.hasMenu) {
                                        event.accepted = false // do not suppress the click event
                                        return
                                }

                                btn.toggleMenuOpened()
                        }

                        StyledMenuLoader {
                                id: menuLoader

                                onHandleMenuItem: function(itemId) {
                                        toolSelectionModel.handleMenuItem(itemId)
                                }
                        }
                }
        }
}
