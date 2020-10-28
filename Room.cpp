#include <iostream>
#include "Room.h"

Room::Room (std::string _name) : Structure() {
    name = "";
    room = 0;
    creatures.resize(0);
    //std::cout << "Room constructor" << std::endl;
}

void Room::setID(int _room) {
    room = _room;
    //std::cout << "Room::setID" << std::endl;
    //std::cout << "Room: " << std::to_string(room) << std::endl;
}

void Room::setCreature (std::shared_ptr<Creature> _creature) {
    //monsters.resize(monsters.size() + 1);
   creatures.push_back(_creature);
    //std::cout << "Room::setCreature" << std::endl;
}

std::vector<std::shared_ptr<Creature>> Room::getCreatures()
{
    return creatures;
}


