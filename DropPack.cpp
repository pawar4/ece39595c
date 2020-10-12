#include <iostream>
#include "DropPack.h"
#include "Action.h"

DropPack::DropPack (std::string _name, std::shared_ptr<Creature> _owner) : CreatureAction (_owner) {
    name = _name;
    std::cout << "DropPack::DropPack" << std::endl;
}