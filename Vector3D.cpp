bool Vector3D::operator==(const Vector3D& other) const {
    return std::abs(x - other.x) < 0.001 &&
           std::abs(y - other.y) < 0.001 &&
           std::abs(z - other.z) < 0.001;
}
