//
// Created by qz9n1f on 2015.05.14..
//

#include "Sphere.h"
#include "Materials.h"


Sphere::Sphere(const Material &_material) {
    material = _material;
    C = Vector(0, 0, 1);
}

Sphere::Sphere() {
    material = Materials::gold();
    C = Vector(0, 0, 1);
}

bool Sphere::_intersect(const Ray &_ray, Hit &_hit) {
    Vector E1 = _ray.eye;
    Vector V1 = _ray.v;
    Vector E = E1 * transformation.im;
    Vector V = (E1 + V1) * transformation.im;
    V = (V - E).Normalized();
    Ray tRay = Ray(E, V);
    float a = V * V;
    float b = 2.0f * (E - C) * V;
    float c = ((E - C) * (E - C)) - 1;
    float D = b * b - 4.0f * a * c;
    if (D >= 0) {
        float t1 = (-b + sqrtf(D)) / (2.0f * a);
        float t2 = (-b - sqrtf(D)) / (2.0f * a);
        if (t1 > 0 && t2 > 0) {
            _hit.t = t1 < t2 ? t1 : t2;
            _hit.point = (tRay(_hit.t)) * transformation.m;
            _hit.normal = ((tRay(_hit.t) - C) * transformation.im.T()).Normalized();
            _hit.t = (_hit.point - E1).Length();
            _hit.object = this;
            return true;
        }
        if (t1 > 0) {
            _hit.t = t1;
            _hit.point = (tRay(_hit.t)) * transformation.m;
            _hit.normal = ((tRay(_hit.t) - C) * transformation.im.T()).Normalized();
            _hit.t = (_hit.point - E1).Length();
            _hit.object = this;
            return true;
        }
        if (t2 > 0) {
            _hit.t = t2;
            _hit.point = (tRay(_hit.t)) * transformation.m;
            _hit.normal = ((tRay(_hit.t) - C) * transformation.im.T()).Normalized();
            _hit.t = (_hit.point - E1).Length();
            _hit.object = this;
            return true;
        }
    }
    return false;
}

Vector Sphere::_param(float a, float b) {
    Vector t = Vector(cosf(a) * sinf(b), sinf(a) * sinf(b), cosf(b));
    t = t * Transformation::trans(0, 0, 1).m;
    return t;
}

Vector Sphere::_paramN(Vector const &p) {
    return (p - Vector(0, 0, 1)).Normalized();
}

Vector Sphere::_getNormal(Vector const &p) {
    return Vector();
}

std::unique_ptr<Object> Sphere::create() {
    return make_unique<Sphere>();
}
