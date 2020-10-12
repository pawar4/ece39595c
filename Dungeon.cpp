#include <iostream>
#include "Dungeon.h"
#include "Room.h"
#include "Creature.h"
#include "Item.h"

std::shared_ptr<Dungeon> Dungeon::instance = nullptr;

Dungeon::Dungeon() {
    width = 0;
    gameHeight = 0;
    topHeight = 0;
    std::cout << "Dungeon::Dungeon" << std::endl;
}


std::shared_ptr<Dungeon> Dungeon::getDungeon(std::string _name, int _width, int _topHeight, int _gameHeight) {
    if (instance == nullptr) {
        instance = std::shared_ptr<Dungeon>(new Dungeon());
        instance->name = _name;
        instance->width = _width;
        instance->gameHeight = _gameHeight;
        instance->topHeight = _topHeight;
    }
    std::cout << "Dungeon::getDungeon" << std::endl;

    return instance;
}

void Dungeon::addRoom(std::shared_ptr<Room> _room) {
    rooms.resize(rooms.size() + 1);
    rooms.push_back(_room);
}
void Dungeon::addCreature(std::shared_ptr<Creature> _creature) {
    creatures.resize(creatures.size() + 1);
    creatures.push_back(_creature);
    std::cout << "Dungeon::addCreature" << std::endl;
}

void Dungeon::addPassage(std::shared_ptr<Passage> _passage) {
    passages.resize(passages.size() + 1);
    passages.push_back(_passage);
    std::cout << "Dungeon::addPassage" << std::endl;
}

void Dungeon::addItem(std::shared_ptr<Item> _item) {
    items.resize(items.size() + 1);
    items.push_back(_item);
    std::cout << "Dungeon::addItem" << std::endl;
}

