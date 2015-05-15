//
// Created by qz9n1f on 2015.05.12..
//

#ifndef CPPNHF2_RAY_H
#define CPPNHF2_RAY_H

#include "Vector.h"

struct Ray {
    Vector eye;
    Vector v;

    Ray(const Vector &_eye, const Vector &_v);

    Vector operator()(float t) const;
};


#endif //CPPNHF2_RAY_H
