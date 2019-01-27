//
// Created by matt on 20/01/19.
//
#include <iostream>
#include <string>

#ifndef HALLOWEEN_ENEMY_ATTRIBUTES_H
#define HALLOWEEN_ENEMY_ATTRIBUTES_H


class Enemy_Attributes {
public:
    double Health {0.0};
    double Hurt {0.0};

    explicit Enemy_Attributes(std:: string);
};


#endif //HALLOWEEN_ENEMY_ATTRIBUTES_H
