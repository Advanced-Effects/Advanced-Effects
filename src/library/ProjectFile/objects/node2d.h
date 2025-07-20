#pragma once

#include "node.h"

#include <QRectF>

namespace ae::library::ProjectFile::objects {

class Node2D : Node {
protected:
    Node2D() : Node() {};
    ~Node2D() = default;

public:
    float position[2];
    float rotation;

    /// The pivot is the center of reference for rotations, scaling...
    ///
    /// A pivot at (0, 0) is exactly at the center of the object
    /// A pivot at (-boundingBox/2, 0) is exactly in the left corner of the object
    /// And a pivot at (boundingBox/2, 0) is exactly in the right corner.
    float pivot[2];

    float skew[2];
    float scale[2];

    virtual void paintObjectWithSkia() = 0;

    QRectF getBoundingBox();
};

};
