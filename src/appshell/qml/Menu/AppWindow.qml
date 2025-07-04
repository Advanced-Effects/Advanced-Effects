import QtQuick 2.15
import QtQuick.Controls 2.15

import AdvancedEffects
import Muse.UiComponents

// Joins a custom titlebar + the window contents
ApplicationWindow {
    visible: true
    title: "Advanced Effects v0.1-alpha"

    default property alias windowContent: windowContentItem.data
    objectName: "ApplicationWindow"

    width: 1150
    height: 800

    minimumWidth: 1050
    minimumHeight: 500

    // we show the children content here (provided by Main.qml)
    Item {
        id: windowContentItem
        anchors.fill: parent
    }
}
