#include "baseEnemy.h"
<<<<<<< HEAD
#include <vector>
#include <cstdlib>

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

// This gives a range [0, 100]
// rand() % 101 
=======
#include "character/baseCharacter.h"

void Enemy::init(int health, int attackPower, int defense){
    this->health = health;
    this->attackPower = attackPower;
    this->defense = defense;
}
int Enemy::getHealth(){
    return health;
}
void Enemy::setHealth(int h){
    this->health = h;
}
int Enemy::getAttackPower(){
    return attackPower;
}
void Enemy::setAttackPower(int a){
    this->attackPower = a;
}
int Enemy::getDefense(){
    return defense;
}
void Enemy::setDefense(int d){
    this->defense = d;
    
}
void takeDamage(int damage){
    
}

// Interaction
void attack(BaseCharacter& character){
    
}

>>>>>>> origin/tonyCow
