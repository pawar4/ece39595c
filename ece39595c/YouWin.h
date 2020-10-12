#ifndef YOUWIN_H_
#define YOUWIN_H_

#include <iostream>
#include "Creature.h"
#include "Action.h"
#include <memory>

class YouWin : public CreatureAction {
public:
    YouWin(std::string _name, std::shared_ptr<Creature> _owner);
private:
    std::string name;
}; 
#endif