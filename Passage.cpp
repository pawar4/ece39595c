#include <iostream>
#include "Passage.h"

Passage::Passage() : Structure() {
    std::cout << "Passage constructor" << std::endl;
}

void Passage::setName(std::string name) {
    std::cout << "Passage::setName" << std::endl;
}

void Passage::setID(int room1, int room2) {
    std::cout << "Passage::setName" << std::endl;
}