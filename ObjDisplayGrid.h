#ifndef OBJDISPLAYGRID_H_
#define OBJDISPLAYGRID_H_

#include <iostream>
#include <string>
#include <memory>
#include "GridChar.h"
#include "Room.h"
#include "Passage.h"
#include "Displayable.h"
class ObjDisplayGrid {

public:
    //ObjDisplayGrid(); //change to constructor with parameters
    ObjDisplayGrid(int _width, int _gameHeight, int _topHeight);
    ~ObjDisplayGrid(); //added 10/21/20
    virtual std::shared_ptr<ObjDisplayGrid> getObjDisplayGrid(int _gameHeight, int _width, int _topHeight);
    virtual void setTopMessageHeight(int _topHeight);
    void addObjectToDisplay(GridChar* ch, int x, int y);
    void update();
    void initRoomGrid(std::shared_ptr<Room> room);
    void initPassageGrid(std::shared_ptr<Passage> passage);
    void initCreatureGrid(std::shared_ptr<Creature> creature);
private:
    int gameHeight, width, topHeight;
    static std::shared_ptr<ObjDisplayGrid> instance;
    //GridChar*** objectGrid; //don't know if this is necessary yet
    //int messageLines; //new changes #lines of messages
    GridChar*** objectGrid; 
    
};

#endif