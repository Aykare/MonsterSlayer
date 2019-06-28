#include <QCoreApplication>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include "enemy.h"
#include "title.h"
#include "map.h"
#include "menu.h"
#include "world.h"
#include "hero.h"

using namespace std;

int main() {
    srand(time(NULL));
    World world;
    Title title;
    Map map;
    Menu menu;
    Hero hero("Lady Fluffybutt");
    vector<Enemy> enemyList = world.getEnemyList();
    world.input ="titlescreen";
    string heroName;
    char tempHeroName[21];
    world.setCurrentRoom(0);
    
     bool firstTime = true;
//items and status not available in rooms

    while (world.input.compare("exit")) {
        if (!world.input.compare("titlescreen")) {
            title.printTitle();
        }
        cin >> world.input;
        cin.clear();
        if (!world.input.compare("status")) {
            system("clear");
            hero.printHero();
            cin >> world.input;
            world.inputCheck();
            cin.clear();
        }

        if(!world.input.compare("bcheck")) {
            system("clear");
            menu.printBattleMenu();
            while (world.input.compare("flee")) {
                cin >> world.input;
                cin.clear();
                world.inputCheck();
                if(!world.input.compare("fight")) {

                    world.battle(hero);
                    cin >> world.input;
                    cin.clear();
                    world.inputCheck();
                }
            }
        }

        if(!world.input.compare("doors")) {
            while (world.input.compare("exit")) {
                if (firstTime) {
                    system("clear");
                    map.printDoor();
                    menu.printMenuBar();
                    cout << "Current Room: " << world.getCurrentRoom()+1 << endl;
                    firstTime = false;
                }
                cin >> world.input;
                world.inputCheck();
                cin.clear();
                world.doorInput(hero);
                world.lookAround(0, hero);
            }
        }

        if (!world.input.compare("help")) {//durch inputcheck ersetzen
            cout << "exit: exit the game" << endl;
            //"titlescreen: clears console and reprints titlescreen"
            //-"endboss: a backdoor that goes to the endboss"
            //-"levelup: adds a lvl, also backdoor"
        }

        if (!world.input.compare("go")) { //if this part moves to world it keeps his function
            //if i build a second exit here i can loop through (not needed atm since its linear)
            world.difficultyMenu();
            system("clear");
            title.printHeroNaming();
            cin.ignore();
            while(world.input.compare("start")) {
                cin.getline(tempHeroName, 21);
                cin.clear();
                world.input = tempHeroName;
                if (world.input.compare("start")) {
                    heroName = tempHeroName;
                    hero.setName(heroName);
                    world.inputCheck();
                    cout << "If you are sure your name is " << world.input << " enter \"start\" to start the game! (Or type another name)" << endl;
                }
            }
            while (world.input.compare("exit")) {
                if (firstTime) {
                    system("clear");
                    map.printDoor();
                    menu.printMenuBar();
                    cout << "Current Room: " << world.getCurrentRoom()+1 << endl;
                    firstTime = false;
                }

                cin >> world.input;
                world.inputCheck(); //cin.get() somewhere
                cin.clear();
                world.doorInput(hero);
                world.lookAround(0,hero);


                if (!world.input.compare("status")) {
                    while (world.input.compare("back")) {
                        system("clear");
                        hero.printHero();
                        cin >> world.input;
                        world.inputCheck(); //cin.get() somewhere
                        cin.clear();
                    }
                    system("clear");
                    map.printDoor();
                    menu.printMenuBar();
                    cout << "Current Room: " << world.getCurrentRoom()+1 << endl;
                }

                if(!world.input.compare("item")) {
                    cout << "Items have not been implemented yet. Sorry mate." << endl;
                    sleep(5);
                }
            }
        }


    }
    return 0;
}
