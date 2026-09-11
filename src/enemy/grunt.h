#include "baseEnemy.cpp"

// grunt will be the easiest enemy in the game
// They suck
class grunt : public baseEnemy {
    private:

    public:
        grunt();
        int basicAttack();
        int specialAttack();
        int heal();
        int getLucky();

    
};