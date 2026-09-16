#include "grunt.h"

grunt::grunt() : baseEnemy(50) {}

int grunt::pickMove() {
    // random value between [0,100]
    int random = rand() % 101;
    if (random >= 60) return BASIC_ATTACK;
    else if (random >= 20) return HEAL;
    else if (random >= 1) return SPECIAL_ATTACK;
    else return GET_LUCKY;
}

int grunt::attack() {
    switch (pickMove()) {
        case BASIC_ATTACK:   return basicAttack();
        case HEAL:           return heal();
        case SPECIAL_ATTACK: return specialAttack();
        default:             return getLucky();
    }
}

int grunt::basicAttack() {
    return 20;
}

int grunt::specialAttack() {
    return rand() % 60 + 1;
}

int grunt::heal() {
    setHealth(health + 20);
    return 0;
}

int grunt::getLucky() {
    return 300;
}
