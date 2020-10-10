#include <iostream>
#include "YouWin.h"

YouWin::YouWin (std::string name, Creature& owner) : CreatureAction (owner) {
    std::cout << "YouWin constructor" << std::endl;
}
