#include "grunt.h"

grunt() {
    baseEnemy();
}

int grunt::pickMove() {
    //random value between [0,100]
    int random = rand() % (101);
    if (random >= 60) return basicAttack();
    else if (random >= 20) return heal();
    else if (random >= 1) return specialAttack();
    else return getLucky();
}

// Does a set amount of  little damage
int grunt::basicAttack() {
    return 20;
}
// Does random amount of damage 1-60
// Could be good, could be bad
int grunt::specialAttack() {
    return rand() % 60 + 1;
}
// heal a little 
int grunt::heal() {
    setHealth(health+20);
}
// 1% chance of happening, but will do massive damage
int grunt::getLucky() {
    return 300;
}