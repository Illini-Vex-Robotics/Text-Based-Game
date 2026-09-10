#include "baseCharacter.h"
#include "enemy/baseEnemy.h"

class BaseCharacter {
public: 
BaseCharacter::BaseCharacter(int h, int a, int d): health(h), attackPower(a), defense(d){}

int BaseCharacter::getHealth(){
    return this->health;
}
void BaseCharacter::takeDamage(int damage){
    this->health = health - damage;
}
int BaseCharacter::getAttackPower(){
    return attackPower;
}
void BaseCharacter::setAttackPower(int a){
    this->attackPower = a;
}
int BaseCharacter::getDefense(){
    return defense;
}
void BaseCharacter::setDefense(int d){
    this->defense = d;
}

// Interaction
void attack(Enemy& enemy){
    enemy.takeDamage(getAttackPower());
}

private:
    int health;
    int attackPower;
    int defense;
};
