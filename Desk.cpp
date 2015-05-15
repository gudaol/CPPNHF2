//
// Created by qz9n1f on 2015.05.14..
//

#include "Desk.h"

Desk::Desk(const Material &_material, const float _X1, const float _X2, const float _Y1, const float _Y2) {
    material = _material;
    X1 = _X1;
    X2 = _X2;
    Y1 = _Y1;
    Y2 = _Y2;
}

bool Desk::_intersect(const Ray &_ray, Hit &_hit) {
    Ray tRay = _ray;
    Vector E = tRay.eye;
    Vector V = tRay.v;
    if (tRay.v.z == 0)
        return false;
    float t = -E.z / V.z;
    if (t < 0)
        return false;
    Vector p = tRay(t);
    if ((p.x < X1) || (p.x > X2) || (p.y < Y1) || (p.y > Y2))
        return false;
    _hit.point = (tRay(t));
    _hit.normal = Vector(0, 0, 1);
    _hit.t = t;
    _hit.object = this;
    return true;
}

bool Desk::_proc() {
    return true;
}

Vector Desk::_getNormal(Vector const &p) {
    return Vector{1, 0, 0};
}

Vector Desk::_param(float a, float z) {
    return Vector{1, 0, 0};
}

Vector Desk::_paramN(Vector const &p) {
    return Vector{1, 0, 0};
}

std::unique_ptr<Object> Desk::create() {
    return make_unique<Desk>();
}
