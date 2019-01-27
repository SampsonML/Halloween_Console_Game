//
// Created by matt on 20/01/19.
//

#include "Enemy_Attributes.h"

/*****************************************************
 *                                                   *
 * Choose the health and attack (Hurt) of each enemy *
 *                                                   *
 ****************************************************/

// Random enemy attack function



Enemy_Attributes:: Enemy_Attributes(std:: string Type){
    if (Type == "Skeleton"){
        Health = 20;
        Hurt = 1;
    }

    if (Type == "Spider"){
        Health = 10;
        Hurt = 1;
    }

    if (Type == "Wolf"){
        Health = 20;
        Hurt = 1;
    }

    if (Type == "Pumpkin"){
        Health = 200;
        Hurt = 40;
    }

    if (Type == "Dragon"){
        Health = 250;
        Hurt = 50;
    }
}