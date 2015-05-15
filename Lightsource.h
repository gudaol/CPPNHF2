//
// Created by qz9n1f on 2015.05.14..
//

#ifndef CPPNHF2_LIGHTSOURCE_H
#define CPPNHF2_LIGHTSOURCE_H


#include "Color.h"
#include "Vector.h"

struct Lightsource {
    Color color;
    Vector pos;

    Lightsource(const Color &_color = Color{1, 1, 1}, const Vector &_pos = Vector{0, 0, 0});
};


#endif //CPPNHF2_LIGHTSOURCE_H
