#pragma once

#include <string>
#include <vector>

namespace ae::library::ProjectFile::objects {

/// Node is the base element in the object hierarchy
///
///
/// What is a "Node"?
///
/// A Node represents anything that can be put in the project (in the Timeline treeview). It represents the most elemental properties of any object (2d, 3d, whatever): it has a name, children and a parent, and whether the object is visible or locked.
/// Since Node can represent any object, it still doesn't have properties like position, scale (to allow for Node3D objects to exist in the future)
///
///
/// Why does Node descend from ProjectFileTrait?
///
/// A Node is EXPECTED to be exportable to the project file format,
/// that's why it inherits from IProjectFile
/// Although the implementation is left to individual objects
class Node : ProjectFileTrait {
protected:
    /// Node can't be summoned by itself, instead
    /// it's used as a blueprint by other classes
    Node();
    ~Node() = default;

public:
    /// Elemental properties
    std::string name;
    bool isVisible;
    bool isLocked;

    /// Children and parent
    std::vector<Node> children;
    Node* parent;
};

};
