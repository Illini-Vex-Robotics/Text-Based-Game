#include <iostream>
#include "character/baseCharacter.h"

#include <string>

int main() {
    //Create spy character + add attacks
    BaseCharacter spy(10, {}, 10);
    BaseCharacter::attackInfo espionage{std::string("Espionage"), std::string("Palantir"), 10, 20, 5};
    BaseCharacter::attackInfo remover{std::string("tactical nuke"), std::string("Sending removal to immediate area"), 20,100,0};
    BaseCharacter::attackInfo pandemic{std::string("COVID-19"), std::string(),};
    BaseCharacter::attackInfo diabetes(std::string("Typ{ 2 Diabetes"), std:: string("Blood Sugar: 670 mg/dL"), 40 , 80 ,2 );
    spy.addAttack(espionage);
    spy.addAttack(remover);
    spy.addAttack(pandemic);

    BaseCharacter 

    
    
    std::cout << "Hello IVR" << std::endl;
    return 0;
}