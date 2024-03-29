#ifndef DROPPACK_H_
#define DROPPACK_H_

#include <iostream>
#include "Creature.h"
#include "Item.h"
#include "Action.h"
#include <memory>

class DropPack : public CreatureAction {
public:
    DropPack(std::string _name, std::shared_ptr<Creature> _owner);
private:
    std::string name;
}; 
#endif