//
// Created by qz9n1f on 2015.05.14..
//

#include <iostream>
#include "Screen.h"

Screen::Screen() {
    Image = new Color[Height * Width];
}

Screen::~Screen() {
    delete Image;
}
