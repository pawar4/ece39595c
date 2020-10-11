#ifndef CHANGEDISPLAYEDTYPE_H_
#define CHANGEDISPLAYEDTYPE_H_

#include <iostream>
#include "Creature.h"

class ChangeDisplayedType : public CreatureAction {
public:
    ChangeDisplayedType(std::string name, Creature& owner);
private:
    std::string name;
    Creature& owner;
}; 

#endif