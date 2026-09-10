#include "Enemy.h"

Enemy::Enemy(int h, int a, int d): health(h), attack(a), defense(d) {}

int Enemy::getHealth() {
    return health;
}

int Enemy::getAttack() {
    return attack;
}

int Enemy::getDefense() {
    return defense;
}

void Enemy::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
}



