#include <iostream>
#include "UpdateDisplay.h"

UpdateDisplay::UpdateDisplay (std::string name, Creature& owner) : CreatureAction (owner) {
    std::cout << "UpdateDisplay constructor" << std::endl;
}