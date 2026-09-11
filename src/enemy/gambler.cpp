#include "gambler.h"
#include <time.h>

gambler::gambler() {
    multiplier = 1.0;
    // random health between 200-800
    srand(time(NULL));
    int randHealth = rand() % 601 + 200;
    baseEnemy(randHealth);
    isSkiped = false;
}


int gambler::pickMove() {

}
// Can do a lot of damage if they get lucky
// Will either do 40, 80, 120, 160, 200, 500
int gambler::jackpot() {
    int randDam = rand() % 101;
    if (randDam >= 80) return 40;
    else if (randDam >= 60) return 80;
    else if (randDam>=40) return 120;
    else if (randDam >= 20) return 160;
    else if (randDam >= 10) return 200;
    else return 500;
}

// Has to stop gambaling
int gambler::rehab() {
    setHealth(getHealth() + 200);
    multiplier -= 0.3;
}