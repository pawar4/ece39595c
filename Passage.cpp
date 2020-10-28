#include <iostream>
#include "Passage.h"

Passage::Passage() : Structure() {
    name = "";
    room1 = 0;
    room2 = 0;
    //std::cout << "Passage::Passage" << std::endl;
}

void Passage::Monster() {
    std::cout << "Passage::Monster" << std::endl;
}

void Passage::setName(std::string _name) {
    name = _name;
    //std::cout << "Passage::setName" << std::endl;
    //std::cout << "Name: " << name << std::endl;
}

void Passage::setID(int _room1, int _room2) {
    room1 = _room1;
    room2 = _room2;
    //std::cout << "Passage::setID" << std::endl;
    //std::cout << "room1: " << room1 << " " << "room2: " << room2 << std::endl;
}

void Passage::pushVecX(int _posX) {
    posXVec.push_back(_posX);
}

void Passage::pushVecY(int _posY) {
    posYVec.push_back(_posY);
}

std::vector<int> Passage::getVecX()
{
    return posXVec;
}

std::vector<int> Passage::getVecY()
{
    return posYVec;
}
