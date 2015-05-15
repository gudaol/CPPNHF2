//
// Created by qz9n1f on 2015.05.14..
//

#ifndef CPPNHF2_MATRIX_H
#define CPPNHF2_MATRIX_H


struct Matrix {
    float m[4][4];

    Matrix();

    Matrix operator*(const Matrix &rhs) const;

    Matrix T();
};


#endif //CPPNHF2_MATRIX_H
