#ifndef ITEM_H_
#define ITEM_H_

#include <iostream>
#include "Creature.h"
#include "Displayable.h"
#include "Action.h"
#include <memory>

//class ItemAction;

class Item : public Displayable {
public:
    Item( );
    virtual void setOwner(std::shared_ptr<Creature> _owner);
    virtual void setAction(std::shared_ptr<ItemAction> _action);
    virtual std::shared_ptr<ItemAction> getAction();
private:
    std::shared_ptr<Creature> owner;
    std::shared_ptr<ItemAction> action;
};
#endif