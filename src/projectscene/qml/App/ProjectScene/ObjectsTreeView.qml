import QtQuick 2.15
import QtQuick.Controls 2.15

import Muse.UiComponents 1.0
import App.ProjectScene

TreeView {
        id: root
        objectName: "ObjectsTreeViewTimeline"
        anchors.fill: parent

        MockTreeModel {
                id: mockTreeModel
        }

        model: mockTreeModel // Replace with actual data.
        //delegate: TreeViewDelegate {}
}
