//
// Created by matt on 20/01/19.
//

#include "Weapons.h"


Weapons:: Weapons(std:: string Weapon_Type) {

    if (Weapon_Type == "Sword1") {
        std::cout << R"(
      /| ________________
O|===|* >________________>
      \|
)" << std::endl;
    }

    if (Weapon_Type == "Axe") {
        std::cout << R"(
  ,  /\  .
 //`-||-'\\
(| -=||=- |)
 \\,-||-.//
  `  ||  '
     ||
     ||
     ||
     ||
     ||
     ()
)" << std::endl;

    }
    if (Weapon_Type == "Sword2") {
        std::cout << R"(
     /\
    //\\
    ||||
    ||||
    ||||
    ||||
    ||||
    ||||
    ||||
    ||||
    ||||
    ||||
    ||||
    ||||
 _  ||||  _
/(  ||||  )\
\\\_[\/]_///
 \\_<()>_//
  \/[\\]\/
    [//]
    [\\]
    [//]
    [\\]
    [//]
    (__)
)" << std::endl;
    }

    if (Weapon_Type == "Bow1") {
        std::cout << R"(
   (
    \
     )
##-------->
     )
    /
   (
)" << std::endl;
    }

}