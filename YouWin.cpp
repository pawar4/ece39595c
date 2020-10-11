#include <iostream>
#include "YouWin.h"

YouWin::YouWin (std::string _name, std::shared_ptr<Creature> _owner) : CreatureAction (_owner) {
    name = _name;
    std::cout << "YouWin::YouWin" << std::endl;
}
