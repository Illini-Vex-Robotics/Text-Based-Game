#pragma once
#include "enemy/baseEnemy.h"

// Works with a lot of random values and does everything with equal chance
// Can hurt themselves or do tons of damage
// Has a multiplier that amplifies
// If they have a negative interaction the multiplier will increase because eventually they must hit the jackpot
class gambler : public baseEnemy {
    private:
        double multiplier;
        bool isSkiped;

    public:
        enum move { JACKPOT, REHAB, COIN_FLIP, DEAL_OR_NO, ACE };

        gambler();

        int pickMove() override;
        int attack() override;
        std::string getName() {return "Gambler";};


        // Does either 40, 80, 120, 160, 200, 500 which is amplified by multiplier
        int jackpot();
        // Either does damage and heals or loses a turn
        int coinFlip();
        // Has to go to rehab which increases his health, but decreases his multiplier
        int rehab();
        // Either does massive damage or massive healing
        int dealOrNo();
        // Increases his multiplier and does set damage (his ace to pull)
        int ace();
};
