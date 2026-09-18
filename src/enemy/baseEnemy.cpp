#include "baseEnemy.h"

baseEnemy::baseEnemy() {
    health = 100;
    maxHealth = 100;
}

baseEnemy::baseEnemy(int maxH) {
    maxHealth = maxH;
    health = maxHealth;
}

bool baseEnemy::isDead() {
    return health <= 0;
}

void baseEnemy::setHealth(int h) { 
    health = h;
    if (health > maxHealth) health = maxHealth;
    if (health < 0) health = 0;
}

// This gives a range [1, 100]
// rand() % 100 + 1

// rand() % (max-min+1) + min
