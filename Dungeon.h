#ifndef DUNGEON_H_
#define DUNGEON_H_
#include <iostream>
#include <vector>
#include "Room.h"
#include "Creature.h"
#include "Item.h"
#include "Passage.h"
#include <memory>

class Dungeon {

public:
    Dungeon(std::string _name, int _width, int _topHeight, int _gameHeight, int _bottomHeight);
    static std::shared_ptr<Dungeon> getDungeon(std::string _name, int _width, int _topHeight, int _gameHeight, int _bottomHeight);
    virtual void addRoom(std::shared_ptr<Room> _room);
    virtual void addCreature(std::shared_ptr<Creature> _creature);
    virtual void addPassage(std::shared_ptr<Passage> _passage);
    virtual void addItem(std::shared_ptr<Item> item);
    virtual std::vector<std::shared_ptr<Room>> getRooms();
    virtual std::vector<std::shared_ptr<Passage>> getPassages();
    virtual std::vector<std::shared_ptr<Creature>> getCreatures();
    virtual std::vector<std::shared_ptr<Item>> getItems();
    virtual int getWidth();
    virtual int getGameHeight();
    virtual int getTopHeight();
    virtual int getBotHeight();
private:
    std::string name;
    int width;
    int gameHeight;
    int topHeight;
    int bottomHeight;
    static std::shared_ptr<Dungeon> instance; //must access instance in order to use height and width lol
    std::vector<std::shared_ptr<Room>> rooms;
    std::vector<std::shared_ptr<Creature>> creatures;
    std::vector<std::shared_ptr<Passage>> passages;
    std::vector<std::shared_ptr<Item>> items;
};

#endif