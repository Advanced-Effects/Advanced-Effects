import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15

import Muse.Ui 1.0
import Muse.UiComponents 1.0

StyledDialogView {
        id: root

        title: qsTrc("projectscene/newproject", "New Project")

        contentWidth: 300
        contentHeight: 320
        resizable: true

        property string currentPageId: ""
        property var params: null

        ColumnLayout  {
                anchors.fill: parent

                spacing: 0

                RowLayout {
                        Layout.fillWidth: true
                        Layout.fillHeight: true

                        spacing: 0

                        /*PreferencesMenu {
                                id: menu
                        }

                        SeparatorLine { orientation: Qt.Vertical }

                        StackLayout {
                                id: stack
                                }*/
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

                        onCreateProjectRequested: {}
                }
        }
}
