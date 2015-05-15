//
// Created by qz9n1f on 2015.05.12..
//

#include "Material.h"

Material::Material(float _Nr, float _Ng, float _Nb, float _Kr, float _Kg, float _Kb, const Color &_kd,
                   const Color &_ks,
                   const Color &_Ka, const bool _rl, const bool _rf, const bool _blinn,
                   const float _shininess) {
    N = Color(_Nr, _Ng, _Nb);
    K = Color(_Kr, _Kg, _Kb);
    reflective = _rl;
    refractive = _rf;
    blinn = _blinn;
    shininess = _shininess;
    kd = _kd;
    ks = _ks,
            Ka = _Ka;
    n = (N.r + N.g + N.b) / 3;
    F0 = Color(((N.r - 1) * (N.r - 1) + K.r * K.r) /
               ((N.r + 1) * (N.r + 1) + K.r * K.r),
               ((N.g - 1) * (N.g - 1) + K.g * K.g) /
               ((N.g + 1) * (N.g + 1) + K.g * K.g),
               ((N.b - 1) * (N.b - 1) + K.b * K.b) /
               ((N.b + 1) * (N.b + 1) + K.b * K.b));
}

Color Material::Kd(int x, int y, bool proc) {
    if (!proc)
        return kd;
    else
        return Color(x % 255 ^ y % 255, x % 255 & y % 255, x % 255 | y % 255);
}

bool Material::isReflective() {
    return reflective;
}

bool Material::isRefractive() {
    return refractive;
}

bool Material::isBlinn() {
    return blinn;
}

Vector Material::ReflectionDir(const Vector &V, const Vector &N) {
    return V - N * (N * V) * 2;
}

bool Material::RefractionDir(const Vector &_V, Vector &_N, Vector &_T) {
    float cosa = -(_N.Normalized() * _V.Normalized());
    float cn = n;
    if (cosa < 0) {
        cosa = -cosa;
        _N = -_N;
        cn = 1 / n;
    }
    float disc = 1 - (1 - cosa * cosa) / cn / cn;
    if (disc < 0)
        return false;
    _T = (_V / cn + _N * (cosa / n - sqrt(disc))).Normalized();
    return true;
}

Color Material::Fresnel(const Vector &V, const Vector &N) {
    float cosa = std::abs(N * V);
    return F0 + (Color(1, 1, 1) - F0) * pow(1 - cosa, 5);
}