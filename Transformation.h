//
// Created by qz9n1f on 2015.05.14..
//

#ifndef CPPNHF2_TRANSFORMATION_H
#define CPPNHF2_TRANSFORMATION_H

#include "Matrix.h"
#include "Vector.h"

struct Transformation {
    Matrix m;
    Matrix im;

    Transformation();

    Transformation static trans(float x, float y, float z);

    Transformation static scale(float x, float y, float z);

    Transformation static rotateX(float alfa);

    Transformation static rotateY(float alfa);

    Transformation static rotateZ(float alfa);

    Transformation static basisR(Vector x, Vector y, Vector z);

    Transformation operator*(const Transformation &rhs) const;
};


#endif //CPPNHF2_TRANSFORMATION_H
