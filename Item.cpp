#include <iostream>
#include "Item.h"

Item::Item ( ) {
    std::cout << "Item constructor" << std::endl;
}

void Item::setOwner (Creature& owner) {
    std::cout << "Item::setOwner" << std::endl;
}