#ifndef ITEM_H_
#define ITEM_H_

#include <iostream>
#include "Creature.h"

class Item {
public:
    Item ();
    void virtual setOwner (Creature& owner);

private:
    Creature& owner;
};

#endif