#pragma once
#include <iostream>
#include<string>

class baseEnemy {
    protected:
        int health;
        int maxHealth;
        

    public:
        baseEnemy();
        baseEnemy(int maxH);
        void takeDamage(int damageTaken) {health -= damageTaken;};
        int getHealth() {return health;};
        void setHealth(int h);
        bool isDead();
        virtual int pickMove() = 0;
        
};



