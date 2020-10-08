#include <iostream>
#include "Dungeon.h"
#include "Room.h"
#include "Creature.h"
#include "Item.h"

Dungeon::Dungeon() {
    std::cout << "Dungeon Constructor" << std::endl;
}

Dungeon& Dungeon::getDungeon(std::string name, int width, int gameHeight) {
    std::cout << "Dungeon::getDungeon" << std::endl;
}

void Dungeon::addRoom(Room& room) {
    std::cout << "Dungeon::addRoom" << std::endl;
}

void Dungeon::addCreature(Creature& creature) {
    std::cout << "Dungeon::addCreature" << std::endl;
}

void Dungeon::addPassage(std::string name) {
    std::cout << "Dungeon::addPassage" << std::endl;
}

void Dungeon::addItem(Item& item) {
    std::cout << "Dungeon::addItem" << std::endl;
}

