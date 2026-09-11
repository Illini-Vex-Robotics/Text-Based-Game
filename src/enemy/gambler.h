#include "baseEnemy.cpp"


// Works with a lot of random values and does everything with equal chance 
// Can hurt themselves or do tons of damage
// Has a multiplier that amplifies
// If they have a negative interaction the multiplier will increase because eventually they must win
class gambler : public baseEnemy {
    private:
        double multiplier;
    public:
        gambler();

        int jackpot();
        int coinFlip();
        int rehab();
        int dealOrNo();
        void ace();
};
