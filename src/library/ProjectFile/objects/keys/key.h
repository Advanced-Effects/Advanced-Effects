#pragma once

#include "range.h"

template<typename T>
class Key {
public:
    Key<T>(Range range) { _range = range; };
    ~Key() = default;

    T keys[_range];

    Range _range;
};
