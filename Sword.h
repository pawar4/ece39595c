#ifndef SWORD_H_
#define SWORD_H_

#include <iostream>
#include <string>
#include "Item.h"
#include <memory>

class Sword : public Item {
public:
    Sword(std::string _name);
    virtual void setID(int _room, int serial);

private:
    std::string name;
    int room, serial;
};

#endif