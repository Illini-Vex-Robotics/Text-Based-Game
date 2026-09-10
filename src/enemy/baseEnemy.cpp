#include "baseEnemy.h"
#include <vector>

baseEnemy::baseEnemy() {
    health = 100;
    damage = 100;
}

baseEnemy::baseEnemy(int h, int d) {
    health = h;
    damage = d;
}

bool baseEnemy::isDead() {
    if (health <= 0) return true;
    else return false;
}

