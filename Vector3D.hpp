#pragma once
#include <cmath>

class Vector3D {
public:
    double x, y, z;

    Vector3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

    double magnitude() const {
        return std::sqrt(x*x + y*y + z*z);
    }

    bool operator==(const Vector3D& other) const;
};
