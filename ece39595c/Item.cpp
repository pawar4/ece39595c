#include <iostream>
#include "Item.h"

Item::Item ( ) : Displayable ( ){
    std::cout << "Item::Item" << std::endl;
}

void Item::setOwner (std::shared_ptr<Creature> _owner) {
    owner = _owner;
    std::cout << "Item::setOwner" << std::endl;
}