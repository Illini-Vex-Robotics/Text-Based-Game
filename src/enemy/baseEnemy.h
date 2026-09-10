#pragma once
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



class enemy2 : public baseEnemy{

};

class enemy3 : public baseEnemy {

};