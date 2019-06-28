#include "map.h"
#include <iostream>
using namespace std;

Map::Map()
{
 //menu is 39 lines
 //instead of programming a map, it will be random
 //an event will randomly trigger when a door is chosen
    //everytime the player advances a room a depth variable will be +1, everytime you have to go back it will be -1
    //there will be 100 levels?
    //save levels in array
    //everytime you go back one a visited variable will be added +1, when it is 2 the next room will definitly the way to the next room
    //dead ends do not exist in the array and will not cause an advancing
    //create a room object. every room has a left, middle, right property that will be set to false when that room was entered so it cant be entered again
}
void Map::printDoor() {
    cout << R"( ______________________________________________________________________________________________________________________________________________________________________________
|                                         |                                                                                        |                                           |
|                                         |                                                                                        |                                           |
|                                         |                                                                                        |                                           |
|                                         |                                                                                        |                                           |
|                                         |                                                                                        |                                           |
|                                         |                                                                                        |                                           |
|                                         |                                                                                        |                                           |
|                                         |                                                                                        |                                           |
|                                         |               left                      middle                    right                |                                           |
|                                         |               ______                    ______                    ______               |                                           |
|                                         |            ,-' ;  ! `-.              ,-' ;  ! `-.              ,-' ;  ! `-.            |                                           |
|                                         |           / :  !  :  . \            / :  !  :  . \            / :  !  :  . \           |                                           |
|                                         |          |_ ;   __:  ;  |          |_ ;   __:  ;  |          |_ ;   __:  ;  |          |                                           |
|                                         |          )| .  :)(.  !  |          )| .  :)(.  !  |          )| .  :)(.  !  |          |                                           |
|                                         |          |"    (##)  _  |          |"    (##)  _  |          |"    (##)  _  |          |                                           |
|                                         |          |  :  ;`'  (_) (          |  :  ;`'  (_) (          |  :  ;`'  (_) (          |                                           |
|                                         |          |  :  :  .     |          |  :  :  .     |          |  :  :  .     |          |                                           |
|                                         |          )_ !  ,  ;  ;  |          )_ !  ,  ;  ;  |          )_ !  ,  ;  ;  |          |                                           |
|                                         |          || .  .  :  :  |          || .  .  :  :  |          || .  .  :  :  |          |                                           |
|                                         |          |" .  |  :  .  |          |" .  |  :  .  |          |" .  |  :  .  |          |                                           |
|                                         |__________|_____;----.___|__________|_____;----.___|__________|_____;----.___|__________|                                           |
|                                        /                                                                                          \                                          |
|                                      /                                                                                              \                                        |
|                                    /                                                                                                  \                                      |
|                                  /                                                                                                      \                                    |
|                                /                                                                                                          \                                  |
|                              /                                                                                                              \                                |
|                            /                                                                                                                  \                              |
|                          /                                                                                                                      \                            |
|                        /                                                                                                                          \                          |)" << endl;
}

void Map::printBattle01() {
    cout << R"( ______________________________________________________________________________________________________________________________________________________________________________ )"<< endl;
}

void Map::printBattle02() { //19 von 31. 1x border, 1x health monster, 1x health hero
    cout << R"(|                  ,                                                                                                                                                           |
|          __      |\                                                                                                                                                          |
|          \ ~-,   | \                                                                                                                                                         |
|           \  \\  |: Y                                                                                                                                                        |
|            ^. )\ ll |                                                                                                                                                        |
|               "v-"~-<                                                                                                                                                        |
|              Y       \                                                                                                                                                       |
|              |    0  0\                                                                                                                                                      |
|              l     ~T~ )                                                                                                                                                     |
|              \._  '-_.<                                                                                                                                                      |
|              |   "~"   \                                                                                                                                                     |
|              |   ,_     Y                                                                                                                                                    |
|              j   _ ~"-; |\                                                                                                                                                   |
|             /     ~"_, \j \                                                                                                                                                  |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|            > Attack ("att")                                                                  > Flee ("flee")                                                                 |
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|______________________________________________________________________________________________________________________________________________________________________________|)" << endl;
}
