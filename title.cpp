#include "title.h"
#include <iostream>
using namespace std;

Title::Title()
{


}

void Title::printTitle() {
    system("clear");
    cout << R"( ______________________________________________________________________________________________________________________________________________________________________________ 
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|                                             __  __                 _              ____  _                         ____    ___                                                |
|                                            |  \/  | ___  _ __  ___| |_ ___ _ __  / ___|| | __ _ _   _  ___ _ __  |___ \  / _ \                                               |
|                                            | |\/| |/ _ \| '_ \/ __| __/ _ \ '__| \___ \| |/ _` | | | |/ _ \ '__|   __) || | | |                                              |
|                                            | |  | | (_) | | | \__ \ ||  __/ |     ___) | | (_| | |_| |  __/ |     / __/ | |_| |                                              |
|                                            |_|  |_|\___/|_| |_|___/\__\___|_|    |____/|_|\__,_|\__, |\___|_|    |_____(_)___/                                               |
|                                                                                                 |___/                                                                        |
|                                                                                                                                                                              |
|                                                                ,                                         ,                                                                   |
|                                                               /|      __                         __      |\                                                                  |
|                                                              / |   ,-~ /                         \ ~-,   | \                                                                 |
|                                                             Y :|  //  /                           \  \\  |: Y                                                                |
|                                                             | jj /( .^                             ^. )\ ll |                                                                |
|                                                             >-"~"-v"                                 "v-"~"-<                                                                |
|                                                            /       Y                                 Y       \                                                               |
|                                                           /^  ^    |                                 |    ^  ^\                                                              |
|                                                          ( ~T~     j                                 l     ~T~ )                                                             |
|                                                           >._-' _./                                   \._  '-_.<                                                             |
|                                                          /   "~"  |                                   |   "~"   \                                                            |
|                                                         Y     _,  |                                   |   ,_     Y                                                           |
|                                                        /| ;-"~ _  l    Type "go" to start the Game!   j   _ ~"-; |\                                                          |
|                                                       / l/ ,-"~    \                                 /     ~"_, \j \                                                         |
|                                                       \//\/      .- \                               /   -.     \/\\/                                                         |
|                                                       Y        /     Y                             Y      \       Y                                                          |
|                                                       l       I      !                             !      I       j                                                          |
|                                                       ]\      _\    /"\                          /"\     /_      /[                                                          |
|                                                      (" ~----( ~   Y.  )                        (   .Y   ~ )----~ ")                                                         |
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|                                                              Enter "help" for extra commands. You can exit the game at any point by typing "exit". All progress will be lost.|
|______________________________________________________________________________________________________________________________________________________________________________|)" << endl;

}

void Title::printHeroNaming() {
    system("clear");
    cout << R"( ______________________________________________________________________________________________________________________________________________________________________________
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|                                                              Welcome to the world of MonsterSlayer, new hero!                                                                |
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|                                                                                     ,                                                                                        |
|                                                                             __      |\                                                                                       |
|                                                                             \ ~-,   | \                                                                                      |
|                                                                              \  \\  |: Y                                                                                     |
|                                                                               ^. )\ ll |                                                                                     |
|                                                                                 "v-"~"-<                                                                                     |
|                                                                                 Y       \                                                                                    |
|                                                                                 |    ^  ^\                                                                                   |
|                                                                                 l     ~T~ )                                                                                  |
|                                                                                  \._  '-_.<                                                                                  |
|                                                                                  |   "~"   \                                                                                 |
|                                                                                  |   ,_     Y                                                                                |
|                                                                                  j   _ ~"-; |\                                                                               |
|                                                                                 /     ~"_, \j \                                                                              |
|                                                                                /   -.     \/\\/                                                                              |
|                                                                               Y      \       Y                                                                               |
|                                                                               !      I       j                                                                               |
|                                                                             /"\     /_      /[                                                                               |
|                                                                            (   .Y   ~ )----~ ")                                                                              |
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|                               Please enter your name because it will go down in history and people will sing ballads about your heroic deeds.                                |
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|______________________________________________________________________________________________________________________________________________________________________________|)" << endl;

}
