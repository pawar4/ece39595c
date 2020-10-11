#ifndef TELEPORT_H_
#define TELEPORT_H_

#include <iostream>
#include "Creature.h"

class Teleport : public CreatureAction {
public:
    Teleport(std::string name, Creature& owner);
private:
    std::string name;
    Creature& owner;
}; 
#endif