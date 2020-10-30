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
    ObjDisplayGrid(int _width, int _gameHeight, int _topHeight, int _botHeight);
    ~ObjDisplayGrid(); //added 10/21/20
    virtual std::shared_ptr<ObjDisplayGrid> getObjDisplayGrid(int _width, int gameHeight, int _topHeight);
    virtual void setTopMessageHeight(int _topHeight);
    virtual void addObjectToDisplay(char ch, int x, int y);
    virtual void moveObject(char ch, int newX, int newY, int oldX, int oldY);
    virtual void update();
    virtual void initRoomGrid(std::shared_ptr<Room> room);
    virtual void initPassageGrid(std::shared_ptr<Passage> passage);
    virtual void initCreatureGrid(std::shared_ptr<Creature> creature, std::shared_ptr<Room> room);
    void initItemGrid(std::shared_ptr<Item> item, std::shared_ptr<Room> room);
    std::shared_ptr<Displayable> player;
private:
    int gameHeight, width, topHeight, botHeight;
    static std::shared_ptr<ObjDisplayGrid> instance;
    //GridChar*** objectGrid; //don't know if this is necessary yet
    //int messageLines; //new changes #lines of messages
    GridChar*** objectGrid; 
    
};

#endif