import QtQuick 2.15

import Muse.Dock
import Muse.Ui
import Muse.UiComponents

import App.ProjectScene

DockWindow {
        id: root
        objectName: "WindowContent"

        onPageLoaded: {
                interactiveProvider.onPageOpened()
        }

        InteractiveProvider {
                id: interactiveProvider
                topParent: root

                onRequestedDockPage: function(uri, params) {
                        root.loadPage(uri, params)
                }
        }

        NavigationSection {
                id: topToolbarKeyNavigationSection
                name: "TopTool"
                order: 1
        }

        Component.onCompleted: {
                api.launcher.open("app://edit")
        }

        pages: [
                EditPage {}
        ]
}
