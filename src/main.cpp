#include <iostream>
#include "character/baseCharacter.h"

#include <string>

int main() {
    BaseCharacter spy(10, {}, 10);
    BaseCharacter::attackInfo espionage{std::string("Espionage"), std::string("Palantir"), 10, 20, 5};
    spy.addAttack(espionage);

    std::cout << "Hello IVR" << std::endl;
    return 0;
}