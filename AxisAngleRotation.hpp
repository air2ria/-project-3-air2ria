#pragma once
#include "Rotation.hpp"
#include "Vector3D.hpp"
#include <cmath>

class AxisAngleRotation : public Rotation {
public:
    Vector3D axis;
    double angle;

    AxisAngleRotation(Vector3D axis = Vector3D(), double angle = 0)
        : axis(axis), angle(angle) {}

    Vector3D getAxis() const { return axis; }

    bool operator==(const AxisAngleRotation& other) const;
};
