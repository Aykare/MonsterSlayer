#include "enemy.h"
#include <iostream>
using namespace std;

int Enemy::getMinLevel() const
{
    return minLevel;
}

void Enemy::setMinLevel(int value)
{
    minLevel = value;
}

int Enemy::getMaxLevel() const
{
    return maxLevel;
}

void Enemy::setMaxLevel(int value)
{
    maxLevel = value;
}

Enemy::Enemy() {

}
Enemy::Enemy(string name, int min, int max)
{
    setName(name);
    setMinLevel(min);
    setMaxLevel(max);
    /* setLevel(level);
    setAttack(10+(2*getLevel())*modifier);
    setDefense(10+(2*getLevel())*modifier);
    setSpeed(10+(2*getLevel())*modifier);
    setHealth((100+(getLevel()*getLevel())+getLevel()-1)*modifier);*/
}

void Enemy::buildStats() {
    //srand(time(NULL));
    int temp = getMaxLevel()-getMinLevel();
    double modifier = (75+(rand()%51))/100.0;
    int attMod = (rand()%11)-5;
    int defMod = (rand()%11)-5;
    int spMod = (rand()%11)-5;

    setAttack(((10+(2*getLevel()))*modifier)+attMod);
    setDefense(((10+(2*getLevel()))*modifier)+defMod);
    setSpeed(((10+(2*getLevel()))*modifier)+spMod);
    setHealth(((100+(getLevel()*getLevel())+getLevel()-1))*modifier);
    setMaxHealth(getHealth());


}

void Enemy::printEnemy() { //13 lines
    string enemy = getName();
    if (enemy == "Evil Sheep") {
        cout << R"(|                                                                                                                                                                              |
|                                                                                                                                                            __  _             |
|                                                                                                                                                        .-:'  `; `-._         |
|                                                                                                                                                       (_,           )        |
|                                                                                                                                                     ,'o"(            )>      |
|                                                                                                                                                    (__,-'            )       |
|                                                                                                                                                       (             )        |
|                                                                                                                                                        `-'._.--._.-'         |
|                                                                                                                                                           |||  |||           |
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|                                                                                                                                                                              |)" << endl;
    }

}
