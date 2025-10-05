import QtQuick 2.15

import Muse.UiComponents

StyledListView {
        id: root
        objectName: "GeneralBar"

        model: ListModel {
                ListElement { name: "Align" }
                ListElement { name: "Fill & Stroke" }
        }

        delegate: Item {
                width: root.width
                height: 40

                Text {
                        text: model.name
                }
        }
}
