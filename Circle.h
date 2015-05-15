//
// Created by qz9n1f on 2015.05.14..
//

#ifndef CPPNHF2_CIRCLE_H
#define CPPNHF2_CIRCLE_H


#include "Object.h"

struct Circle : public Object {
    float z;

    Circle(const float _z = 0);

    Circle(const Material &_material, const float _z = 0);

    virtual bool _intersect(const Ray &_ray, Hit &_hit) override;

    virtual Vector _getNormal(Vector const &p) override;

    virtual Vector _param(float a, float z) override;

    virtual Vector _paramN(Vector const &p) override;

    virtual std::unique_ptr<Object> create() override;
};


#endif //CPPNHF2_CIRCLE_H
