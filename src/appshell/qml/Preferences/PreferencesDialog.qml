import QtQuick 2.15
import QtQuick.Controls 2.15

import Muse.Ui 1.0
import Muse.UiComponents 1.0
import App.Preferences 1.0

import "internal"

StyledDialogView {
        id: root

        title: qsTrc("appshell/preferences", "Preferences")

        contentWidth: 880
        contentHeight: 640
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

                        PreferencesMenu {
                                id: menu
                        }

                        SeparatorLine { orientation: Qt.Vertical }

                        StackLayout {
                                id: stack
                        }
                }

                SeparatorLine { }

                PreferencesButtonsPanel {
                        id: buttonsPanel

                        Layout.fillWidth: true
                        Layout.preferredHeight: 70

                        navigation.section: root.navigationSection
                        navigation.order: 100000

                        onRevertFactorySettingsRequested: {}

                        onRejectRequested: {}

                        onApplyRequested: {}
                }
        }
}
