#include <iostream>

#include "character/baseCharacter.h"
#include "enemy/baseEnemy.h"
#include "enemy/grunt.h"
#include "enemy/darthVader.h"
#include "enemy/gambler.h"
#include "enemy/Joker.h"

#include <string>

void addSpyAttacks(BaseCharacter& spy) {
    BaseCharacter::attackInfo espionage{std::string("Espionage"), std::string("Gain info about next enemy attack to raise defense\n5-8 damage\nRaises defense by 15"), 5, 8, 15};
    BaseCharacter::attackInfo gadget{std::string("Gadget"), std::string("Use one of your gadgets, who knows if it'll be good\n0-40 damage"), 0,40,0};
    BaseCharacter::attackInfo stealthAttack{std::string("Stealth attack"), std::string("Avoid detection and attack your enemy\n15-25 damage\nRaises defense by 10 by being sneaky"), 1,100,10};
    BaseCharacter::attackInfo doubleO7{std::string("007"), std::string("License to kill\n20-25 damage"), 20,25,0};
    spy.addAttack(espionage);
    spy.addAttack(gadget);
    spy.addAttack(stealthAttack);
    spy.addAttack(doubleO7);
}

void addIronManAttacks (BaseCharacter& ironMan) {
    BaseCharacter::attackInfo laser_beam{std::string("Laser Beam"), std::string("Shoot a laser beam at the enemy\nVery accurate but low damage\n4-5 damage"), 4, 5, 0};
    BaseCharacter::attackInfo laser_pulse{std::string("Laser Pulse"), std::string("Shoot a laser pulse at the enemy\nNot very accurate, but high damage potential\n1-9 damage"), 1, 9, 0};
    BaseCharacter::attackInfo armor_reinforcement{std::string("Armor Reinforcement"), std::string("Strengthen Iron Man's armor\nRaise defense by 30"), 0, 0, 30};
    ironMan.addAttack(laser_beam);
    ironMan.addAttack(laser_pulse);
    ironMan.addAttack(armor_reinforcement);
}

void addHulkAttacks (BaseCharacter& hulk) {
    BaseCharacter::attackInfo left_handed_punch {std::string("Left Handed Punch"), std::string("Deliver a brutal left handed jab at the enemy\nNot very accurate but medium-level damage\n4-6 damage"),4,6,0};
    BaseCharacter::attackInfo right_handed_punch {std::string("Left Handed Punch"), std::string("Deliver a brutal right handed jab at the enemy\nVery accurate and high damage potential\n7-9 damage\nConfidence boost: Raise defense by 5"),7,9,5};
    BaseCharacter::attackInfo chuck_car {std::string("Chuck Car"), std::string("Launch a random car at your enemy\n Hit or miss, but depending on the size of the car, high damage could be dealt\n1-9 damage"),1,9,0};
    hulk.addAttack(left_handed_punch);
    hulk.addAttack(right_handed_punch);
    hulk.addAttack(chuck_car);
}   

void titleScreen(){
    std::cout << "\tWelcome to Crossed Lines!" << std::endl;
    for (int i = 0; i < 20; i++){std::cout << "-";}
}

//pass in a player reference and enemy reference, make sure they are both t
bool checkPlaying(BaseCharacter& player, baseEnemy* enemy) {
    if (player.getHealth() == 0) {
        std::cout << "The player has died a heroic death.";
        return false;
    }
    if (enemy->getHealth() <= 0) {
        std::cout << "The enemey has died a brutal death.";
        return false;
    }
}

void displayHealthBar(int health, int max) {
    int maxWidth = 20;
    int width = (health * maxWidth) / max;
    std::string curr = "";
    for (int i = 0; i < width; ++i) {
        curr += "█";
    }
    for (int i = 0; i < maxWidth - width; ++i) {
        curr += "░";
    }
    std::cout << "\nHealth: " + curr;
}

void characterTurn(BaseCharacter& character, baseEnemy* enemy) {
    std::cout << "\nSelect an attack:";
    character.listAttacks();
    int attack;
    while (!(std::cin >> attack && attack > 0 && attack < character.getAttacks().size())) {
        std::cout << "Invalid input, try again!: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    character.getAttack(attack, enemy);
    displayHealthBar(character.getHealth(), character.getMaxHealth());
}

void enemyTurn(BaseCharacter & character, baseEnemy* enemy) {
    std::cout << "\n\nSelect an attack:";
    int damageDone = enemy->attack();
    character.takeDamage(damageDone);
}

int main() {

    int selection;
    std::cout << "\nSelect a character:\n1. Spy\n2. Iron Man\n3. Hulk\n";
    while (!(std::cin >> selection && selection > 0 && selection < 4)) {
        std::cout << "Invalid input, try again!: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    BaseCharacter spy(50, {}, 10);
    BaseCharacter selectedCharacter = spy;
    if (selection == 1) {
        addSpyAttacks(spy);
    } else if (selection == 2) {
        BaseCharacter ironMan(75, {}, 20);
        addIronManAttacks(ironMan);
        selectedCharacter = ironMan;
    } else if (selection == 3) {
        BaseCharacter hulk(90, {}, 25);
        addHulkAttacks(hulk);
        selectedCharacter = hulk;
    }
    std::vector<baseEnemy*> enemyList = {};
    grunt* enemyGrunt = new grunt();
    enemyList.insert(enemyList.begin(), enemyGrunt);
    for (int i = 0; i < enemyList.size(); i++) {
        auto currEnemy = enemyList.at(i);
        for (bool gamePlaying = true; gamePlaying != false; gamePlaying = checkPlaying(selectedCharacter, currEnemy)) {
            characterTurn(selectedCharacter, currEnemy);
            enemyTurn(selectedCharacter,currEnemy);
        }
    }

    std::cout << "Hello IVR" << std::endl;
    delete enemyGrunt;
    return 0;
}


