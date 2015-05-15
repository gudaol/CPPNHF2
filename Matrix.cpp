//
// Created by qz9n1f on 2015.05.14..
//

#include "Matrix.h"

Matrix::Matrix() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (i == j)
                m[i][j] = 1;
            else m[i][j] = 0;
}

Matrix Matrix::operator*(const Matrix &rhs) const {
    Matrix ret;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            float t = 0;
            for (int k = 0; k < 4; k++)
                t += this->m[k][i] * rhs.m[j][k];
            ret.m[j][i] = t;
        }
    return ret;
}

Matrix Matrix::T() {
    Matrix transponed;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            transponed.m[i][j] = this->m[j][i];
    return transponed;
}