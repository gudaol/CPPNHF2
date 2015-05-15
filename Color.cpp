//
// Created by qz9n1f on 2015.05.14..
//

#include "Color.h"

Color::Color() {
    r = g = b = 0;
}

Color::Color(float r0, float g0, float b0) {
    r = r0;
    g = g0;
    b = b0;
}

Color Color::operator*(float a) const {
    return Color{r * a, g * a, b * a};
}

Color Color::operator/(float a) const {
    return Color{r / a, g / a, b / a};
}

Color Color::operator*(const Color &c) const {
    return Color{r * c.r, g * c.g, b * c.b};
}

Color Color::operator/(const Color &c) const {
    return Color{r / c.r, g / c.g, b / c.b};
}

Color Color::operator+(const Color &c) const {
    return Color{r + c.r, g + c.g, b + c.b};
}

Color Color::operator-(const Color &c) const {
    return Color{r - c.r, g - c.g, b - c.b};
}

float Color::max(const Color &_c) {
    float i[3];
    i[0] = _c.r;
    i[1] = _c.g;
    i[2] = _c.b;
    float m = i[0];
    for (int j = 0; j < 3; j++)
        if (m < i[j])
            m = i[j];
    return m;
}
