#include <iostream>
#include "UpdateDisplay.h"

UpdateDisplay::UpdateDisplay (std::string _name, std::shared_ptr<Creature> _owner) : CreatureAction (_owner) {
    name = _name;
    //std::cout << "UpdateDisplay::UpdateDisplay" << std::endl;
    //std::cout << "name: " << name << std::endl;
}