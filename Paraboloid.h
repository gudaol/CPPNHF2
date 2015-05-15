//
// Created by qz9n1f on 2015.05.14..
//

#ifndef CPPNHF2_PARABOLOID_H
#define CPPNHF2_PARABOLOID_H


#include "Vector.h"
#include "Ray.h"
#include "Hit.h"
#include "Circle.h"

struct Paraboloid : public Object {
    float a;
    float b;
    float c;
    Circle circle;

    Paraboloid();

    Paraboloid(const Material &_material);

    virtual bool _intersect(const Ray &_ray, Hit &_hit) override;

    virtual Vector _getNormal(Vector const &p) override;

    virtual Vector _param(float a, float z) override;

    virtual Vector _paramN(Vector const &p) override;

    virtual std::unique_ptr<Object> create() override;

};

#endif //CPPNHF2_PARABOLOID_H
