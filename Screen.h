//
// Created by qz9n1f on 2015.05.14..
//

#ifndef CPPNHF2_SCREEN_H
#define CPPNHF2_SCREEN_H


#include "Color.h"

struct Screen {
    static const int Width = 600;
    static const int Height = 600;
    Color *  Image;
    Screen();
    ~Screen();
};

#endif //CPPNHF2_SCREEN_H

