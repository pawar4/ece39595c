#include <iostream>
#include "ChangeDisplayedType.h"

ChangeDisplayedType::ChangeDisplayedType (std::string name, Creature& owner) : CreatureAcion (owner) {
    std::cout << "ChangeDisplayedType constructor" << std::endl;
}