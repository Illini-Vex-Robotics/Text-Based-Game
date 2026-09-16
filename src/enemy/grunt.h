#pragma once
#include "enemy/baseEnemy.h"

// grunt will be the easiest enemy in the game
// They suck
class grunt : public baseEnemy {
    public:
        // The moves grunt can roll on its turn.
        enum move { BASIC_ATTACK, HEAL, SPECIAL_ATTACK, GET_LUCKY };

        grunt();

        int pickMove() override;
        int attack() override;

        // Does a set amount of little damage
        int basicAttack();
        // Does a random amount of damage 1-60
        // Could be good, could be bad
        int specialAttack();
        // Heal a little
        int heal();
        // 1% chance of happening, but will do massive damage
        int getLucky();
};
