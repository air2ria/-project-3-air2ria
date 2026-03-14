#include "AxisAngleRotation.hpp"

bool AxisAngleRotation::operator==(const AxisAngleRotation& other) const {
    return axis == other.axis &&
           std::abs(angle - other.angle) < 0.001;
}
