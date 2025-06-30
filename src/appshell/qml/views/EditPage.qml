import QtQuick 2.15

// This page contains:
// - The central widget (Canvas & tabbar)
// - 3 dialogs: Properties, General, and Timeline
//
// TODO: Research how MuseScore does dialogs?
// TODO: QML OpenGL widget
EditPage {
    Column {
        Row {
            // Properties dialog

            // central widget
            Column {
                // Switch between Files
                TabBar {}
                // Canvas
                BaseCanvas {}
            }

            // General Dialog
        }

    // Timeline
    }
}