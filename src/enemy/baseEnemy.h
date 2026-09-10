#pragma once
<<<<<<< HEAD
#include <iostream>
#include<string>

class baseEnemy {
    protected:
        int health;
        int damage;

    public:
        baseEnemy();
        baseEnemy(int h, int d);
        void takeDamage(int damageTaken) {damage -= damageTaken;};
        int getHealth() {return health;};
        int getDamage() {return damage;};
        void setDamage(int d) {damage = d;};
        void setHealth(int h) {health = h;};
        bool isDead();



};



=======
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
>>>>>>> origin/tonyCow
