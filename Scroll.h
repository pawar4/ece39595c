#ifndef SCROLL_H_
#define SCROLL_H_

#include <iostream>
#include <string>

#include "Item.h"

class Scroll : public Item {
public:
    Scroll(std::string _name);
    virtual void setID(int _room, int _serial);
private:
    std::string name;
    int room;
    int serial;
};

#endif