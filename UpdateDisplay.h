#ifndef UPDATEDISPLAY_H_
#define UPDATEDISPLAY_H_

#include <iostream>
#include "Creature.h"

class UpdateDisplay : public CreatureAction {
public:
    UpdateDisplay(std::string _name, std::shared_ptr<Creature> _owner);
private:
    std::string name;
}; 
#endif