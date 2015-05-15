//
// Created by qz9n1f on 2015.05.12..
//

#ifndef CPPNHF2_MATERIAL_H
#define CPPNHF2_MATERIAL_H

#include "Color.h"
#include "Vector.h"

struct Material {
    Color K, N, kd, ks, F0, Ka;
    bool reflective, refractive, blinn;
    float n, shininess;

    Material(float _Nr = 1.0f, float _Ng = 1.0f, float _Nb = 1.0f, float _Kr = 0.0f, float _Kg = 0.0f, float _Kb = 0.0f,
             const Color &_kd = Color(0, 0, 0), const Color &_ks = Color(0, 0, 0),
             const Color &_Ka = Color(0, 0, 0), const bool _rl = true, const bool _rf = false,
             const bool _blinn = false,
             const float _shininess = 1);

    Color Kd(int x, int y, bool proc);

    bool isReflective();

    bool isRefractive();

    bool isBlinn();

    Vector ReflectionDir(const Vector &V, const Vector &N);

    bool RefractionDir(const Vector &_V, Vector &_N, Vector &_T);

    Color Fresnel(const Vector &V, const Vector &N);
};


#endif //CPPNHF2_MATERIAL_H
