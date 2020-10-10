#include "Teleport.h"
#include <iostream>

Teleport::Teleport (std::string name, Creature& owner): CreatureAction (owner) {
    std::cout << "Teleport constructor" << std::endl;
}
