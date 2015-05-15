//
// Created by qz9n1f on 2015.05.14..
//

#include "Materials.h"

Material Materials::glass() {
    return Material(1.5f, 1.5f, 1.5f, 0.0f, 0.0f, 0.0f, Color(0, 0, 0), Color(0, 0, 0), Color(0, 0, 0),
                    true,
                    true);
}

Material Materials::gold() {
    return Material(0.17f, 0.35f, 1.5f, 3.1f, 2.7f, 1.9f, Color(1, 1, 1), Color(1, 1, 1),
                    Color(0, 0, 0), true,
                    false);
}

Material Materials::silver() {
    return Material(0.14f, 0.16f, 0.13f, 4.1f, 2.3f, 3.1f, Color(1, 1, 1), Color(1, 1, 1),
                    Color(0, 0, 0), true,
                    false);
}

Material Materials::blinn() {
    return Material(0, 0, 0, 0, 0, 0, Color(0.5, 0, 0.5), Color(1, 1, 1), Color(0, 0, 0), false, false,
                    true,
                    30);
}
