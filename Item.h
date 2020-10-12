#ifndef ITEM_H_
#define ITEM_H_

#include <iostream>
#include "Creature.h"
#include "Displayable.h"

class Item : public Displayable {
public:
    Item( );
    virtual void setOwner (std::shared_ptr<Creature> _owner);

private:
    std::shared_ptr<Creature> owner;
};

#endif