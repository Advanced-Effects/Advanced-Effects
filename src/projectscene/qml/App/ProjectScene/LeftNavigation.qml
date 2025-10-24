import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
        id: root
        objectName: "LeftNavigationTimeline"

        QuickActions {
                id: quickActions

                anchors {
                        top: root.top
                        left: root.left
                        right: root.right
                }

                z: 100
        }

        ObjectsTreeView {
                id: objectsTreeView

                anchors {
                        left: root.left
                        right: root.right
                        top: objectsTreeView.bottom
                        bottom: root.bottom
                }
        }
}
