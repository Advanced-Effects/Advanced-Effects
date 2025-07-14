import QtQuick 2.15

import Muse.UiComponents

Column {
    id: root

    SelectToolBar {
        anchors.left: root.left
    }
    QuickAccessBar {
        anchors.right: root.right
    }
}
