#ifndef SCROLL_H_
#define SCROLL_H_

#include <iostream>
#include "Item.h"

class Scroll : public Item {
public:
    Scroll(std::string name);
    virtual void setID(int room, int serial);
private:
    int room;
    int serial;
};

#endif