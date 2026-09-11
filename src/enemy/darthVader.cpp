#include "darthVader.h"

darthVader::darthVader(){
    maxHealth = 300;
    health = maxHealth;
    stamina = 100;
}
darthVader::forcePush(){
    if(checkTurn()){
        if (health + 10 <= maxHealth){health += 10;}
        else{health = maxHealth;}
        stamina = 80;
        std::cout << "Darth Vader used force push" << endl;
        return 30;
    }
    return 0;
}
darthVader::forceHeal(){
    if(checkTurn()){
        health = maxHealth;
        stamina = 80
        std::cout << "Darth Vader used force heal" << endl;
    }
    return 0;
}
darthVader::forceChoke(){
    if(checkTurn()){
        stamina = 20;
        std::cout << "Darth Vader used force heal" << endl;
        return 80;
    }
    return 0;
}
darthVader::younglingSlayer(){
    if(checkTurn()){
        stamina = 0;
        std::cout << "Darth Vader thought your were a youngling" << endl;
        return 100;
    }
    return 0;
}
darthVader::throwShit(){
    if(checkTurn()){
        stamina = 40;
        std::cout << "Darth Vader threw shit at you" << endl;
        return 60;
    }
    return 0;
}
darthVader::attack(){
    rand = rand() % 5;
    if (rand == 0){return forcePush();}
    else if (rand == 1){return forceHeal();}
    else if (rand == 2){return forceChoke();}
    else if (rand == 3){return younglingSlayer();}
    else{return throwShit();}
}