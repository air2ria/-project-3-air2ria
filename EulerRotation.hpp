#pragma once
#include "Rotation.hpp"
#include <cmath>

class EulerRotation : public Rotation {
public:
    double roll, pitch, yaw;

    EulerRotation(double roll = 0, double pitch = 0, double yaw = 0)
        : roll(roll), pitch(pitch), yaw(yaw) {}

    bool operator==(const EulerRotation& other) const;
};
