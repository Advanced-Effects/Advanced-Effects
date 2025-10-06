import QtQuick 2.15
import QtQuick.Controls 2.15

import Muse.UiComponents 1.0

TreeView {
        id: root
        objectName: "ObjectsTreeViewTimeline"

        anchors.fill: parent

        delegate: TreeViewDelegate {
                treeview: objectsTreeModel
        }
}
