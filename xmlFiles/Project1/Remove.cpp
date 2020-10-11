#include <iostream>
#include "Remove.h"

Remove::Remove (std::string name, Creature& owner) : CreatureAction (owner) {
    std::cout << "Romove constructor" << std::endl;
}