#include "RotationRegistry.hpp"

RotationRegistry::RotationRegistry() : ArrayBag<Rotation*>() {}

bool RotationRegistry::addRotation(Rotation* rotation) {
    return add(rotation);
}

int RotationRegistry::countQuaternions() const {
    int count = 0;
    std::vector<Rotation*> items = toVector();
    for (Rotation* r : items) {
        if (dynamic_cast<QuaternionRotation*>(r)) count++;
    }
    return count;
}

double RotationRegistry::getAverageMagnitude() const {
    std::vector<Rotation*> items = toVector();
    double total = 0.0;
    int count = 0;
    for (Rotation* r : items) {
        AxisAngleRotation* aar = dynamic_cast<AxisAngleRotation*>(r);
        if (aar) {
            total += aar->getAxis().magnitude(); 
            count++;
        }
    }
    return count == 0 ? 0.0 : total / count;
}
