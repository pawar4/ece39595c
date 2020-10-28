#include <iostream>
#include "Armor.h"

Armor::Armor (std::string _name) : Item ( ) {
    name = _name;
    room = 0;
    serial = 0;
    //std::cout << "Armor::Armor" << std::endl;
}

void Armor::setName (std::string _name) {
    name = _name;
    //std::cout << "Armor::setName" << std::endl;
    //std::cout << "Name: " << name << std::endl;
}

void Armor::setID (int _room, int _serial) {
    room = _room;
    serial = _serial;
    //std::cout << "Armor::setID" << std::endl;
    //std::cout << "Room: " << room << std::endl;
    //std::cout << "Serial: " << serial << std::endl;
}
