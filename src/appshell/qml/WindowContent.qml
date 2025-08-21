import QtQuick 2.15

import Muse.Dock
import Muse.Ui
import Muse.UiComponents

import "./EditPage"

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

        pages: [
                EditPage {}
        ]
}
