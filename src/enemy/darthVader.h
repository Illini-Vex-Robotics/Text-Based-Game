#pragma once
#include "enemy/baseEnemy.h"

class darthVader : public baseEnemy {
    private:
        int stamina;
        // Rolls against the stamina the last move left behind. On a failed roll
        // the turn is wasted and stamina is restored to full.
        bool checkTurn();

    public:
        // The moves darthVader can roll on its turn.
        enum move { FORCE_PUSH, FORCE_HEAL, FORCE_CHOKE, YOUNGLING_SLAYER, THROW_SHIT };

        darthVader();

        int pickMove() override;
        int attack() override;

        int forcePush();
        int forceHeal();
        int forceChoke();
        int younglingSlayer();
        int throwShit();
};
