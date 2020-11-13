#ifndef ARMOR_H_
#define ARMOR_H_

#include <iostream>
#include <string>
#include "Item.h"
#include <memory>

class Armor : public Item {
public:
    Armor(std::string name);
    virtual void setName(std::string _name);
    virtual void setID(int room, int serial);
    virtual std::string getName();
private:
    std::string name;
    int room, serial;
};

#endif