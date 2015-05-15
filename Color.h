//
// Created by qz9n1f on 2015.05.14..
//

#ifndef CPPNHF2_COLOR_H
#define CPPNHF2_COLOR_H


struct Color {
    float r, g, b;

    Color();

    Color(float r0, float g0, float b0);

    Color operator*(float a) const;

    Color operator/(float a) const;

    Color operator*(const Color &c) const;

    Color operator/(const Color &c) const;

    Color operator+(const Color &c) const;

    Color operator-(const Color &c) const;

    float static max(const Color &_c);
};


#endif //CPPNHF2_COLOR_H
