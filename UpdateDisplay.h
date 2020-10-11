#ifndef UPDATEDISPLAY_H_
#define UPDATEDISPLAY_H_

#include <iostream>
#include "Creature.h"

class UpdateDisplay : public CreatureAction {
public:
    UpdateDisplay(std::string name, Creature& owner);
private:
    std::string name;
    Creature& owner;
}; 
#endif