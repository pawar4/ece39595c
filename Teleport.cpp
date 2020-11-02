#include "Teleport.h"
#include <iostream>

Teleport::Teleport (std::string _name, std::shared_ptr<Creature> _owner): CreatureAction (_owner) {
    name = _name;
    //std::cout << "Teleport::Teleport" << std::endl;
    //std::cout << "name: " << name << std::endl;

}
