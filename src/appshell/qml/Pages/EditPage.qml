import QtQuick 2.15

import Muse.UiComponents

// This page contains:
// - The central widget (Canvas & tabbar)
// - 3 dialogs: Properties, General, and Timeline
//
ColumnLayout {
    RowLayout {
        // Properties dialog
        PropertiesBar {}

        // central widget
        CentralWidget {}

        // General Dialog
        GeneralBar {}
    }

    // Timeline widget
    TimelineBar {}
}
