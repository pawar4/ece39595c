#ifndef REMOVE_H_
#define REMOVE_H_

#include <iostream>
#include "Creature.h"
#include "Action.h"
#include <memory>

class Remove : public CreatureAction {
public:
    Remove(std::string _name, std::shared_ptr<Creature> _owner);
private:
    std::string name;
}; 
#endif