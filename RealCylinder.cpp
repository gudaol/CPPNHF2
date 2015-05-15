//
// Created by qz9n1f on 2015.05.14..
//

#include "RealCylinder.h"
#include "Settings.h"

RealCylinder::RealCylinder() {
    p.material = p.ds.material = p.us.material = Materials::glass();
    objects[0] = &p;
    objects[1] = &p.ds;
    objects[2] = &p.us;
}

RealCylinder::RealCylinder(const Material &_material) {
    p.material = p.ds.material = p.us.material = _material;
    objects[0] = &p;
    objects[1] = &p.ds;
    objects[2] = &p.us;

}

bool RealCylinder::_intersect(const Ray &_ray, Hit &_hit) {
    float tmax = Settings::distance;
    Hit realhit;
    for (int i = 0; i < 3; i++) {
        if (objects[i]->intersect(_ray, _hit)) {
            if (_hit.t > 0 && _hit.t < tmax) {
                tmax = _hit.t;
                realhit = _hit;
            }
        }
    }
    if (tmax < Settings::distance) {
        _hit = realhit;
        return true;
    }
    return false;
}

void RealCylinder::_transform(const Transformation &t) {
    transformation = transformation * t;
    p.ds.transformation = p.ds.transformation * t;
    p.us.transformation = p.us.transformation * t;
    p.transformation = p.transformation * t;
}

Vector RealCylinder::_getNormal(Vector const &p) {
    float x = p.x;
    float y = p.y;
    return Vector{x, y, 0}.Normalized();
}

Vector  RealCylinder::_param(float a, float z) {
    return {cosf(a), sinf(a), z};
}

Vector  RealCylinder::_paramN(Vector const &p) {
    return (p - Vector(0, 0, p.z)).Normalized();
}

std::unique_ptr<Object> RealCylinder::create() {
    return make_unique<RealCylinder>();
}
