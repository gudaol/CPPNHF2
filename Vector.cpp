//
// Created by qz9n1f on 2015.05.14..
//

#include <stdexcept>
#include "Vector.h"


Vector::Vector() {
    x = y = z = 0;
}

Vector::Vector(const float x0, const float y0, const float z0) {
    x = x0;
    y = y0;
    z = z0;
}

Vector Vector::operator*(const float a) const {
    return Vector{x * a, y * a, z * a};
}

Vector Vector::operator/(const float a) const {
    return Vector{x / a, y / a, z / a};
}

Vector Vector::operator+(const Vector &v) const {
    return Vector{x + v.x, y + v.y, z + v.z};
}

Vector Vector::operator-(const Vector &v) const {
    return Vector{x - v.x, y - v.y, z - v.z};
}

Vector Vector::operator-() const {
    return Vector{-x, -y, -z};
}

float Vector::operator*(const Vector &v) const {
    return (x * v.x + y * v.y + z * v.z);
}

float &Vector::operator[](const int i) {
    switch (i) {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        default:
            throw std::out_of_range{"Nincs ilyen adattag a vektorban"};
    }
}

Vector Vector::operator%(const Vector &v) const {
    return Vector{y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x};
}

float Vector::Length() const {
    return std::sqrt(x * x + y * y + z * z);
}

Vector Vector::Normalized() const {
    return *this / Length();
}

Vector Vector::gimmeOrtogonal() const {
    return Vector{-y, x, 0}.Normalized();
}

Vector Vector::operator*(const Matrix &rhs) {
    Vector ret;
    ret.x = x * rhs.m[0][0] + y * rhs.m[1][0] + z * rhs.m[2][0] + rhs.m[3][0];
    ret.y = x * rhs.m[0][1] + y * rhs.m[1][1] + z * rhs.m[2][1] + rhs.m[3][1];
    ret.z = x * rhs.m[0][2] + y * rhs.m[1][2] + z * rhs.m[2][2] + rhs.m[3][2];
    return ret;
}


Vector operator*(const float a, const Vector &rhs) {
    return Vector{rhs.x * a, rhs.y * a, rhs.z * a};
}