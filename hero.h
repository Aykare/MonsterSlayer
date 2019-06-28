#ifndef HERO_H
#define HERO_H
#include "monster.h"


class Hero : public Monster
{
private:
    double exp;
    //Gearslots

public:
    double levels[100];

    Hero(string name);
    void printHero();
    void printDeadHero();
    void levelUpCheck();
    void levelUp(int i);
    double *getLevels() const;
    void setLevelExp();
    double getExp() const;
    void setExp(double value);
    void addExp(double value);
    string placeholder(double number);
    string namePlaceholder();
    void printHealthBar();
};

#endif // HERO_H
