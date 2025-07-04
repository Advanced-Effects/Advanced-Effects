import QtQuick 2.15

DockWindow {
    id: root
    objectName: "WindowContent"

    NavigationSection {
        id: topToolbarKeyNavigationSection
        name: "TopTool"
        order: 1
    }

    pages: [
        WelcomePage {},
        EditPage {},
        RenderPage {}
    ]
}
