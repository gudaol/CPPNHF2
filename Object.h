//
// Created by qz9n1f on 2015.05.12..
//

#ifndef CPPNHF2_OBJECT_H
#define CPPNHF2_OBJECT_H

#include "Material.h"
#include "Transformation.h"
#include "Hit.h"
#include <memory>
#include "memory.h"


struct Object {
    Transformation transformation;
    Material material;

    Object();


    /**
     * Intersecting function. Can be anything from a quadratic surface equation to 3 billion triangle intersection
     */
    bool intersect(const Ray &, Hit &);

    /**
     * Sometimes (when you have more objects in a wrapper object (e.g.: RealCylinder)) you must override the default implementation
     */
    void transform(const Transformation &);

    /**
     * Returns the surface normal of the transformated object in the Vector given point.
     */
    Vector getNormal(Vector const &);

    /**
     * Returns a Vector pointing to the parametrized coordinate on the unit-object.
     */
    Vector param(float, float);

    /**
     * Returns a Vector directioned as the surface normal of the unit-object.
     */
    Vector paramN(Vector const &);

    /**
    * Is the object procedurally textured?
    */
    bool proc();

    virtual std::unique_ptr<Object> create() = 0;

private:

    virtual bool _intersect(const Ray &, Hit &) = 0;

    virtual void _transform(const Transformation &);

    virtual bool _proc();

    virtual Vector _getNormal(Vector const &) = 0;

    virtual Vector _param(float, float) = 0;

    virtual Vector _paramN(Vector const &) = 0;

};

#endif //CPPNHF2_OBJECT_H
