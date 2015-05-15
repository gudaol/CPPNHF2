//
// Created by qz9n1f on 2015.05.14..
//

#ifndef CPPNHF2_CAMERA_H
#define CPPNHF2_CAMERA_H


#include "Vector.h"
#include "Ray.h"
#include "Screen.h"

struct Camera {
    Vector eye, lookat, up, right;

    Camera(const Vector &_eye = Vector{}, const Vector &_lookat = Vector{}, const Vector &_up = Vector{}, const Vector &_right = Vector{});

    Ray getRay(const int x, const int y) const;

    float ex(void);

    float ey(void);

    float ez(void);

    void update(float, float);

    /**
     * Distance from origo.
     */
    float distance;
    /**
     * Polar coordinates of camera.
     */
    float B, L;
};


#endif //CPPNHF2_CAMERA_H
