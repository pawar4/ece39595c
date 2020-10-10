#ifndef DROPPACK_H_
#define DROPPACK_H_

#include <iostream>
#include "Creature.h"

class DropPack : public CreatureAction {
public:
    DropPack(std::string name, Creature& owner);
private:
    std::string name;
    Creature& owner;
}; 
#endif