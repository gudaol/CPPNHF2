//
// Created by qz9n1f on 2015.05.12..
//

#ifndef CPPNHF2_HIT_H
#define CPPNHF2_HIT_H

#include "Ray.h"

struct Object;

struct Hit {
    Vector point;
    Vector normal;
    float t;
    Object *object;

    Hit();
};


#endif //CPPNHF2_HIT_H
