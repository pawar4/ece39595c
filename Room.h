#ifndef ROOM_H_
#define ROOM_H_

#include <iostream>
#include <vector>
#include <string>
#include "Creature.h"
#include "Structure.h"
#include "Item.h"
#include <memory>

class Room : public Structure {
public:
    Room(std::string _name);
    virtual void setID(int _room);
    virtual void setCreature(std::shared_ptr<Creature> _monster);
    virtual std::vector<std::shared_ptr<Creature>> getCreatures();
    virtual void setItem(std::shared_ptr<Item> _item);
    std::vector<std::shared_ptr<Item>> getItems();
private:
    std::string name;
    int room;
    std::vector<std::shared_ptr<Creature>> creatures;
    std::vector<std::shared_ptr<Item>> items;
};
#endif