#include <iostream>
#include "Item.h"

Item::Item ( ) : Displayable ( ){
    //std::cout << "Item::Item" << std::endl;
}

void Item::setOwner (std::shared_ptr<Creature> _owner) {
    owner = _owner;
    //std::cout << "Item::setOwner" << std::endl;
}

void Item::setAction(std::shared_ptr<ItemAction> _action)
{
    action = _action;
}

std::shared_ptr<ItemAction> Item::getAction()
{
    return action;
}

void Item::setName(std::string _name) {
    name = _name;
}
