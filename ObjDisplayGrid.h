#ifndef OBJDISPLAYGRID_H_
#define OBJDISPLAYGRID_H_

#include <iostream>
#include <string>
#include <memory>
#include "GridChar.h"

class ObjDisplayGrid {

public:
    //ObjDisplayGrid(); //change to constructor with parameters
    ObjDisplayGrid(int _width, int _gameHeight, int _topHeight);
    ~ObjDisplayGrid(); //added 10/21/20
    virtual std::shared_ptr<ObjDisplayGrid> getObjDisplayGrid(int _gameHeight, int _width, int _topHeight);
    virtual void setTopMessageHeight(int _topHeight);
    void addObjectToDisplay(GridChar* ch, int x, int y);
    void update();
private:
    int gameHeight, width, topHeight;
    static std::shared_ptr<ObjDisplayGrid> instance;
    //GridChar*** objectGrid; //don't know if this is necessary yet
    //int messageLines; //new changes #lines of messages
    GridChar*** objectGrid; //Will need to figure out later how to make an array of pointers to pointers
    
};

#endif