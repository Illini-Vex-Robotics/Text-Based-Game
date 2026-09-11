#include "baseEnemy.cpp"
#include <cstdlib>
#include <vector>

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
        int forcePush(){
            if(checkTurn()){
                if (health + 10 <= maxHealth){health += 10;}
                else{health = maxHealth;}
                    stamina = 80;
                    std::cout << "Darth Vader used force push" << endl;
                    return 30;
            }
            return 0;
        }
        int forceHeal(){
            if(checkTurn()){
                health = maxHealth;
                stamina = 80
                std::cout << "Darth Vader used force heal" << endl;
            }
            return 0;
        }
        int forceChoke(){
            if(checkTurn()){
                stamina = 20;
                std::cout << "Darth Vader used force heal" << endl;
                return 80;
            }
            return 0;
        }
        int younglingSlayer(){
            if(checkTurn()){
                stamina = 0;
                std::cout << "Darth Vader thought your were a youngling" << endl;
                return 100;
            }
            return 0;
        }
        int throwShit(){
            if(checkTurn()){
                stamina = 40;
                std::cout << "Darth Vader threw shit at you" << endl;
                return 60;
            }
            return 0;
        }
        int attack(){
            rand = rand() % 5;
            if (rand == 0){return forcePush();}
            else if (rand == 1){return forceHeal();}
            else if (rand == 2){return forceChoke();}
            else if (rand == 3){return younglingSlayer();}
            else{return throwShit();}
        }
};