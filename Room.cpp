#include <iostream>
#include "Room.h"

Room::Room (std::string name) : Structure() {
    std::cout << "Room constructor" << std::endl;
}

void Room::setID(int room) {
    std::cout << "Room::setID" << std::endl;
}

void Room::setCreature (Creature& monstor) {
    std::cout << "Room::setCreature" << std::endl;
}

