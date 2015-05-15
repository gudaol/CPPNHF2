//
// Created by qz9n1f on 2015.05.14..
//

#include "RealParaboloid.h"
#include "Settings.h"

RealParaboloid::RealParaboloid() {
    p.material = p.circle.material = Materials::silver();
    objects[0] = &p;
    objects[1] = &p.circle;
}

RealParaboloid::RealParaboloid(const Material &_material) {
    p.material = p.circle.material = _material;
    objects[0] = &p;
    objects[1] = &p.circle;

}

bool RealParaboloid::_intersect(const Ray &_ray, Hit &_hit) {
    float tmax = Settings::distance;
    Hit realhit;
    for (int i = 0; i < 2; i++) {
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

void RealParaboloid::_transform(const Transformation &t) {
    transformation = transformation * t;
    p.transformation = p.transformation * t;
    p.circle.transformation = p.circle.transformation * t;
}

Vector RealParaboloid::_param(float u, float v) {
    return {u * cosf(v), v * sinf(v), u};
}

Vector RealParaboloid::_paramN(Vector const &p) {
    return Vector{2 * p.x, 2 * p.y, -1}.Normalized();
}

Vector RealParaboloid::_getNormal(Vector const &p) {
    float x = p.x;
    float y = p.y;
    return Vector{2 * x / (this->p.a * this->p.a), 2 * y / (this->p.b * this->p.b), -1 / this->p.c};
}

std::unique_ptr<Object> RealParaboloid::create() {
    return make_unique<RealParaboloid>();
}
