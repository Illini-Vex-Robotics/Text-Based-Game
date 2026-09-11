#pragma once
#pragma once

#include "enemy/baseEnemy.h"

class BaseCharacter {
public:
    BaseCharacter(int h, int a, int d): health(h), attackPower(a), defense(d){}
    int getHealth();
    void takeDamage(int damage);
    int getAttackPower();
    void setAttackPower(int a);
    int getDefense();
    void setDefense(int d);
    void takeDamage(int damage);

    void attack(Enemy& enemy);
    
private:
    int health;
    int attackPower;
    int defense;
};
