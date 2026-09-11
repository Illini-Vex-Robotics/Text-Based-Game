#include "baseEnemy.cpp"


// Works with a lot of random values and does everything with equal chance 
// Can hurt themselves or do tons of damage
// Has a multiplier that amplifies
// If they have a negative interaction the multiplier will increase because eventually they must hit the jackpot
class gambler : public baseEnemy {
    private:
        double multiplier;
        bool isSkiped;
    public:

        gambler();

        // Does either 40, 80, 120, 160, 200, 500 which is amplified by multiplier
        int jackpot();
        // Either does damage and heals or loses a turn
        int coinFlip();
        // Has to go to rehab which increases his health, but decreases his multiplier
        int rehab();
        // Either does massive damage or massive healing
        int dealOrNo();
        // Increases his multiplier and does set damage (his ace to pull)
        void ace();
};
