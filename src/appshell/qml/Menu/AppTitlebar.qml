import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15

import Muse.UiComponents

RowLayout {
    AppMenubar {
        id: menu

        Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
        Layout.preferredWidth: width
        Layout.preferredHeight: height
    }

    AppSystemButtons {
        id: systemButtons

        Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
        Layout.preferredWidth: width
        Layout.preferredHeight: height

        windowIsMiximized: root.windowVisibility === Window.Maximized

        visible: root.windowVisibility !== Window.FullScreen

        onShowWindowMinimizedRequested: {
            root.showWindowMinimizedRequested()
        }

        onToggleWindowMaximizedRequested: {
            root.toggleWindowMaximizedRequested()
        }

        onCloseWindowRequested: {
            root.closeWindowRequested()
        }
    }
}
