import QtQuick 2.15
import QtQuick.Layouts 1.15

import Muse.Ui 1.0
import Muse.UiComponents 1.0

Rectangle {
    id: root

    color: ui.theme.backgroundPrimaryColor

    property alias navigation: buttonBox.navigationPanel

    signal createProjectRequested()
    signal rejectRequested()

    ButtonBox {
        id: buttonBox

        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.margins: 10

        buttons: [ ButtonBoxModel.Cancel, ButtonBoxModel.Ok ]

        onStandardButtonClicked: function(buttonId) {
            if (buttonId === ButtonBoxModel.Cancel) {
                root.rejectRequested()
            } else if (buttonId === ButtonBoxModel.Ok) {
                root.createProjectRequested()
            }
        }
    }
}
