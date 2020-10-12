#include <iostream>
#include "EndGame.h"

EndGame::EndGame (std::string _name, std::shared_ptr<Creature> _owner) : CreatureAction (_owner) {
    name = _name;
    std::cout << "EndGame::EndGame" << std::endl;
    std::cout << "Name: " << name << std::endl;
}

