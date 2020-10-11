#ifndef ENDGAME_H_
#define ENDGAME_H_

#include <iostream>
#include "Creature.h"

class EndGame : public CreatureAction {
public:
    EndGame(std::string name, Creature& owner);
private:
    std::string name;
    Creature& owner;
}; 
#endif