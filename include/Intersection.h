#pragma once

#include "math/Vector3.h"

class Actor; // evitar da ruim na compilação

struct Intersection {
    
    float distance = -1.0f;
    cg::vec3f point;
    cg::vec3f normal;

    Actor* actor = nullptr;

    explicit operator bool() const {
        return actor != nullptr;
    }

};