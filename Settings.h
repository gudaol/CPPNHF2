//
// Created by qz9n1f on 2015.05.14..
//

#ifndef CPPNHF2_SETTINGS_H
#define CPPNHF2_SETTINGS_H


#include "Materials.h"

struct Settings {
    static constexpr float distance = 40.0f;
    static constexpr float epsilon = 0.01f;

    static constexpr int samples = 3;
    static Materials material;
};


#endif //CPPNHF2_SETTINGS_H
