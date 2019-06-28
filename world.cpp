#include "world.h"
#include <iostream>

using namespace std;

vector<Enemy> World::getEnemyList() const
{
    return enemyList;
}

void World::setEnemyList(const vector<Enemy> &value)
{
    enemyList = value;
}

double World::getDifficulty() const
{
    return difficulty;
}

void World::setDifficulty(double value)
{
    difficulty = value;
}

unsigned long World::getCurrentRoom() const
{
    return currentRoom;
}

void World::setCurrentRoom(unsigned long value)
{
    currentRoom = value;
}

World::World()
{
    createList();
    for (int i=1; i<=100; i++) {
        rooms.push_back(Room());
    }
    currentRoom = 0;
}

void World::advanceRoom() {
    setCurrentRoom(getCurrentRoom()+1);
}

Room World::getRoom() {
    return rooms[getCurrentRoom()];
}

void World::createList() {
    Enemy enemy01("Evil Sheep", 1, 99);
    Enemy enemy02("Slime", 1, 10);
    Enemy enemy03("Black Cat", 10, 15);
    Enemy enemy04("Ugly Troll", 40, 50);
    Enemy enemy05("Ghost", 80, 100);
    Enemy enemy50("Mighty Dragon", 90, 100);
    this->enemyList.push_back(enemy01);
    this->enemyList.push_back(enemy02);
}

void World::addEnemy(Enemy enemy){
    this->enemyList.push_back(enemy);
}
void World::inputCheck() {
    if (!input.compare("exit")) {
        exit(0);
    }
    if (!input.compare("help")) {
        cout << "exit: exit the game" << endl;
        cout << "rules: get an explanation of how to play" << endl;
        //"titlescreen: clears console and reprints titlescreen"
    }
    if(!input.compare("rules")) {
        cout << "How to Play:" << endl;
        cout << "Advance in the game by choosing a door. You can choose by typing \"left\", \"middle\" or \"right\"" << endl;
        cout << "You can choose options from the menu by typing them into the console (eg. \"stats\")" << endl;
        cout << "You cannot go back to a room once you advanced to the next. If you end up in a dead end go back with \"back\"" << endl;
        cout << "Thats pretty much it. Have fun!" << endl;
    }
}

void World::difficultyMenu() {
    system("clear");
    menu.printDifMenu();
    while (getDifficulty()==0.0) {
        cout << "Set difficulty to: ";
        cin >> input;
        cin.clear();
        inputCheck();
        if (!input.compare("0")) {
            cout << "The Difficulty was set to easy. Enter \"yes\" to confirm or anything else to choose again." << endl;

            cin >> input;
            cin.clear();
            inputCheck();
            if (!input.compare("yes")) {
                setDifficulty(0.5);
            }

        }
        else if (!input.compare("1")) {
            cout << "The Difficulty was set to normal. Enter \"yes\" to confirm or anything else to choose again." << endl;
            cin >> input;
            cin.clear();
            inputCheck();
            if (!input.compare("yes")) {
                setDifficulty(1);
            }
        }
        else if (!input.compare("2")) {
            cout << "The Difficulty was set to hard. Enter \"yes\" to confirm or anything else to choose again." << endl;
            cin >> input;
            cin.clear();
            inputCheck();
            if (!input.compare("yes")) {
                setDifficulty(1.25);
            }
        }
        else if (!input.compare("3")) {
            cout << "The Difficulty was set to insanity. Enter \"yes\" to confirm or anything else to choose again." << endl;
            cin >> input;
            cin.clear();
            inputCheck();
            if (!input.compare("yes")) {
                setDifficulty(2);
            }
        }
        else {
            cout << "Please enter a valid input" << endl;
        }
    }
}

void World::lookAround(int screen, Hero &hero) {
    if (!input.compare("stay")) {
        int event = room.stayEventTrigger();
        switch (event) {
        case 1: cout << "You look around and find a treasure! It's useless though since neither items nor gold have been implemented" << endl; break;
        case 2: cout << "You look around. Nothing happens." << endl; break;
        case 3:  system("clear");
            menu.printBattleMenu();
            while (input.compare("flee")) {
                cin >> input;
                cin.clear();
                inputCheck();
                if(!input.compare("fight")) {
                    battle(hero);
                    input = "flee";
                }

            }
            if (screen == 0) {
                system("clear");
                map.printDoor();
                menu.printMenuBar();
                cout << "Current Room: " << getCurrentRoom()+1 << endl;
            }
            if (screen == 1) {
                system("clear");
                room.treasureEvent();
                menu.printRoomMenuBar();
            }
            if (screen == 5) {
                system("clear");
                room.deadEndEvent();
                menu.printRoomMenuBar();
            }
            break;
        default: cout << "You somehow broke the game" << endl;
        }
    }
}


void World::doorInput(Hero &hero) {
    if (!input.compare("left")||!input.compare("middle")||!input.compare("right")) {
        bool temp = false;
        int event;
        if (!input.compare("left")) {
            if (rooms[getCurrentRoom()].getLeft()) {
                rooms[getCurrentRoom()].setLeft(false);
                temp = true;
            }
            else {
                cout << "You already went that way." << endl;
            }
        }
        if (!input.compare("middle")) {
            if (rooms[getCurrentRoom()].getMiddle()) {
                rooms[getCurrentRoom()].setMiddle(false);
                temp = true;
            }
            else {
                cout << "You already went that way." << endl;
            }
        }
        if (!input.compare("right")) {
            if (rooms[getCurrentRoom()].getRight()) {
                rooms[getCurrentRoom()].setRight(false);
                temp = true;
            }
            else {
                cout << "You already went that way." << endl;
            }
        }
        if (temp==true) {
           event = rooms[getCurrentRoom()].advanceEventTrigger();
           if ((rooms[getCurrentRoom()].getLeft()&&!rooms[getCurrentRoom()].getMiddle()&&!rooms[getCurrentRoom()].getRight())
               || (!rooms[getCurrentRoom()].getLeft()&&rooms[getCurrentRoom()].getMiddle()&&!rooms[getCurrentRoom()].getRight())
                   || (!rooms[getCurrentRoom()].getLeft()&&!rooms[getCurrentRoom()].getMiddle()&&rooms[getCurrentRoom()].getRight())) {
              int temp = rand() % 2;
              if (temp==0) {
                  event = 2;
              }
              else {
                  event = 4;
              }
           }
           switch (event) {
           case 1:
               system("clear");
               room.treasureEvent();
               menu.printRoomMenuBar();
               cout << "You found a treasure! But neither items nor gold are implemented right now so this is a gloryfied dead end. Sorry dude." << endl;
               while (input.compare("back")) {
                   cin >> input;
                   cin.clear();
                   inputCheck();
                   lookAround(1, hero);
               }
               system("clear");
               map.printDoor();
               menu.printMenuBar();
               cout << "Current Room: " << getCurrentRoom()+1 << endl;
               break;
           case 2:    system("clear");
               menu.printBattleMenu();
               while (input.compare("flee")) {
                   cin >> input;
                   cin.clear();
                   inputCheck();
                   if(!input.compare("fight")) {

                       battle(hero);
                       input = "flee";
                   }

               }

           case 4: setCurrentRoom(getCurrentRoom()+1);
               system("clear");
               map.printDoor();
               menu.printMenuBar();
               cout << "Current Room: " << getCurrentRoom()+1 << endl;
               cout << "You found the next room." << endl;
               break;
           case 3: //battle
               system("clear");
               menu.printBattleMenu();
               while (input.compare("flee")) {
                   cin >> input;
                   cin.clear();
                   inputCheck();
                   if(!input.compare("fight")) {

                       battle(hero);
                       input = "flee";
                   }

               }
           case 5:
               system("clear");
               room.deadEndEvent();
               menu.printRoomMenuBar();
               cout << "You find a dead end." << endl;
               while (input.compare("back")) {


               cin >> input;
               cin.clear();
               inputCheck();
               lookAround(5, hero);
               }
               system("clear");
               map.printDoor();
               menu.printMenuBar();
               cout << "Current Room: " << getCurrentRoom()+1 << endl;
               break;
           default: cout << "Congratulation! You broke the game." << endl;
           }
        }
    }
}

void World::battle(Hero &hero) {
    bool monsterFound = false;
    Enemy opponent;
    bool attFirst;
    int min;
    int max;
    bool flee = false;
    vector<Enemy> monsterList = getEnemyList();

    while (monsterFound==false) {
        opponent = monsterList[(rand()%monsterList.size())];
        min = opponent.getMinLevel()-2;
        if (min<0) {min=0;}
        max = opponent.getMaxLevel()+2;
        opponent.setLevel(hero.getLevel());
        opponent.buildStats();
        if (getCurrentRoom()>min&&getCurrentRoom()<max) {
            monsterFound = true;
            cout << "Monster found!" << endl;
        }
    }
    system("clear");
    map.printBattle01();
    opponent.printHealthBar();
    opponent.printEnemy();
    hero.printHealthBar();
    map.printBattle02();
    if (hero.getSpeed()<opponent.getSpeed()) {
        attFirst=false;
    }
    else if (hero.getSpeed()>opponent.getSpeed()) {
        attFirst=true;
    }
    else {
       int temp = rand()%2;
       if (temp==0) {
           attFirst = true;
       }
       else {
           attFirst = false;
       }
    }

    while (!hero.isDead()&&!opponent.isDead()&&flee==false) {
        cin >> input;
        inputCheck();
        if (!input.compare("att")) {
            if (attFirst) {
                opponent.setHealth(opponent.getHealth()-hero.calcDamage(opponent.getDefense()));
                if(!opponent.isDead()) {
                   hero.setHealth(hero.getHealth()-opponent.calcDamage(hero.getDefense()));
                }
            }
            else {
                hero.setHealth(hero.getHealth()-opponent.calcDamage(hero.getDefense()));
                if(!hero.isDead()) {
                 opponent.setHealth(opponent.getHealth()-hero.calcDamage(opponent.getDefense()));

                }
            }
            system("clear");
            map.printBattle01();
            opponent.printHealthBar();
            opponent.printEnemy();
            hero.printHealthBar();
            map.printBattle02();
            if (attFirst) {
                cout << opponent.getName() << " takes " << hero.calcDamage(opponent.getDefense()) << " damage." << endl;
                if(!opponent.isDead()) {
                    cout << "You take " << opponent.calcDamage(hero.getDefense()) << " damage." << endl;
                }
            }
            else {
                cout << "You take " << opponent.calcDamage(hero.getDefense()) << " damage." << endl;
                if(!hero.isDead()) {
                    cout << opponent.getName() << " takes " << hero.calcDamage(opponent.getDefense()) << " damage." << endl;
                }
            }
        }
        if (!input.compare("flee")) {
            flee = true;
            hero.setHealth(hero.getMaxHealth());
            cout << "help?" << endl;
        }
        if (opponent.isDead()) {
            //get exp

            cout << "You win and gain " << getCurrentRoom()*opponent.getLevel()*5 << " experience points." << endl;
            hero.addExp(getCurrentRoom()*opponent.getLevel()*5);
            hero.setHealth(hero.getMaxHealth());
            flee = true;
        }
        else if (hero.isDead()) {
           system("clear");
           hero.printDeadHero();
           cout << "GAME OVER" << endl;
           exit(0);
        }}
    }






