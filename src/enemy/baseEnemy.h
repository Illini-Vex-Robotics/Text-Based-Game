#pragma once
#include "character/baseCharacter.h"

class Enemy {
public:
    void init(int health, int attackPower, int defense);
    int getHealth();
    void setHealth(int h);
    int getAttackPower();
    void setAttackPower(int a);
    int getDefense();
    void setDefense(int d);
    void takeDamage(int damage);

    void attack(BaseCharacter& character);
    
private:
    int health;
    int attackPower;
    int defense;
};