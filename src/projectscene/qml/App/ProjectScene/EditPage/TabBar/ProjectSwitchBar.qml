import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import Muse.UiComponents

import App.ProjectScene

Item {
        id: root
        height: 32

        // ! NOTE: this is not a UI widget,
        // it's only a Model that we use to retrieve DATA from C++
        ProjectModel {
                id: fileListModel
        }

        Component.onCompleted: {
                fileListModel.init();
        }

        // List of open files
        Repeater {
                id: openFilesWidget

                anchors {
                        left: root.left
                        right: rightControlsBar.left
                        top: root.top
                        bottom: root.bottom
                }

                model: fileListModel
                ProjectTab {
                        fileName: model.display
                }
        }

        // Other controls to the right of the files
        Row {
                id: rightControlsBar

                anchors {
                        right: root.right
                        top: root.top
                        bottom: root.bottom
                }

                // + button
                FlatButton {
                        id: addFileButton

                        icon: IconCode.PLUS
                        toolTipTitle: qsTrc("projectscene/tabbar", "Create New Project")
                }
        }

        // Background color
        Rectangle {
                color: ui.theme.secondaryBackgroundColor
                anchors.fill: parent.fill
                z: -1
        }
}
