#pragma once
#include "Rotation.hpp"
#include <cmath>

class QuaternionRotation : public Rotation {
public:
    double w, x, y, z;

    QuaternionRotation(double w = 1, double x = 0, double y = 0, double z = 0)
        : w(w), x(x), y(y), z(z) {}

    bool operator==(const QuaternionRotation& other) const;
};
