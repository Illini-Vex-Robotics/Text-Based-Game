#include "Joker.h"

joker::joker(){
    maxHealth = 100;
    health = maxHealth;
    stamina = 100;
}
joker::fakeGun(){
    if(checkTurn()){
        if (health + 10 <= maxHealth){health += 10;}
        else{health = maxHealth;}
        stamina = 80;
        std::cout << "Joker used a fake gun" << endl;
        return 30;
    }
    return 0;
}
joker::eatPie(){
    if(checkTurn()){
        health = maxHealth;
        stamina = 80
        std::cout << "Joker ate a pie" << endl;
    }
    return 0;
}
joker::laughingGas(){
    if(checkTurn()){
        stamina = 20;
        std::cout << "Joker threw laughing gas at you" << endl;
        return 80;
    }
    return 0;
}
joker::nuclearBomb(){
    if(checkTurn()){
        stamina = 0;
        std::cout << "Joker sent a nuclear bomb at you" << endl;
        return 100;
    }
    return 0;
}
joker::explosivePie(){
    if(checkTurn()){
        stamina = 40;
        std::cout << "Joker threw an explosive pie at you" << endl;
        return 60;
    }
    return 0;
}
joker::attack(){
    rand = rand() % 5;
    if (rand == 0){return fakeGun();}
    else if (rand == 1){return eatPie();}
    else if (rand == 2){return laughingGas();}
    else if (rand == 3){return nuclearBomb();}
    else{return explosivePie();}
}