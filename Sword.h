#ifndef SWORD_H_
#define SWORD_H_

#include <iostream>
#include "Item.h"

class Sword : public Item {
public:
    Sword(std:string name);
    virtual void setID(int room, int serial);

private:
    std::string name;
    int room, serial;
};

#endif