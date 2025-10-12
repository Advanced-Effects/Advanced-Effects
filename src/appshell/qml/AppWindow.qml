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

    // This is a strange mechanism
    // (A model, not a GUI widget)
    // to let MuseScore's framework know
    // THIS is the WINDOW to work with.
    //
    // Ignore it.
    MainWindowBridge {
            id: bridge

            window: root

            filePath: ""
            fileModified: false
    }

    Item {
        id: windowContentItem
        anchors.fill: parent
    }
}
