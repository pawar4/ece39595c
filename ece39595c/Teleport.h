#ifndef TELEPORT_H_
#define TELEPORT_H_

#include <iostream>
#include "Creature.h"
#include "Item.h"
#include "Action.h"
#include <memory>

class Teleport : public CreatureAction {
public:
    Teleport(std::string _name, std::shared_ptr<Creature> _owner);
private:
    std::string name;
}; 
#endif