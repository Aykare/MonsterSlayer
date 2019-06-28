#include "hero.h"
#include <iostream>
#include <math.h>
using namespace std;

Hero::Hero(string name)
{
    setName(name);
    setLevel(1);
    setLevelExp();
    setExp(0);
    setHealth(100+(getLevel()*getLevel())+(getLevel()-1));
    setMaxHealth(getHealth());
    setAttack(10);
    setDefense(10);
    setSpeed(10);

}

void Hero::setLevelExp()
{
    levels[0]=0; //exp<=6 = Level 1
    levels[1]=6;
    levels[2]=34;
    levels[3]=94;
    levels[4]=202;
    levels[5]=372;
    levels[6]=616;
    levels[7]=949;
    for(int i = 8; i<98; i++) {
        levels[i]=round(levels[i-1]*(1.3-(0.03*((i+1)/10.0))));
    }
    //levels[98]=round(levels[97]*(1.3-(0.03*(99/10.0)))); Why the fuck does this cause stack smashing
    //cout << "Level 99: " << levels[98] << endl;
}

double Hero::getExp() const
{
    return exp;
}

void Hero::setExp(double value)
{
    exp = value;
}

void Hero::addExp(double value) {
    double exp = getExp()+value;
    setExp(exp);
    levelUpCheck();
}

void Hero::levelUpCheck() {
    for (int i = 0; i<98;i++) {
        if (getExp()>=this->levels[i]&&getExp()<=this->levels[i+1]) {
            if (getLevel()!=i+1) {
                levelUp(i+1);
                cout << "LEVEL UP!" << endl;
                return;
            }
        }
    }
}

void Hero::levelUp(int i) {
    int newlevel = i - getLevel();
    setAttack(getAttack()+(2*newlevel));
    setDefense(getDefense()+(2*newlevel));
    setSpeed(getSpeed()+(2*newlevel));
    if(getLevel()==1) {
        setAttack(getAttack()+2);
        setDefense(getDefense()+2);
        setSpeed(getSpeed()+2);
    }
    setLevel(i);
    setHealth(100+(getLevel()*getLevel())+(getLevel()-1));
    setMaxHealth(getHealth());
}

string Hero::placeholder(double number) {
    string s;
    if (number<10) { //0-9
        s="       ";
    }
    else if (number>=10&&number<100) { //11-99
        s="      ";
    }
    else if (number>=100&&number<1000) {
        s="     ";
    }
    else if (number>=1000&&number<10000) {
        s="    ";
    }
    else if (number>=10000&&number<100000) {
        s="   ";
    }
    else if (number>=100000&&number<1000000) {
        s="  ";
    }
    else if (number>=1000000&&number<10000000) {
        s=" ";
    }
    else if (number>=10000000&&number<100000000) {
        s="";
    }
    return s;
}
string Hero:: namePlaceholder() {
    unsigned long number = getName().length();
    string s;
    for (int i = number; i<=20; i++) {
        s.append(" ");
    }
    return s;
}


void Hero::printHero() {
        cout << R"( ______________________________________________________________________________________________________________________________________________________________________________
|                                         |                                                                                                                                    |
|                                         |                                                                                                                                    |
|                                         |                                                                                                                                    |
|                                         |                                                                                                                                    |
|                                         |                                                                                                                                    |
|                   ,                     |                                                                                                                                    |
|           __      |\                    |                                                                                                                                    |)" << endl;
cout << R"(|           \ ~-,   | \                   |           )" << "Name: " << getName() << namePlaceholder() << "                                                                                              |" << endl;
cout << R"(|            \  \\  |: Y                  |                                                                                                                                    |)" << endl;
cout << R"(|             ^. )\ ll |                  |           )" << "Level: " << getLevel() << placeholder(getLevel()) <<"                                                                                                          |" << endl;
cout << R"(|                "v-"~-<                  |                                                                                                                                    |)" << endl;
cout << R"(|               Y       \                 |           )" << "EXP: " << getExp() << placeholder(getExp()) <<"                                                                                                            |" << endl;
cout << R"(|               |    ^  ^\                |                                                                                                                                    |)" << endl;
cout << R"(|               l     ~T~ )               |           )" << "HP: " << getHealth() << placeholder(getHealth()) <<"                                                                                                             |" << endl;
cout << R"(|                \._  '-_.<               |                                                                                                                                    |)" << endl;
cout << R"(|                |   "~"   \              |           )" << "Attack: " << getAttack() << placeholder(getAttack()) <<"                                                                                                         |" << endl;
cout << R"(|                |   ,_     Y             |                                                                                                                                    |)" << endl;
cout << R"(|                j   _ ~"-; |\            |           )" << "Defense: " << getDefense() << placeholder(getDefense())<<"                                                                                                        |" << endl ;
cout << R"(|               /     ~"_, \j \           |                                                                                                                                    |)" << endl;
cout << R"(|              /   -.     \/\\/           |           )" << "Statuspoints: " << "                                                                                                           |" << endl ;
cout << R"(|             Y      \       Y            |                                                                                                                                    |
|             !      I       j            |                                                                                                                                    |
|           /"\     /_      /[            |                                                                                                                                    |
|          (   .Y   ~ )----~ ")           |                                                                                                                                    |
|                                         |                                                                                                                                    |
|                                         |                                                                                                                                    |
|                                         |                                                                                                                                    |
|                                         |                                                                                                                                    |
|                                         |                                                                                                                                    |
|                                         |                                                                                                                                    |
|-----------------------------------------|------------------------------------------------------------------------------------------------------------------------------------|
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|            > Back                                                                                                                                                            |
|                                                                                                                                                                              |
|                                                                                                                                                                              |
|______________________________________________________________________________________________________________________________________________________________________________|)" << endl;
}

void Hero::printDeadHero() {
    cout << R"(
                 ,
                /|      __
               / |   ,-~ /
              Y :|  //  /
              | jj /( .^
              >-"~"-v"
             /       Y
            jX  X    |
           ( ~T~     j
            >._-' _./
           /   "~"  |
          Y     _,  |
         /| ;-"~ _  l
        / l/ ,-"~    \
        \//\/      .- \
         Y        /    Y
         l       I     !
         ]\      _\    /"\
        (" ~----( ~   Y.  ))" << endl;
}

void Hero::printHealthBar() {
    string bar ="||||||||||||||||||||";
    string digits;
    digits.append(to_string(getHealth()));
    digits.append("/");
    digits.append(to_string(getMaxHealth()));
    string whitespace;
    for (unsigned long i=digits.length(); i<=30; i++) {
        whitespace.append(" ");
    }
    cout << "|      " << bar << "  " << digits << whitespace << "                                                                                                                   |" << endl;
}
