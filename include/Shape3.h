#pragma once

#include "geometry/Ray.h"
#include "Intersection.h"

class Shape3 {

public:

    virtual ~Shape3() = default;

    virtual Intersection intersect(cg::Ray3f& ray, cg::mat4f& transform) = 0;

};