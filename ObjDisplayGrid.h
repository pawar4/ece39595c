#ifndef OBJDISPLAYGRID_H_
#define OBJDISPLAYGRID_H_

#include <iostream>

class ObjDisplayGrid {

public:
    ObjDisplayGrid();
    ObjDisplayGrid& getObjDisplayGrid(int gameHeight, int width, int topHeight);
    void setTopMessageHeight(int topHeight);
private:
    int gameHeight, width, topHeight;
};

#endif