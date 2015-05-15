//
// Created by qz9n1f on 2015.05.14..
//

#include "Cylinder.h"
#include "memory.h"

Cylinder::Cylinder() {
    us.z = 1;
}

Cylinder::Cylinder(const Material _material) {
    material = ds.material = us.material = _material;
    us.z = 1;
}

bool Cylinder::_intersect(const Ray &_ray, Hit &_hit) {
    Vector E1 = _ray.eye;
    Vector V1 = _ray.v;
    Vector E = E1 * transformation.im;
    Vector V = (E1 + V1) * transformation.im;
    V = (V - E).Normalized();
    Ray tRay = Ray(E, V);
    float A = V.x * V.x + V.y * V.y;
    float B = 2 * E.x * V.x + 2 * E.y * V.y;
    float C = E.x * E.x + E.y * E.y - 1;
    float D = B * B - 4.0f * A * C;
    if (D >= 0) {
        float t1 = (-B + sqrtf(D)) / (2.0f * A);
        float t2 = (-B - sqrtf(D)) / (2.0f * A);
        Vector point1 = (tRay(t1));
        Vector point2 = (tRay(t2));
        float l1 = (point1 - Vector(0, 0, 0.5)).Length();
        float l2 = (point2 - Vector(0, 0, 0.5)).Length();
        if (l1 < 1.151 || l2 < 1.151) {
            if (t1 > 0 && t2 > 0) {
                _hit.t = t1 < t2 ? t1 : t2;
                _hit.normal = ((getNormal(tRay(_hit.t)) * transformation.im.T()).Normalized());
                _hit.point = (tRay(_hit.t)) * transformation.m;
                _hit.t = (_hit.point - E1).Length();
                _hit.object = this;
                return true;
            }
            if (t1 > 0) {
                _hit.t = t1;
                _hit.point = (tRay(_hit.t));
                _hit.point = (tRay(_hit.t)) * transformation.m;
                _hit.normal = ((getNormal(tRay(_hit.t)) * transformation.im.T()).Normalized());
                _hit.t = (_hit.point - E1).Length();
                _hit.object = this;
                return true;
            }
            if (t2 > 0) {
                _hit.t = t2;
                _hit.point = (tRay(_hit.t));
                _hit.point = (tRay(_hit.t)) * transformation.m;
                _hit.normal = ((getNormal(tRay(_hit.t)) * transformation.im.T()).Normalized());
                _hit.t = (_hit.point - E1).Length();
                _hit.object = this;
                return true;
            }
        }
    }
    return false;
}

Vector Cylinder::_getNormal(Vector const &p) {
    float x = p.x;
    float y = p.y;
    return Vector{x, y, 0}.Normalized();
}

Vector Cylinder::_param(float a, float z) {
    Vector t = Vector{cosf(a), sinf(a), z};
    return t;
}

Vector Cylinder::_paramN(Vector const &p) {
    return (p - Vector{0, 0, p.z}).Normalized();
}

std::unique_ptr<Object> Cylinder::create() {
    return make_unique<Cylinder>();
}
