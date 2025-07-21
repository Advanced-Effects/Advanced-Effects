import QtQuick 2.15

import Muse.Ui
import Muse.UiComponents
import Muse.DockWindow

DockWindow {
    id: root
    objectName: "WindowContent"

    toolbars: [
        Topbar {}
    ]

    panels: [
        GeneralBar {},
        TimelineBar {}
    ]

    central: CentralWidget {}
}
