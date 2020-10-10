#ifndef REMOVE_H_
#define REMOVE_H_

#include <iostream>
#include "Creature.h"

class Remove : public CreatureAction {
public:
    Remove(std::string name, Creature& owner);
private:
    std::string name;
    Creature& owner;
}; 
#endif