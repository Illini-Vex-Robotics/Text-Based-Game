#pragma once
#include <iostream>
#include <string>
#include <cstdlib>

// Base class every enemy in the game derives from.
//
// Subclasses must implement the two pure virtuals:
//   pickMove() - rolls for and returns the id of the move the enemy uses this
//                turn. The ids are the subclass's own `move` enum values.
//   attack()   - runs the move pickMove() chose and returns the damage dealt
//                to the player (0 when the move only heals or fizzles).
class baseEnemy {
    protected:
        int health;
        int maxHealth;

    public:
        baseEnemy();
        baseEnemy(int maxH);
        // Enemies are owned and deleted through baseEnemy*, so this must be virtual.
        virtual ~baseEnemy() = default;

        virtual void takeDamage(int damageTaken) { health -= damageTaken; }
        virtual int getHealth() { return health; }
        // Sets health to h, clamped to [0, maxHealth].
        virtual void setHealth(int h);
        virtual bool isDead();
        virtual int pickMove() = 0;
        virtual int attack() = 0;
};
