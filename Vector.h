//
// Created by qz9n1f on 2015.05.14..
//

#ifndef CPPNHF2_VECTOR_H
#define CPPNHF2_VECTOR_H


#include "Matrix.h"
#include <cmath>

struct Vector {
    float x, y, z;

    Vector();

    Vector(const float x0, const float y0, const float z0);

    Vector operator*(const float a) const;

    Vector operator/(const float a) const;

    Vector operator+(const Vector &v) const;

    Vector operator-(const Vector &v) const;

    Vector operator-() const;

    float operator*(const Vector &v) const;

    float &operator[](const int i);

    Vector operator%(const Vector &v) const;

    float Length() const;

    Vector Normalized() const;

    Vector gimmeOrtogonal() const;

    Vector operator*(const Matrix &rhs);
};

Vector operator*(const float a, const Vector &rhs);

#endif //CPPNHF2_VECTOR_H
