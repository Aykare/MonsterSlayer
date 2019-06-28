#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include "monster.h"
using namespace std;


class Enemy : public Monster
{
private:
    double expValue;
    double spawnChance;
    int gold;
    int minLevel;
    int maxLevel;

public:
    Enemy();
    Enemy(string name, int min, int max);
    void printEnemy();
    void buildStats();
    int getMinLevel() const;
    void setMinLevel(int value);
    int getMaxLevel() const;
    void setMaxLevel(int value);
};

#endif // ENEMY_H
