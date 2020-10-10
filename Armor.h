#ifndef ARMOR_H_
#define ARMOR_H_

#include <iostream>
#include "Item.h"

class Armor : public Item {
public:
    Armor(std::string name);
    virtual void setName(std::string name);
    virtual void setID(int room, int serial);

private:
    std::string name;
    int room, serial;
}
#endif