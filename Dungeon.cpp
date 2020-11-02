#include <iostream>
#include "Dungeon.h"
#include "Room.h"
#include "Creature.h"
#include "Item.h"

std::shared_ptr<Dungeon> Dungeon::instance = nullptr;

Dungeon::Dungeon(std::string _name, int _width, int _topHeight, int _gameHeight, int _bottomHeight) {
    name = _name;
    width = _width;
    gameHeight = _gameHeight;
    topHeight = _topHeight;
    bottomHeight = _bottomHeight;
    //std::cout << "Dungeon::Dungeon" << std::endl;
}


std::shared_ptr<Dungeon> Dungeon::getDungeon(std::string _name, int _width, int _topHeight, int _gameHeight, int _bottomHeight) {
    if (instance == nullptr) {
        instance = std::shared_ptr<Dungeon>(new Dungeon(_name, _width, _topHeight, _gameHeight, _bottomHeight));
        instance->name = _name; /*Ik This is stupid I will fix this later 10/27/2020. Don't know how to use instance*/
        instance->width = _width;
        instance->gameHeight = _gameHeight;
        instance->topHeight = _topHeight;
        instance->topHeight = _bottomHeight;
        //std::cout << "Dungeon::Dungeon" << std::endl;
    }
    
    //std::cout << "Dungeon::getDungeon" << std::endl;
    //std::cout << "Name: " << instance -> name << std::endl;
    //std::cout << "Width: " << std::to_string(instance->width) << std::endl;
    //std::cout << "topHeight: " << std::to_string(instance->topHeight) << std::endl;
    //std::cout << "gameHeight: " << std::to_string(instance->gameHeight) << std::endl;


    return instance;
}

void Dungeon::addRoom(std::shared_ptr<Room> _room) {
    //rooms.resize(rooms.size() + 1);
    rooms.push_back(_room);
}
void Dungeon::addCreature(std::shared_ptr<Creature> _creature) {
    //creatures.resize(creatures.size() + 1);
    creatures.push_back(_creature);
    //std::cout << "Dungeon::addCreature" << std::endl;
}

void Dungeon::addPassage(std::shared_ptr<Passage> _passage) {
    //passages.resize(passages.size() + 1);
    passages.push_back(_passage);
    //std::cout << "Dungeon::addPassage" << std::endl;
}

void Dungeon::addItem(std::shared_ptr<Item> _item) {
    //items.resize(items.size() + 1);
    items.push_back(_item);
    //std::cout << "Dungeon::addItem" << std::endl;
}

std::vector<std::shared_ptr<Room>> Dungeon::getRooms()
{
    return rooms;
}

std::vector<std::shared_ptr<Passage>> Dungeon::getPassages()
{
    return passages;
}

std::vector<std::shared_ptr<Creature>> Dungeon::getCreatures()
{
    return creatures;
}

std::vector<std::shared_ptr<Item>> Dungeon::getItems()
{
    return items;
}

int Dungeon::getWidth()
{
    return width;
}

int Dungeon::getGameHeight()
{
    return gameHeight;
}

int Dungeon::getTopHeight()
{
    return topHeight;
}

int Dungeon::getBotHeight()
{
    return bottomHeight;
}

