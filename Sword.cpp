#include <iostream>
#include "Sword.h"

Sword::Sword (std::string _name) : Item ( ) {
    name = _name;
    room = 0;
    serial = 0;
    //std::cout << "Sword::Sword" << std::endl;
}

void Sword::setID (int _room, int _serial) {
    room = _room;
    serial = _serial;
    //std::cout << "Sword::setID" << std::endl;
    //std::cout << "room: " << std::to_string(room) << " serial: " << std::to_string(serial) << std::endl;

}

std::string Sword::getName()
{
    return name;
}

void Sword::setName(std::string _name)
{
    name = _name;
}
