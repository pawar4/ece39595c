#ifndef DUNGEON_H_
#define DUNGEON_H_
#include <iostream>
#include "Room.h"
#include "Creature.h"
#include "Item.h"

class Dungeon {

public:
    Dungeon();
    virtual Dungeon& getDungeon(std::string name, int width, int gameHeight);
    virtual void addRoom(Room* room);
    virtual void addCreature(Creature& creature);
    virtual void addPassage(std::string name);
    virtual void addItem(Item& item);

private:
    std::string name;
    int width;
    int gameHeight;
    Room& room;
    Creature& creature;
    std::string passageName;
    Item& item;
};

#endif