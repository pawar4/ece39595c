#include <iostream>
#include "DropPack.h"

DropPack::DropPack (std::string name, Creature& owner) : CreatureAction (owner) {
    std::cout << "DropPack constructor" << std::endl;
}