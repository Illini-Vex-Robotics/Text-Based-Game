#include "baseCharacter.h"
#include "baseCharacter.h"
#include <cmath>
#include <random>
#include <limits>

using namespace std;

BaseCharacter::BaseCharacter(int h, vector<BaseCharacter::attackInfo> a, int d) : health(h), attacks(a), defense(d) {}
int BaseCharacter::getHealth(){
    return this->health;
}

void BaseCharacter::takeDamage(int damage){
    health = health - clamp((damage - defense), 0, INT_MAX);
}

//change to void return type in .h and .cpp
//calculate damage random val between min and max
//call take damage
//modify our own defense

void BaseCharacter::getAttack(int index, baseEnemy& enemy){
    if(index < 0 || index > (int)attacks.size()){
        throw out_of_range("Not an attack!");
        return;
    }
    int max_damage = attacks[index].maxDamage;
    int min_damage = attacks[index].minDamage;
    
    // Random
    random_device rd;
    mt19937 gen(rd()); 
    uniform_int_distribution<int> dist(min_damage, max_damage);
    int damage = dist(gen);
    
    attack(enemy, damage);
}

void BaseCharacter::addAttack(attackInfo& atk){
    attacks.push_back(atk);
}

void BaseCharacter::listAttacks() {
    for(attackInfo& a : attacks){
        cout << "Attack name: " + a.name + '\n' + "Attack desc: " + a.description + '\n' + "Damage Range: " + 
        to_string(a.minDamage) + "~" + to_string(a.maxDamage) + '\n' + to_string(a.defenseModifier) << '\n\n';
    }
}

int BaseCharacter::getDefense(){
    return defense;
}
void BaseCharacter::setDefense(int d){
    this->defense = d;
}

// Interaction
void attack(baseEnemy& enemy, int damage){
    enemy.takeDamage(damage);
}

