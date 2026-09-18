#include "gambler.h"
#include <time.h>

gambler::gambler() {
    multiplier = 1.0;
    // random health between 200-800
    srand((unsigned int)time(NULL));
    maxHealth = rand() % 60 + 60;
    health = maxHealth;
    isSkiped = false;
}

int gambler::pickMove() {
    int random = rand() % 101;
    if (random >= 80) return JACKPOT;
    else if (random >= 20) return REHAB;
    else if (random >= 1) return COIN_FLIP;
    else return DEAL_OR_NO;
}

int gambler::attack() {
    
    if (isSkiped) {
        isSkiped = false;
        std::cout << "The gambler is still counting his losses and skips a turn" << std::endl;
        return 0;
    }
    if (multiplier < 0.1) multiplier = 0.1;
    switch (pickMove()) {
        case JACKPOT:    return jackpot();
        case REHAB:      return rehab();
        case COIN_FLIP:  return coinFlip();
        case DEAL_OR_NO: return dealOrNo();
        default:         return ace();
    }
}

// Can do a lot of damage if they get lucky
// Will either do 40, 80, 120, 160, 200, 500
int gambler::jackpot() {
    int randDam = rand() % 101;
    int payout;
    if (randDam >= 80) payout = 5;
    else if (randDam >= 60) payout = 10;
    else if (randDam >= 40) payout = 15;
    else if (randDam >= 20) payout = 25;
    else if (randDam >= 10) payout = 35;
    else payout = 60;
    return (int)(payout * multiplier);
}

int gambler::coinFlip() {
    if (rand() % 2 == 1) {
        std::cout << "The gambler called the coin flip and cashed in" << std::endl;
        setHealth(getHealth() + 40);
        return 25 * multiplier;
    }
    std::cout << "The gambler missed the coin flip and loses his next turn" << std::endl;
    isSkiped = true;
    multiplier += 0.3;
    return 0;
}

// Has to stop gambaling
int gambler::rehab() {
    setHealth(getHealth() + 200);
    multiplier -= 0.3;
    return 0;
}

int gambler::dealOrNo() {
    if (rand() % 2 == 1) {
        std::cout << "The gambler took the deal" << std::endl;
        multiplier += 0.2;
        return 20 * multiplier;
    }
    std::cout << "The gambler passed on the deal and walked away healthier" << std::endl;
    setHealth(getHealth() + 200);
    multiplier -= 0.3;
    return 0;
}

int gambler::ace() {
    multiplier += 0.3;
    return (int)(30 * multiplier);
}
