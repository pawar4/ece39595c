#include <iostream>
#include "Sword.h"

Sword::Sword (std::string name) : Item ( ) {
    std::cout << "Sword constructor" << std::endl;
}

void Sword::setID (int room, int serial) {
    std::cout << "Sword::setID" << std::endl;
}
