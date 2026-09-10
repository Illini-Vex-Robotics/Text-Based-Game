#include "Character.h"
#include "Enemy.h"

Character::Character(int h, int a, int d): hp(h), atk(a), def(d) {}

int Character::getHealth() {
    return hp;
}

int Character::getAttack() {
    return atk;
}

int Character::getDefense() {
    return def;
}

void Character::takeDamage(int damage) {
    hp -= damage;
    if (hp < 0) {
        hp = 0;
    }
}

void Character::attack(Enemy& target) {
    int damage = this->atk;
    target.takeDamage(damage);
}


