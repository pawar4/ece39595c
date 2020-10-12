#ifndef PASSAGE_H_
#define PASSAGE_H_

#include <iostream>
#include "Structure.h"

class Passage : public Structure {
public:
    Passage();
    virtual void Monster();
    virtual void setName(std::string _name);
    virtual void setID(int _room1, int _room2);

private:
    std::string name;
    int room1;
    int room2;
};
#endif