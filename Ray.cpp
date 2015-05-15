#include "Ray.h"


Ray::Ray(const Vector &_eye, const Vector &_v) {
    eye = _eye;
    v = _v.Normalized();
}

Vector Ray::operator()(float t) const {
    return (eye + v * t);
}


