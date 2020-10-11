#ifndef ENDGAME_H_
#define ENDGAME_H_

#include <iostream>
#include "Creature.h"

class EndGame : public CreatureAction {
public:
    EndGame(std::string _name, std::shared_ptr<Creature> _owner);
private:
    std::string name;
}; 
#endif