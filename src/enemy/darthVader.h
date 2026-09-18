#pragma once
#include "enemy/baseEnemy.h"

class darthVader : public baseEnemy {
    private:
        int stamina;
        bool checkTurn();

    public:
        enum move { FORCE_PUSH, FORCE_HEAL, FORCE_CHOKE, YOUNGLING_SLAYER, THROW_SHIT };

        darthVader();

        int pickMove() override;
        int attack() override;
        std::string getName() {return "Darth Vader";};
        int forcePush();
        int forceHeal();
        int forceChoke();
        int younglingSlayer();
        int throwShit();
};
