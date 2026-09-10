#include "Character.h"

Character::Character(int h, int a, int d): health(h), attack(a), defense(d) {}

int Character::getHealth() {
    return health;
}

int Character::getAttack() {
    return attack;
}

int Character::getDefense() {
    return defense;
}

void Character::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
}

void Character:attack(Enemy& target) {
    target.takeDamage(this->attack);
}


