#ifndef MONSTER_H
#define MONSTER_H
#include <string>
using namespace std;


class Monster
{
private:
    string name;
    //string element;

    int health;
    int maxHealth;
    //int mana;
    int level;

    double attack;
    double defense;
   // double mAttack;
    //double mDefense;
    double speed;


    double accuracy;
    double critChance;

public:
    Monster();
    Monster(string name);

    string getName() { return name; }
    void setName(const string &value);
    int getHealth() const;
    void setHealth(int value);
    int getLevel() const;
    void setLevel(int value);

    double getAttack() const;
    void setAttack(double value);
    double getDefense() const;
    void setDefense(double value);
    double getSpeed() const;
    void setSpeed(double value);
    double calcDamage(double def);
    bool isDead();

    void printStats();
    int getMaxHealth() const;
    void setMaxHealth(int value);
    void printHealthBar();
};

#endif // MONSTER_H
