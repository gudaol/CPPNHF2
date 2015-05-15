//
// Created by qz9n1f on 2015.05.14..
//

#ifndef CPPNHF2_REALCYLINDER_H
#define CPPNHF2_REALCYLINDER_H

#include "Screen.h"
#include "Ray.h"
#include "Material.h"
#include "Cylinder.h"

struct RealCylinder : public Object {
    Object *objects[3];
    Cylinder p;

    RealCylinder();

    RealCylinder(const Material &_material);

    virtual bool _intersect(const Ray &_ray, Hit &_hit) override;

    virtual void _transform(const Transformation &t) override;

    virtual Vector _getNormal(Vector const &p) override;

    virtual Vector _param(float a, float z) override;

    virtual Vector _paramN(Vector const &p) override;

    virtual std::unique_ptr<Object> create() override;
};


#endif //CPPNHF2_REALCYLINDER_H
