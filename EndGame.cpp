#include <iostream>
#include "EndGame.h"

EndGame::EndGame (std::string name, Creature& owner) : CreatureAction (owner) {
    std::cout << "EndGame constructor" << std::endl;
}

