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
                width: parent.width
                height: 40

                GeneralBarHeader {
                        text: model.name
                        //component: model.component
                }
        }
}
