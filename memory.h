//
// Created by qz9n1f on 2015.05.14..
//

#ifndef CPPNHF2_MEMORY_H
#define CPPNHF2_MEMORY_H

#include <memory>

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args &&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}


#endif //CPPNHF2_MEMORY_H
