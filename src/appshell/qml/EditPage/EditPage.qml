import QtQuick 2.15

import Muse.UiComponents
import Muse.Dock

import "./Panels/"
import "./Toolbars/"

DockPage {
        id: root
        objectName: "Edit"
        uri: "app://edit"

        central: CentralWidget {}

        toolBars: [
                DockToolBar {
                        id: selectToolBar
                        objectName: "selectToolBar"
                        title: qsTr("appshell", "Toolbar")
                        visible: true

                        dropDestinations: [
                            root.toolBarTopDropDestination,
                            root.toolBarBottomDropDestination,
                            root.toolBarLeftDropDestination,
                            root.toolBarRightDropDestination
                        ]

                        thickness: orientation === Qt.Horizontal ? 40 : 76
                        resizable: !floating

                        ToolSelection {
                                orientation: selectToolBar.orientation
                                floating: selectToolBar.floating

                                maximumWidth: selectToolBar.maximumWidth
                                maximumHeight: selectToolBar.maximumHeight

                                navigationPanel.section: selectToolBar.navigationSection
                                navigationPanel.order: 1
                        }
                }
        ]
}
