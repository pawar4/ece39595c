#include <iostream>
#include "Armor.h"

Armor::Armor (std::string name) : Item ( ) {
    std::cout << "Armor constructor" << std::endl;
}

void Armor::setName (std::string name) {
    std::cout << "Armor::setName" << std::endl;
}

void Armor::setID (int room, int serial) {
    std::cout << "Armor::setID" << std::endl;
}
