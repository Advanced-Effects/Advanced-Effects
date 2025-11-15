import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15

import Muse.Ui 1.0
import Muse.UiComponents 1.0

import App.ProjectScene

StyledDialogView {
        id: root

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

                RowLayout {
                        Layout.fillWidth: true
                        Layout.fillHeight: true

                        spacing: 0

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
                                projectModel.newProject("Scene 1", 1920, 1080, 30)

                                root.hide()
                        }
                }
        }
}
