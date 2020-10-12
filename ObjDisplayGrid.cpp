#include <iostream>
#include "ObjDisplayGrid.h"


std::shared_ptr<ObjDisplayGrid> ObjDisplayGrid::instance = nullptr;

ObjDisplayGrid::ObjDisplayGrid() {
    gameHeight = 0;
    width = 0;
    topHeight = 0;
    std::cout << "ObjDisplayGrid::ObjDisplayGrid" << std::endl;
}

std::shared_ptr<ObjDisplayGrid> ObjDisplayGrid::getObjDisplayGrid(int _gameHeight, int _width, int _topHeight) {
    if (instance == nullptr) {
        instance = std::shared_ptr<ObjDisplayGrid>(new ObjDisplayGrid());
        instance->gameHeight = _gameHeight;
        instance->width = _width;
        instance->topHeight = _topHeight;
    }
    std::cout << "ObjDisplayGrid::getObjDisplayGrid" << std::endl;
    
    return instance;
}

void ObjDisplayGrid::setTopMessageHeight(int _topHeight) {
    instance->topHeight = _topHeight;
    std::cout << "ObjDisplayGrid::setTopMessageHeight" << std::endl;
}