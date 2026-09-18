#pragma once
#include <iostream>
#include <string>
#include <cstdlib>

class baseEnemy {
    protected:
        int health;
        int maxHealth;

    public:
        baseEnemy();
        baseEnemy(int maxH);
        virtual ~baseEnemy() = default;

        virtual void takeDamage(int damageTaken) { setHealth(health - damageTaken); }
        virtual int getHealth() { return health; }
        virtual int getMaxHealth() {return maxHealth;};
        virtual void setHealth(int h);
        virtual bool isDead();
        virtual int pickMove() = 0;
        virtual int attack() = 0;
        virtual std::string getName() = 0;
};
