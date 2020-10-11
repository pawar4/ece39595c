#ifndef YOUWIN_H_
#define YOUWIN_H_

#include <iostream>
#include "Creature.h"

class YouWin : public CreatureAction {
public:
    YouWin(std::string name, Creature& owner);
private:
    std::string name;
    Creature& owner;
}; 
#endif