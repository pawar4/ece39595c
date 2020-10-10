#ifndef ROOM_H_
#define ROOM_H_

#include <iostream>
#include "Creature.h"
#include "Structure.h"

class Room : public Structure {
public:
    Room(std::string name);
    virtual void setID(int room);
    virtual void setCreate(Creature& monstor);
private:
    std::string name;
    int room;
    Creature& monstor;
};
#endif