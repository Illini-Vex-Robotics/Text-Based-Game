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
    std::cout << "The grunt attacks you with a club for 10 damage.";
    return 10;
}

int grunt::specialAttack() {
    std::cout << "The grunt uses all of their might to hit you";
    return rand() % 30 + 1;
}

int grunt::heal() {
    std::cout << "The grunt ate a well balanced meal to heal 20 health;";
    setHealth(health + 20);
    return 0;
}

int grunt::getLucky() {
    std::cout << "The grunt fell and stabbed the character doing 60 damage;";
    return 60;
}
