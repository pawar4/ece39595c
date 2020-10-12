#include <iostream>
#include "ChangeDisplayedType.h"

ChangeDisplayedType::ChangeDisplayedType (std::string _name, std::shared_ptr<Creature> _owner) : CreatureAcion (_owner) {
    name = _name;
    std::cout << "ChangeDisplayedType::ChangeDisplayedType" << std::endl;
}