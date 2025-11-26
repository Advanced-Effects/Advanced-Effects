import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15

import Muse.Ui 1.0
import Muse.UiComponents 1.0

import App.ProjectScene

StyledDialogView {
        id: root

        property int selectedWidth: 1920
        property int selectedHeight: 1080
        property int selectedFps: 30

        title: qsTrc("projectscene/newproject", "New Project")

        contentWidth: 300
        contentHeight: 320
        resizable: true

        property string currentPageId: ""
        property var params: null

        ProjectModel {
                id: projectModel
        }

        ColumnLayout  {
                anchors.fill: parent

                spacing: 0

                Column {
                        Layout.fillWidth: true
                        Layout.fillHeight: true

                        anchors {
                                fill: parent
                        }

                        spacing: 4

                        IncrementalPropertyControl {
                                id: widthField

                                currentValue: root.selectedWidth

                                step: 1
                                decimals: 1
                                maxValue: 10_000
                                minValue: 1
                        }

                        IncrementalPropertyControl {
                                id: heightField

                                currentValue: root.selectedHeight

                                step: 1
                                decimals: 0
                                maxValue: 10_000
                                minValue: 1
                        }

                        IncrementalPropertyControl {
                                id: fpsField

                                currentValue: root.selectedFps

                                step: 1
                                decimals: 0
                                maxValue: 1000
                                minValue: 1
                        }
                }

                SeparatorLine { }

                NewProjectButtonsPanel {
                        id: buttonsPanel

                        Layout.fillWidth: true
                        Layout.preferredHeight: 45

                        navigation.section: root.navigationSection
                        navigation.order: 100000

                        onRejectRequested: {
                                root.hide()
                        }

                        onCreateProjectRequested: {
                                projectModel.newProject("", root.width, root.height, root.fps)

                                root.hide()
                        }
                }
        }
}
