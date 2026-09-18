#include "Joker.h"

joker::joker() : baseEnemy(100) {
    stamina = 100;
}

bool joker::checkTurn() {
    int rand = std::rand() % 101;
    if (rand <= stamina) { return true; }
    else {
        stamina = 100;
        std::cout << "Didn't have enough stamina to attack" << std::endl;
        return false;
    }
}

int joker::pickMove() {
    return std::rand() % 5;
}

int joker::attack() {
    switch (pickMove()) {
        case FAKE_GUN:      return fakeGun();
        case EAT_PIE:       return eatPie();
        case LAUGHING_GAS:  return laughingGas();
        case NUCLEAR_BOMB:  return nuclearBomb();
        default:            return explosivePie();
    }
}

int joker::fakeGun() {
    if (checkTurn()) {
        setHealth(health + 10);
        stamina = 80;
        std::cout << "Joker used a fake gun" << std::endl;
        std::cout << "The Fake Gun did 30 damage and healed Joker 10" << std::endl;
        return 30;
    }
    return 0;
}

int joker::eatPie() {
    if (checkTurn()) {
        health = maxHealth;
        stamina = 80;
        std::cout << "Joker ate a pie" << std::endl;
        std::cout << "The Pie fully healed Joker" << std::endl;
    }
    return 0;
}

int joker::laughingGas() {
    if (checkTurn()) {
        stamina = 20;
        std::cout << "Joker threw laughing gas at you" << std::endl;
        std::cout << "The Laughing Gas did 30 damage" << std::endl;
        return 30;
    }
    return 0;
}

int joker::nuclearBomb() {
    if (checkTurn()) {
        stamina = 0;
        std::cout << "Joker sent a nuclear bomb at you" << std::endl;
        std::cout << "The Nuclear Bomb did 60 damage" << std::endl;
        return 60;
    }
    return 0;
}

int joker::explosivePie() {
    if (checkTurn()) {
        stamina = 40;
        std::cout << "Joker threw an explosive pie at you" << std::endl;
        std::cout << "The pie did 30 damage" << std::endl;
        return 30;
    }
    return 0;
}
