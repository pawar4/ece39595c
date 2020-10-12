#ifndef ROOM_H_
#define ROOM_H_

#include <iostream>
#include <vector>
#include <string>
#include "Creature.h"
#include "Structure.h"

class Room : public Structure {
public:
    Room(std::string _name);
    virtual void setID(int _room);
    virtual void setCreature(std::shared_ptr<Creature> _monstor);
private:
    std::string name;
    int room;
    std::vector<std::shared_ptr<Creature>> monsters;
};
#endif