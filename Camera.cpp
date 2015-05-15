//
// Created by qz9n1f on 2015.05.14..
//

#include "Camera.h"

Camera::Camera(const Vector &_eye, const Vector &_lookat, const Vector &_up, const Vector &_right)
        : eye(_eye), lookat(_lookat), up(_up), right(_right) { }

Ray Camera::getRay(const int x, const int y) const {
    Vector p = lookat +
               right * (2.0 * (x + 0.5) / Screen::Width - 1) +
               up * (2.0 * (y + 0.5) / Screen::Height - 1);
    return Ray(eye, (p - eye).Normalized());
}

void Camera::update(float _B, float _L) {
    B = _B;
    L = _L;
    eye = Vector(ex(), ey(), ez());
    right = -(((lookat - eye).gimmeOrtogonal()) * (((eye - lookat).Length())));
    up = -(((lookat - eye) % right).Normalized() * ((eye - lookat).Length()));
}

float Camera::ez(void) {
    return distance * std::cos(B / 36.0f);
}

float Camera::ey(void) {
    return distance * std::sin(B / 36.0f) * std::sin(L / 18.0f);
}

float Camera::ex(void) {
    return distance * std::sin(B / 36.0f) * std::cos(L / 18.0f);
}