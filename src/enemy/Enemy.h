#pragma once

class Enemy {
    public:
        Enemy(int h, int a, int d);

        int getHealth();
        int getAttack();
        int getDefense();
        
        void takeDamage(int damage);
    private:
        int health;
        int attack;
        int defense;
};