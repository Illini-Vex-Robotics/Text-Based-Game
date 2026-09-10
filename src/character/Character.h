#pragma once

class Enemy;

class Character {
    public:
        Character(int h, int a, int d);

        int getHealth();
        int getAttack();
        int getDefense();
        
        void takeDamage(int damage);
        void attack(Enemy& target);
    private:
        int hp;
        int atk;
        int def;
};