#pragma once

#include "enemy/baseEnemy.h"
#include <vector>

using namespace std;

class BaseCharacter {
public:
    struct attackInfo {
        string name;
        string description;
        int minDamage;
        int maxDamage;
        int baseDefense;
    };

    BaseCharacter(int h, vector<attackInfo> ai, int d);
    int getHealth();
    void takeDamage(int damage);

    void addAttack(attackInfo& atk);

    void getAttack(int index, baseEnemy* enemy);
    void listAttacks();

    int getDefense();
    void setDefense(int d);
    //void takeDamage(int damage);

    void attack(baseEnemy* enemy, int damage);
    int getMaxHealth();
    vector<attackInfo> getAttacks();
private:
    int maxHealth;
    int health;
    vector<attackInfo> attacks;
    /*
    attackInfo attack1 = attack(name, gerg, sgeg, ewf)
    attacks.push_back(attack1)
    */
    int defense;
};
