#pragma once
#include "enemy/baseEnemy.h"

class joker : public baseEnemy {
private:
    int stamina;
    // Rolls against the stamina the last move left behind. On a failed roll the
    // turn is wasted and stamina is restored to full.
    bool checkTurn();

public:
    // The moves joker can roll on its turn.
    enum move { FAKE_GUN, EAT_PIE, LAUGHING_GAS, NUCLEAR_BOMB, EXPLOSIVE_PIE };

    joker();

    int pickMove() override;
    int attack() override;

    int fakeGun();
    int eatPie();
    int laughingGas();
    int nuclearBomb();
    int explosivePie();
};
