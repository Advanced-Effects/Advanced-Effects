import QtQuick 2.15

import Muse.UiComponents
import Muse.Dock

import "./Panels/"
import "./Toolbars/"

DockPage {
        id: root
        objectName: "Edit"
        uri: "app://edit"

        central: centralWidget

        Component {
                id: centralWidget

                CentralWidget {}
        }
}
