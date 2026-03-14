bool QuaternionRotation::operator==(const QuaternionRotation& other) const {
    return std::abs(w - other.w) < 0.001 &&
           std::abs(x - other.x) < 0.001 &&
           std::abs(y - other.y) < 0.001 &&
           std::abs(z - other.z) < 0.001;
}
