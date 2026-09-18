#pragma once
#include "enemy/baseEnemy.h"

// grunt will be the easiest enemy in the game
// They suck
class grunt : public baseEnemy {
    public:
        enum move { BASIC_ATTACK, HEAL, SPECIAL_ATTACK, GET_LUCKY };

        grunt();

        int pickMove() override;
        int attack() override;
        std::string getName() {return "Grunt";};

        int basicAttack();

        int specialAttack();
        int heal();
        int getLucky();
};
