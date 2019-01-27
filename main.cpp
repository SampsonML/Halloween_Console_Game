/* Text based game Halloween
 * Matt Sampson
 * 2019*/


#include <iostream>
#include <string>
#include <stdlib.h>
#include <random>
#include <cstdlib>
#include <ctime>
#include "Landscapes.h"
#include "Enemies.h"
#include "Items.h"
#include "Enemy_Attributes.h"
#include "Weapons.h"
#include "Weapon_Attributes.h"


/* *******************************************************************************************************************
 * To make things easier to read, all game functions will be defined here before calling main, normally would want   *
 * them in seperate cpp files but that's not needed, just makes things look nicer.                                   *
 *                                                                                                                   *
 * To use a function, simply type its name, and if it needs a parameter type that in the brackets, ie DiceRoll(Luck) *
 * will call DiceRoll using whatever value Luck is at to add to the dice score.                                      *
 *                                                                                                                   *
 * All updatable variables ie, luck, health, damage_multi must be in main scope so they can be updated               *
 * throughout all sequences of the game                                                                              *
 * ******************************************************************************************************************/



// Initialising Global Variables, these are the updatable player attribute, ie Luck, Strength, Health etc
// Initialised here for function use, will also be initialised in scope of main function
int Luck {1};
int Experience{0};
int Player_Level{0};
double Player_Health {25};
std:: string Weapon_Equip = "Sword1";
double Damage_Multi {Weapon_Attributes(Weapon_Equip).Weapon_Multi};



// Function Declarations, to make sure things compile, be sure functions will all be defined before implementation

void Church();
void clear();
void Sleep();
double Dice_Roll(int Luck);
double Enemy_Roll();
double Attack_Score(double Damage);
int Forest();
void Menu();
void Mountains();
void Village();
void Lake();


// Defining a function to clear space in the  console
void clear() {
    std:: cout << std:: string(20, '\n'); // First number is how many line to skip, change at will
}

// Defining Sleeping function, when sleep health regens?

void Sleep(){
    std:: cout << "Sleeping....zzzzzzzzzzzz \n"
                  "zzzzzzzzzzzzzzzzzzzzzzzz\n"
                  "zzzzzzzzzzzzzzzzzzzzzzzz" << std:: endl;

    // Code for health regen goes here
}


// Defining random chance function, ie Diceroll in D and D
// Luck, will be updated during play and added to diceroll score, function returns Dice score

double Dice_Roll(int Luck) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1.0, 7.0);
    return dist(mt)+ Luck;
}

double Enemy_Roll() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1.0, 4.0);
    return dist(mt);
}

// Defining attack score, Will be attack/weapon multiplier times dice score,
// used to calculate total damage whenever in battle


double Attack_Score(double Damage){
    double Damage_Score {0.0};
    Damage_Score = Dice_Roll(Luck)*Damage;
    return Damage_Score;
}


/********************************************************************************************
 *                                                                                          *
 * Below here and before the main function we can put all of the ncp challenges and         *
 * possibly level functions too                                                             *
 *                                                                                          *
 *                                                                                          *
 * You can define either a void function (ie doesnt return anything) or a function that     *
 * can return a value or string. Could be useful for level/exp build up.                    *
 *                                                                                          *
 *                                                                                          *
 *******************************************************************************************/




// Forest Quest and level functions

int Forest(){
    double Damage_Multi {Weapon_Attributes(Weapon_Equip).Weapon_Multi};
    std:: cout << "Welcome to the forest, its a dark and cold place \n"
                  "Beasts roam free, people have gone mad wandering in the darkness \n"
                  "Try to not lose your head" << std:: endl;
    clear();
    std:: cin.get();

    std:: cout << "You enter the forest and can hear some rumblings in the trees \n"
                  "The villagers warned you to be on guard, you keep you hand close to your weapon" << std:: endl;
    std:: cin.get();
    std:: cout << "Oh no!!! Something jups out at you \n"
                  "Its a spider" << std:: endl;
    Enemies("Spider").Creature;
    std:: cout << "Quickly, you must slay this beast" << std:: endl;
    std:: cout << "You attack, " << std:: endl;
    std:: cin.get();
    double Local_Health {Enemy_Attributes("Spider").Health};
    while (Local_Health > (Luck + 1)) {
        double Power {Attack_Score(Damage_Multi)};
        double Damage_Taken {Enemy_Roll()*Enemy_Attributes("Spider").Hurt};
        std::cout << "Your attack deals " << Power << " damage" << std::endl;
        std::cout << "Spiders attack deals " << Damage_Taken << " damage" << std::endl;
        Weapons(Weapon_Equip).Weapon_Type;
        Local_Health = Local_Health - Power;
        Player_Health = Player_Health - Damage_Taken ;
        std:: cout << "Spiders health now at " << Local_Health << std:: endl;
        std:: cout << "Your health now at " << Player_Health << std:: endl;
        std:: cout << "You attack again" << std:: endl;
        std:: cin.get();
    }
    Experience = Experience + 5;
    std:: cout << "That was a close one, but luckily you live on"  << std:: endl;
    std:: cout << "Your health is now " << Player_Health << std:: endl;
    std:: cout << "Your experience is now " << Experience << std:: endl;
    std:: cin.get();
    std:: cout <<  "You continue onwards through the trees, its getting ever darker "  << std:: endl;
    std:: cin.get();
    std:: cout <<  "You were told that this was the site of the first death "  << std:: endl;
    std:: cin.get();
    std:: cout << "Thngs seem to get creepy and you see a building in the distance" << std:: endl;
    std:: cin.get();
    Landscapes("Church").World_Type;
    std:: cin.get();
    Church();
    return 0;
}

// Now writing Church level

void Church(){

    std:: string Chest_Choice;
    std:: cout << "Its a church, it seems abandoned" << std:: endl;
    std:: cin.get();
    std:: cout << "You open the door and enter\n"
                  "Its dark and very cold. Something seems not quite right" << std:: endl;
    std:: cin.get();
    std:: cout << "Theres a chest by the wall, do you open it? Open or Leave" << std:: endl;
    std:: cin >> Chest_Choice;

    if (Chest_Choice == "Open")
    {
        std:: cout << "You open the chest and look inside" << std:: endl;
        std:: cin.get();
        Weapons("Axe").Weapon_Type;
        std:: cout << "Wow a new weapon, I'll equip that now!!!" << std:: endl;
        std:: cout << "Axe does 1.5 damage multiplier" << std:: endl;
        Weapon_Equip = "Axe";
    }

    if (Chest_Choice == "Leave")
    {
        std:: cout << "You need some more curiosity in your heart" << std:: endl;
    }

    std:: cin.get();
    std:: cout << "You keep looking around and see a bloodstained piece book" << std:: endl;
    clear();
    std:: cout << R"(
           .-~~~~~~~~~-._       _.-~~~~~~~~~-.
            __.'              ~.   .~              `.__
          .'//                  \./                  \\`.
        .'//                     |                     \\`.
      .'// .-~"""""""~~~~-._     |     _,-~~~~"""""""~-. \\`.
    .'//.-"                 `-.  |  .-'                 "-.\\`.
  .'//______.============-..   \ | /   ..-============.______\\`.
.'______________________________\|/______________________________`.
)" << std:: endl;

    std:: cout << "Think of some cool message/hint to put in here" << std:: endl;
    std:: cin.get();

    std:: cout << "Time to go back to the homeworld, you start wandering back" << std:: endl;
    std:: cin.get();
    std:: cout << "A skeleton ambushes you!!!!" << std:: endl;

    Enemies("Skeleton").Creature;
    std:: string Fight_Choice;
    std:: cout << "Do you Fight or Run" << std:: endl;
    std:: cin >> Fight_Choice;
    if (Fight_Choice == "Fight"){
        std:: cout << "You attack, " << std:: endl;
        std:: cin.get();
        double Local_Health {Enemy_Attributes("Skeleton").Health};   // Using the Skeleton class, and health attribute to get numerical value for skeleton health (benefits of OOP)
        while (Local_Health > (Luck + 1)) {
            double Power {Attack_Score(Damage_Multi)};
            double Damage_Taken {Enemy_Roll()*Enemy_Attributes("Skeleton").Hurt}; // OOP again makes things much easier
            std::cout << "Your attack deals " << Power << " damage" << std::endl;
            std::cout << "Skeletons attack deals " << Damage_Taken << " damage" << std::endl;
            Weapons(Weapon_Equip).Weapon_Type;
            Local_Health = Local_Health - Power;
            Player_Health = Player_Health - Damage_Taken ;
            std:: cout << "Skeleton's health now at " << Local_Health << std:: endl;
            std:: cout << "Your health now at " << Player_Health << std:: endl;
            std:: cout << "You attack again" << std:: endl;
            std:: cin.get();
        }

        Experience = Experience + 5;
        std:: cout << "All hail Valdimir the conquerer"  << std:: endl;
        std:: cout << "Your health is now " << Player_Health << std:: endl;
        std:: cout << "Your experience is now " << Experience << std:: endl;
    }

    if (Fight_Choice == "Run"){
        std:: cout << "You little bitch" << std:: endl;
    }

    std:: cout << "Nice you killed him, (or ran like a bitch) \n"
                  "You make it back to the homeworld" << std:: endl;




}

// Mountains function level
void Mountains()
{

    std:: cout << "The air is freezing, the ground is snow, the mountains are as treacherous as you remembered" << std:: endl;
    std:: cin.get();
    std:: cout << "You were told there may be some secrets to uncover here" << std:: endl;
    std:: cin.get();
    std:: cout << "You start to climb, knowing the road ahead will be difficult" << std:: endl;
    std:: cin.get();
    std:: cout << "Ah an apple tree,this will do well to recover some health" << std:: endl;
    Player_Health = Player_Health + 10;
    std:: cout << "Health now at " << Player_Health << std:: endl;
    clear();

    

}

// Village function level
void Village()
{

}

// Lake function level
void Lake()
{

}


/*******************************************************************************************
 *                                                                                         *
 * Menu/ Homeworld function, return to this page for player stats and to travel to new     *
 * worlds and areas                                                                        *
 *                                                                                         *
 ******************************************************************************************/

void Menu(){
    std:: string Where_To;
    Landscapes("Home").World_Type;
    std:: cout << "Your health is " << Player_Health << std :: endl;
    std:: cout << "Your experience is " << Experience << std :: endl;
    std:: cout << "Your level is " << Player_Level << std :: endl;
    std:: cout << "Where would you like to go? \n"
                  "Village \n"
                  "Lake \n"
                  "Forest \n"
                  "Mountains" << std:: endl;
    std:: cin >> Where_To;

    if (Where_To == "Village"){
        clear();
        Landscapes("Castle").World_Type;
        Village();
    }
    if (Where_To == "Lake"){
        clear();
        Landscapes("Lake").World_Type;
        Lake();
    }
    if (Where_To == "Forest"){
        clear();
        Landscapes("Forest").World_Type;
        Forest();
    }
    if (Where_To == "Mountains"){
        clear();
        Landscapes("Mountains").World_Type;
        Mountains();
    }

}

// Main Function, ie the game

int main() {
    // Main scope variables,
    //int Luck {1};
    //int Experience{0};
    //int Player_Level{0};
    //
    // double Player_Health {25};
    std:: string Weapon_Equip = "Sword1";
    double Damage_Multi {Weapon_Attributes(Weapon_Equip).Weapon_Multi};

        std:: cout << R"(
============================================================================
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
============================================================================

                            ;::;;::;,
                            ;::;;::;;,
                           ;;:::;;::;;,
           .vnmmnv%vnmnv%,.;;;:::;;::;;,  .,vnmnv%vnmnv,
        vnmmmnv%vnmmmnv%vnmmnv%;;;;;;;%nmmmnv%vnmmnv%vnmmnv
      vnmmnv%vnmmmmmnv%vnmmmmmnv%;:;%nmmmmmmnv%vnmmmnv%vnmmmnv
     vnmmnv%vnmmmmmnv%vnmmmmmmmmnv%vnmmmmmmmmnv%vnmmmnv%vnmmmnv
    vnmmnv%vnmmmmmnv%vnmmmmmmmmnv%vnmmmmmmmmmmnv%vnmmmnv%vnmmmnv
   vnmmnv%vnmmmmmnv%vnmm;mmmmmmnv%vnmmmmmmmm;mmnv%vnmmmnv%vnmmmnv,
  vnmmnv%vnmmmmmnv%vnmm;' mmmmmnv%vnmmmmmmm;' mmnv%vnmmmnv%vnmmmnv
  vnmmnv%vnmmmmmnv%vn;;    mmmmnv%vnmmmmmm;;    nv%vnmmmmnv%vnmmmnv
 vnmmnv%vnmmmmmmnv%v;;      mmmnv%vnmmmmm;;      v%vnmmmmmnv%vnmmmnv
 vnmmnv%vnmmmmmmnv%vnmmmmmmmmm;;       mmmmmmmmmnv%vnmmmmmmnv%vnmmmnv
 vnmmnv%vnmmmmmmnv%vnmmmmmmmmmm;;     mmmmmmmmmmnv%vnmmmmmmnv%vnmmmnv
 vnmmnv%vnmmmmm nv%vnmmmmmmmmmmnv;, mmmmmmmmmmmmnv%vn;mmmmmnv%vnmmmnv
 vnmmnv%vnmmmmm  nv%vnmmmmmmmmmnv%;nmmmmmmmmmmmnv%vn; mmmmmnv%vnmmmnv
 `vnmmnv%vnmmmm,  v%vnmmmmmmmmmmnv%vnmmmmmmmmmmnv%v;  mmmmnv%vnnmmnv'
  vnmmnv%vnmmmm;,   %vnmmmmmmmmmnv%vnmmmmmmmmmnv%;'   mmmnv%vnmmmmnv
   vnmmnv%vnmmmm;;,   nmmm;'              mmmm;;'    mmmnv%vnmmmmnv'
   `vnmmnv%vnmmmmm;;,.         mmnv%v;,            mmmmnv%vnmmmmnv'
    `vnmmnv%vnmmmmmmnv%vnmmmmmmmmnv%vnmmmmmmnv%vnmmmmmnv%vnmmmmnv'
      `vnmvn%vnmmmmmmnv%vnmmmmmmmnv%vnmmmmmnv%vnmmmmmnv%vnmmmnv'
          `vn%vnmmmmmmn%:%vnmnmmmmnv%vnmmmnv%:%vnmmnv%vnmnv'


============================================================================
||||||||||||╔═╗┬  ┬    ╦ ╦┌─┐┬  ┬  ┌─┐┬ ┬┌─┐  ╔═╗┬  ┬┌─┐||||||||||||||||||||
||||||||||||╠═╣│  │    ╠═╣├─┤│  │  │ ││││└─┐  ║╣ └┐┌┘├┤  |||||||||||||||||||
||||||||||||╩ ╩┴─┘┴─┘  ╩ ╩┴ ┴┴─┘┴─┘└─┘└┴┘└─┘  ╚═╝ └┘ └─┘||||||||||||||||||||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||||By Matt and Jordann Sampson|||||||||||||||||||||||||||||||||||||
============================================================================


)" << std:: endl;
  std:: string name;
  std:: cout << "Welcome to the game, please enter your name" << std:: endl;
  std:: cin >> name ;
  std:: cout << "Hi " << name << " prepare to enter hell" << std:: endl;
  std:: cin.get(); // To add pauses

  /* *******************************************************************
   *                                                                   *
   * Purely for testing functions and goto points,                     *
   * not part of game story, keep in here as a reference for you       *
   *                                                                   *
   * General beginning of new world/area setup below                   *
   *                                                                   *
   ********************************************************************/


  /*******************************************************************************
   *                                                                             *
   * This is the general attack setup, start by initiating Local_Health,         *
   *                                                                             *
   * To do that, just set Local_Health to Enemy_Attributes("Enemy_Type").Health  *
   *                                                                             *
   * Next, setup the while loop like below, all variables should already be set  *
   *                                                                             *
   * Note, to print pic of weapon, type Weapons(Weapon_Equip).Weapon_Type        *
   *                                                                             *
   * Weapon_Equip is a main scope variable that should be changed whenever a     *
   * new weapon is picked up                                                     *
   *                                                                             *
   * To find out all Enemy_Type, and Weapon types available look in their        *
   * respective cpp files, ie Weapons.cpp                                        *
   *                                                                             *
   ******************************************************************************/

  /*

  Enemies("Skeleton").Creature;
  std:: string Fight_Choice;
  std:: cout << "Do you Fight or Run" << std:: endl;
  std:: cin >> Fight_Choice;
  if (Fight_Choice == "Fight"){
      std:: cout << "You attack, " << std:: endl;
      std:: cin.get();
      double Local_Health {Enemy_Attributes("Skeleton").Health};   // Using the Skeleton class, and health attribute to get numerical value for skeleton health (benefits of OOP)
      while (Local_Health > (Luck + 1)) {
          double Power {Attack_Score(Damage_Multi)};
          double Damage_Taken {Enemy_Roll()*Enemy_Attributes("Skeleton").Hurt}; // OOP again makes things much easier
          std::cout << "Your attack deals " << Power << " damage" << std::endl;
          std::cout << "Skeletons attack deals " << Damage_Taken << " damage" << std::endl;
          Weapons(Weapon_Equip).Weapon_Type;
          Local_Health = Local_Health - Power;
          Player_Health = Player_Health - Damage_Taken ;
          std:: cout << "Skeleton's health now at " << Local_Health << std:: endl;
          std:: cout << "Your health now at " << Player_Health << std:: endl;
          std:: cout << "You attack again" << std:: endl;
          std:: cin.get();
      }
  }

  if (Fight_Choice == "Run"){
      std:: cout << "You little bitch" << std:: endl;
  }

  std:: cout << "Nice you killed your first enemy" << std:: endl;

   */

/**********************************************************************
 *                                                                    *
 * Start writing the beginning of the game storyline after this       *
 *                                                                    *
 *********************************************************************/

 std:: cout << "Welcome to All Hallows Eve Homeworld" << std:: endl;

 Menu();

 std:: cout << "You rest and wait until the next night to explore some more" << std:: endl;
 if (Experience > 8){
     std:: cout << "Through your journeys you have levelled up, good job" << std:: endl;
     Player_Level = Player_Level + 1;
     std:: cout << "Now at level " << Player_Level << std:: endl;
 }


 Menu();


    return 0;
}

