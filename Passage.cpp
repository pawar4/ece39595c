#include <iostream>
#include "Passage.h"

Passage::Passage() : Structure() {
    name = "";
    room1 = 0;
    room2 = 0;
    std::cout << "Passage::Passage" << std::endl;
}

void Passage::Monster() {
    std::cout << "Passage::Monster" << std::endl;
}

void Passage::setName(std::string _name) {
    name = _name;
    std::cout << "Passage::setName" << std::endl;
}

void Passage::setID(int _room1, int _room2) {
    room1 = _room1;
    room2 = _room2;
    std::cout << "Passage::setName" << std::endl;
}