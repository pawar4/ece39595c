#include <iostream>
#include "Scroll.h"

Scroll::Scroll(std::string _name) : Item( ) {
    name = _name;
    room = 0;
    serial = 0;
    //std::cout << "Scroll::Scroll" << std::endl;
} 

void Scroll::setID (int _room, int _serial) {
    room = _room;
    serial = _serial;
    //std::cout << "Scroll::setID" << std::endl;
    //std::cout << "room: " << std::to_string(room) << " serial: " << std::to_string(serial) << std::endl;
}
