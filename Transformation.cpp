//
// Created by qz9n1f on 2015.05.14..
//

#include "Transformation.h"

Transformation::Transformation() {
}

Transformation Transformation::trans(float x, float y, float z) {
    Transformation trans;
    trans.m.m[3][0] = x;
    trans.m.m[3][1] = y;
    trans.m.m[3][2] = z;
    trans.im.m[3][0] = -x;
    trans.im.m[3][1] = -y;
    trans.im.m[3][2] = -z;
    return trans;
}

Transformation Transformation::scale(float x, float y, float z) {
    Transformation scale;
    scale.m.m[0][0] = x;
    scale.m.m[1][1] = y;
    scale.m.m[2][2] = z;
    scale.im.m[0][0] = 1 / x;
    scale.im.m[1][1] = 1 / y;
    scale.im.m[2][2] = 1 / z;
    return scale;
}

Transformation Transformation::rotateX(float alfa) {
    Transformation ret;
    float sina = sinf((alfa / 180.0f) * 3.1415);
    float cosa = cosf((alfa / 180.0f) * 3.1415);
    ret.m.m[1][1] = cosa;
    ret.m.m[1][2] = -sina;
    ret.m.m[2][1] = sina;
    ret.m.m[2][2] = cosa;
    ret.im = ret.m.T();
    return ret;
}

Transformation Transformation::rotateY(float alfa) {
    Transformation ret;
    float sina = sinf((alfa / 180.0f) * 3.1415);
    float cosa = cosf((alfa / 180.0f) * 3.1415);
    ret.m.m[0][0] = cosa;
    ret.m.m[0][2] = sina;
    ret.m.m[2][0] = -sina;
    ret.m.m[2][2] = cosa;
    ret.im = ret.m.T();
    return ret;
}

Transformation Transformation::rotateZ(float alfa) {
    Transformation ret;
    float sina = sinf((alfa / 180.0f) * 3.1415);
    float cosa = cosf((alfa / 180.0f) * 3.1415);
    ret.m.m[0][0] = cosa;
    ret.m.m[0][1] = -sina;
    ret.m.m[1][0] = sina;
    ret.m.m[1][1] = cosa;
    ret.im = ret.m.T();
    return ret;
}

Transformation Transformation::basisR(Vector x, Vector y, Vector z) {
    Transformation ret;
    float a, b, c, d, e, f, g, h, i;
    a = x.x;
    b = y.x;
    c = z.x;
    d = x.y;
    e = y.y;
    f = z.y;
    g = x.z;
    h = y.z;
    i = z.z;
    ret.m.m[0][0] = a;
    ret.m.m[0][1] = b;
    ret.m.m[0][2] = c;
    ret.m.m[1][0] = d;
    ret.m.m[1][1] = e;
    ret.m.m[1][2] = f;
    ret.m.m[2][0] = g;
    ret.m.m[2][1] = h;
    ret.m.m[2][2] = i;
    ret.im.m[0][0] = (f * h - e * i) / (c * e * g - b * f * g - c * d * h + a * f * h + b * d * i - a * e * i);
    ret.im.m[0][1] = (c * h - b * i) / (-c * e * g + b * f * g + c * d * h - a * f * h - b * d * i + a * e * i);
    ret.im.m[0][2] = (c * e - b * f) / (c * e * g - b * f * g - c * d * h + a * f * h + b * d * i - a * e * i);
    ret.im.m[1][0] = (f * g - d * i) / (-c * e * g + b * f * g + c * d * h - a * f * h - b * d * i + a * e * i);
    ret.im.m[1][1] = (c * g - a * i) / (c * e * g - b * f * g - c * d * h + a * f * h + b * d * i - a * e * i);
    ret.im.m[1][2] = (c * d - a * f) / (-c * e * g + b * f * g + c * d * h - a * f * h - b * d * i + a * e * i);
    ret.im.m[2][0] = (e * g - d * h) / (c * e * g - b * f * g - c * d * h + a * f * h + b * d * i - a * e * i);
    ret.im.m[2][1] = (b * g - a * h) / (-c * e * g + b * f * g + c * d * h - a * f * h - b * d * i + a * e * i);
    ret.im.m[2][2] = (b * d - a * e) / (c * e * g - b * f * g - c * d * h + a * f * h + b * d * i - a * e * i);
    return ret;
}

Transformation Transformation::operator*(const Transformation &rhs) const {
    Transformation ret;
    ret.m = this->m * rhs.m;
    ret.im = rhs.im * this->im;
    return ret;
}