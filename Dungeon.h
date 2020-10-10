#ifndef DUNGEON_H_
#define DUNGEON_H_
#include <iostream>

class Dungeon {

public:
    Dungeon();
    Dungeon& getDungeon(std::string name, int width, int gameHeight);
    void addRoom(Room& room);
    void addCreature(Creature& creature);
    void addPassage(std::string name);
    void addItem(Item& item);

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