//
// Created by matt on 20/01/19.
//

#include "Weapon_Attributes.h"

/************************************************************
 *                                                          *
 * Weapon attributes will determine the damage multiplier   *
 * when in battle                                           *
 *                                                          *
 ***********************************************************/


Weapon_Attributes:: Weapon_Attributes(std:: string Type) {
    if (Type == "Sword1") {
        Weapon_Multi = 1;
    }

    if (Type == "Axe") {
        Weapon_Multi = 1.5;
    }

    if (Type == "Bow1") {
        Weapon_Multi = 1.5;
    }

    if (Type == "Sword2") {
        Weapon_Multi = 5;
    }
}