//
// Created by qz9n1f on 2015.05.14..
//

#ifndef CPPNHF2_DESK_H
#define CPPNHF2_DESK_H


#include "Object.h"
#include "Settings.h"

struct Desk : public Object {
    float X1, X2, Y1, Y2;

    Desk(const Material &_material = Settings::material.blinn(), const float _X1 = 10.0f, const float _X2 = -10.0f, const float _Y1 = 10.0f,
         const float _Y2 = -10.0f);

    virtual bool _intersect(const Ray &_ray, Hit &_hit) override;

    virtual bool _proc() override;

    virtual Vector _getNormal(Vector const &p) override;

    virtual Vector _param(float a, float z) override;

    virtual Vector _paramN(Vector const &p) override;

    virtual std::unique_ptr<Object> create() override;
};

#endif //CPPNHF2_DESK_H
