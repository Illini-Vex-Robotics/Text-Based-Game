#pragma once
#include "enemy/baseEnemy.h"

class joker : public baseEnemy {
private:
    int stamina;
    bool checkTurn();

public:
    enum move { FAKE_GUN, EAT_PIE, LAUGHING_GAS, NUCLEAR_BOMB, EXPLOSIVE_PIE };

    joker();
    std::string getName() {return "Joker";};

    int pickMove() override;
    int attack() override;

    int fakeGun();
    int eatPie();
    int laughingGas();
    int nuclearBomb();
    int explosivePie();
};
