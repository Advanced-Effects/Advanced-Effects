import QtQuick 2.15
import QtQuick.Controls 2.15

import Muse.Ui 1.0

ApplicationWindow {
    id: root

    default property alias windowContent: windowContentItem.data

    objectName: "ApplicationWindow"

    width: 1150
    height: 800

    minimumWidth: 1050
    minimumHeight: 500

    color: ui.theme.backgroundPrimaryColor

    signal showWindowMinimizedRequested()
    signal toggleWindowMaximizedRequested()
    signal closeWindowRequested()

    Item {
        id: windowContentItem
        anchors.fill: parent
    }
}
