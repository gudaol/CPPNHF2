//
// Created by qz9n1f on 2015.05.14..
//

#include "Paraboloid.h"
#include "memory.h"

Paraboloid::Paraboloid() {
    a = 1;
    b = 1;
    c = 1;
    circle.z = 1;
}

Paraboloid::Paraboloid(const Material &_material) {
    material = _material;
    a = 1;
    b = 1;
    c = 1;
    circle.material = _material;
    circle.z = 1;
}


bool Paraboloid::_intersect(const Ray &_ray, Hit &_hit) {
    Vector E1 = _ray.eye;
    Vector V1 = _ray.v;
    Vector E = E1 * transformation.im;
    Vector V = (E1 + V1) * transformation.im;
    V = (V - E).Normalized();
    Ray tRay = Ray(E, V);
    float A = c / (a * a) * (V.x * V.x) + c / (b * b) * (V.y * V.y);
    float B = -V.z + c / (a * a) * 2 * E.x * V.x + c / (b * b) * 2 * E.y * V.y;
    float C = -E.z + c / (a * a) * E.x * E.x + c / (b * b) * E.y * E.y;
    float D = B * B - 4.0f * A * C;
    if (D >= 0) {
        float t1 = (-B + std::sqrt(D)) / (2.0f * A);
        float t2 = (-B - std::sqrt(D)) / (2.0f * A);
        Vector point1 = (tRay(t1));
        Vector point2 = (tRay(t2));
        float l1 = (point1).Length();
        float l2 = (point2).Length();
        if ((l1 < 1.41 || l2 < 1.41)) {
            if (t1 > 0 || t2 > 0) {
                _hit.t = t1 < t2 ? t1 : t2;
                _hit.normal = ((_getNormal(tRay(_hit.t)) * transformation.im.T()).Normalized());
                _hit.point = (tRay(_hit.t)) * transformation.m;
                _hit.t = (_hit.point - E1).Length();
                _hit.object = this;
                return true;
            }
            if (t1 > 0) {
                _hit.t = t1;
                _hit.point = (tRay(_hit.t));
                _hit.point = (tRay(_hit.t)) * transformation.m;
                _hit.normal = ((_getNormal(tRay(_hit.t)) * transformation.im.T()).Normalized());
                _hit.t = (_hit.point - E1).Length();
                _hit.object = this;
                return true;
            }
            if (t2 > 0) {
                _hit.t = t2;
                _hit.point = (tRay(_hit.t));
                _hit.point = (tRay(_hit.t)) * transformation.m;
                _hit.normal = ((_getNormal(tRay(_hit.t)) * transformation.im.T()).Normalized());
                _hit.t = (_hit.point - E1).Length();
                _hit.object = this;
                return true;
            }
        }
    }
    return false;
}

Vector Paraboloid::_param(float a, float z) {
    return {a * cosf(z), a * sinf(z), z};

}

Vector Paraboloid::_paramN(Vector const &p) {
    return Vector{2 * p.x, 2 * p.y, -1}.Normalized();
}

Vector Paraboloid::_getNormal(Vector const &p) {
    float x = p.x;
    float y = p.y;
    return Vector{2.0f * x / (a * a), 2.0f * y / (b * b), -1.0f / c};
}

std::unique_ptr<Object> Paraboloid::create() {
    return make_unique<Paraboloid>();
}
