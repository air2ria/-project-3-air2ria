bool EulerRotation::operator==(const EulerRotation& other) const {
    return std::abs(roll - other.roll) < 0.001 &&
           std::abs(pitch - other.pitch) < 0.001 &&
           std::abs(yaw - other.yaw) < 0.001;
}
