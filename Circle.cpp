//
// Created by qz9n1f on 2015.05.14..
//

#include "Circle.h"

Circle::Circle(const float _z) {
    z = _z;
}

Circle::Circle(const Material &_material, const float _z) {
    material = _material;
    z = _z;
}

bool Circle::_intersect(const Ray &_ray, Hit &_hit) {
    Vector E1 = _ray.eye;
    Vector V1 = _ray.v;
    Vector E = E1 * transformation.im;
    Vector V = (E1 + V1) * transformation.im;
    V = (V - E).Normalized();
    Ray tRay = Ray(E, V);
    if (tRay.v.z == 0)
        return false;
    float t = (z - E.z) / V.z;
    if (t < 0)
        return false;
    Vector p = tRay(t);
    if ((p - Vector(0, 0, z)).Length() > 1)
        return false;
    _hit.point = p * transformation.m;
    _hit.normal = (Vector(0, 0, 1) * transformation.im.T()).Normalized();
    _hit.t = (_hit.point - E1).Length();
    _hit.object = this;
    return true;
}

Vector Circle::_getNormal(Vector const &p) {
    return -p;
}

Vector Circle::_param(float a, float z = 0) {
    return Vector{z * cosf(a), z * sinf(a), 0};
}

Vector Circle::_paramN(Vector const &p) {
    return p.Normalized();
}

std::unique_ptr<Object> Circle::create() {
    return make_unique<Circle>();
}
