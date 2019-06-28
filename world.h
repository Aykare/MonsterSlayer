#ifndef WORLD_H
#define WORLD_H
#include <list>
#include <vector>
#include <enemy.h>
#include "menu.h"
#include "room.h"
#include "map.h"
#include "hero.h"
using namespace std;


class World
{
private:
    vector<Enemy> enemyList;
    double difficulty = 0;
    Menu menu;
    unsigned long currentRoom;
    Room room;
    Map map;


public:
    string input;
    vector<Room> rooms;


    World();

    Room getRoom();
    void createRoomList();
    void createList();
    void addEnemy(Enemy enemy);
    vector<Enemy> getEnemyList() const;
    void setEnemyList(const vector<Enemy> &value);
    double getDifficulty() const;
    void setDifficulty(double value);
    void difficultyMenu();
    void inputCheck();
    unsigned long getCurrentRoom() const;
    void setCurrentRoom(unsigned long value);
    void advanceRoom();
    void doorInput(Hero &hero);
    void lookAround(int screen, Hero &hero);
    void battle(Hero &hero);
};

#endif // WORLD_H
