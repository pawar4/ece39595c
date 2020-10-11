#include <iostream>
#include "ObjDisplayGrid.h"

ObjDisplayGrid::ObjDisplayGrid() {
    std::cout << "ObjDisplayGrid constructor" << std::endl;
}

ObjDisplayGrid& ObjDisplayGrid::getObjDisplayGrid(int gameHeight, int width, int topHeight) {
    std::cout << "ObjDisplayGrid::getObjDisplayGrid" << std::endl;
}

void ObjDisplayGrid::setTopMessageHeight(int topHeight) {
    std::cout << "ObjDisplayGrid::setTopMessageHeight" << std::endl;
}