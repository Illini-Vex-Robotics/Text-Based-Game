#include "baseEnemy.h"
#include <vector>
#include <cstdlib>

baseEnemy::baseEnemy() {
    health = 100;
    maxHealth = 100;
}

baseEnemy::baseEnemy(int maxH) {
    maxHealth = maxH;
    health = maxHealth;
}

bool baseEnemy::isDead() {
    if (health <= 0) return true;
    else return false;
}
void baseEnemy:setHealth(int h) {
    health += h;
    if (maxHealth < health) health = maxHealth;
}



// This gives a range [1, 100]
// rand() % 100 + 1 

// rand() % (max-min+1) + min