#include <iostream>
#include "Remove.h"

Remove::Remove (std::string _name, std::shared_ptr<Creature> _owner) : CreatureAction (_owner) {
    name = _name;
    //std::cout << "Romove::Remove" << std::endl;
}