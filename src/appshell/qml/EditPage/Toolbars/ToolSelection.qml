import QtQuick 2.15

import Muse.Ui
import Muse.UiComponents

import App.AppShell

StyledToolBarView {
        navigationPanel.name: "ToolSelectionBar"
        navigationPanel.accessible.name: qsTrc("toolbar", "Tool Selection bar")

        spacing: 2

        model: ToolBarModel { }
}
