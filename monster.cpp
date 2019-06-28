#include "monster.h"
#include <iostream>
using namespace std;

void Monster::setName(const string &value)
{
    name = value;
}

int Monster::getLevel() const
{
    return level;
}

void Monster::setLevel(int value) {
    level = value;
}

int Monster::getHealth() const
{
    return health;
}

void Monster::setHealth(int value)
{
    if (value>9999) {
        value = 9999;
    }
    health = value;
}

bool Monster::isDead() {
    if (getHealth()<=0) {
        return true;
    }
    else {
        return false;
    }
}

double Monster::getAttack() const
{
    return attack;
}

void Monster::setAttack(double value)
{
    if (value>256) {
        value = 256;
    }
    attack = value;
}

double Monster::getDefense() const
{

    return defense;
}

void Monster::setDefense(double value)
{
    if (value>256) {
        value = 256;
    }
    defense = value;
}

double Monster::getSpeed() const
{
    return speed;
}

void Monster::setSpeed(double value)
{
    if (value>256) {
        value = 256;
    }
    speed = value;
}

int Monster::getMaxHealth() const
{
    return maxHealth;
}

void Monster::setMaxHealth(int value)
{
    maxHealth = value;
}

Monster::Monster() {}

Monster::Monster(string name) {
    this->name = name;
    
}

double Monster::calcDamage(double def) {
   double damage = (25*level)*(getAttack()*((100+getAttack())/(100+def)))/def;
   return damage/3;
}

void Monster::printStats() {
    cout << "Name:" << getName() << endl;
    cout << "Level:" << getLevel() << endl;
    cout << "Health:" << getHealth() << endl;
    cout << "Att:" << getAttack() << endl;
    cout << "Def:" << getDefense() << endl;
    cout << "Speed:" << getSpeed() << endl;
}

void Monster::printHealthBar() {
    string bar ="||||||||||||||||||||";
    string digits;
    digits.append(to_string(getHealth()));
    digits.append("/");
    digits.append(to_string(getMaxHealth()));
    string whitespace;
    for (unsigned long i=digits.length(); i<=30; i++) {
        whitespace.append(" ");
    }
    cout << "|                                                                                                                                                                              |" << endl;
    cout <<"|                                                                                                                   " << whitespace << digits << "  " << bar << "      |" << endl;
}
