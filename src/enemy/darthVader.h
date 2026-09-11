#include "baseEnemy.cpp"

class darthVader : public baseEnemy {
    private:
        int stamina;
        bool checkTurn(){
            int rand = rand() % 101;
            if(rand <= stamina){return true;}
            else{
                stamina = 100;
                std::cout << "Didn't have enough stamina to attack" << endl;
                return false;
            }
        }
    public:
        darthVader();
        int forcePush();
        int forceHeal();
        int forceChoke();
        int younglingSlayer();
        int throwShit();
        int attack();
};