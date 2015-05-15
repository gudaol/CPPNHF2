#include "Object.h"


bool Object::_proc() {
    return false;
}

void Object::_transform(const Transformation &t) {
    transformation = transformation * t;
}

Object::Object() {
    transformation = Transformation{};
    material = Material{1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, Color(0, 0, 0), Color(0, 0, 0), Color(0, 0, 0), true, true};

}

bool Object::intersect(const Ray &_ray, Hit &_hit) {
    return _intersect(_ray, _hit);
}

void Object::transform(const Transformation &t) {
    _transform(t);
}

Vector Object::getNormal(Vector const &p) {
    return _getNormal(p);
}

Vector Object::param(float u, float v) {
    return _param(u, v);
}

Vector Object::paramN(const Vector &v) {
    return _paramN(v);
}

bool Object::proc() {
    return _proc();
}
