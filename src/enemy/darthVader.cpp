#include "darthVader.h"

darthVader::darthVader() : baseEnemy(300) {
    stamina = 100;
}

bool darthVader::checkTurn() {
    int rand = std::rand() % 101;
    if (rand <= stamina) { return true; }
    else {
        stamina = 100;
        std::cout << "Didn't have enough stamina to attack" << std::endl;
        return false;
    }
}

int darthVader::pickMove() {
    return std::rand() % 5;
}

int darthVader::attack() {
    switch (pickMove()) {
        case FORCE_PUSH:       return forcePush();
        case FORCE_HEAL:       return forceHeal();
        case FORCE_CHOKE:      return forceChoke();
        case YOUNGLING_SLAYER: return younglingSlayer();
        default:               return throwShit();
    }
}

int darthVader::forcePush() {
    if (checkTurn()) {
        setHealth(health + 10);
        stamina = 80;
        std::cout << "Darth Vader used force push" << std::endl;
        std::cout << "Force Push did 30 damage and healed Darth Vader 10" << std::endl;
        return 30;
    }
    return 0;
}

int darthVader::forceHeal() {
    if (checkTurn()) {
        health = maxHealth;
        stamina = 80;
        std::cout << "Darth Vader used force heal" << std::endl;
        std::cout << "Force Heal fully healed Darth Vader" << std::endl;
    }
    return 0;
}

int darthVader::forceChoke() {
    if (checkTurn()) {
        stamina = 20;
        std::cout << "Darth Vader used force choke" << std::endl;
        std::cout << "Force Choke did 40 damage" << std::endl;
        return 40;
    }
    return 0;
}

int darthVader::younglingSlayer() {
    if (checkTurn()) {
        stamina = 0;
        std::cout << "Darth Vader thought your were a youngling" << std::endl;
        std::cout << "Darth Vader did 55 damage" << std::endl;
        return 55;
    }
    return 0;
}

int darthVader::throwShit() {
    if (checkTurn()) {
        stamina = 40;
        std::cout << "Darth Vader threw shit at you" << std::endl;
        std::cout << "Some random object did 20 damage" << std::endl;
        return 20;
    }
    return 0;
}
