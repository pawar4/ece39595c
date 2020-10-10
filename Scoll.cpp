#include <iostream>
#include "Scroll.h"

Scroll::Scroll (std::string name) {
    std::cout << "Scroll constructor" << std::endl;
} 

void Scroll::setID (int room, int serial) {
    std::cout << "Scroll::setID" << std::endl;
}
