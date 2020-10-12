#ifndef OBJDISPLAYGRID_H_
#define OBJDISPLAYGRID_H_

#include <iostream>
#include <string>
#include <memory>

class ObjDisplayGrid {

public:
    ObjDisplayGrid();
    virtual std::shared_ptr<ObjDisplayGrid> getObjDisplayGrid(int _gameHeight, int _width, int _topHeight);
    virtual void setTopMessageHeight(int _topHeight);
private:
    int gameHeight, width, topHeight;
    static std::shared_ptr<ObjDisplayGrid> instance;
};

#endif