#ifndef PASSAGE_H_
#define PASSAGE_H_

#include <iostream>
#include "Structure.h"

class Passage : public Structure {
public:
    Passage();
    virtual void Monstor();
    virtual void setName(std::string name);
    virtual void setID(int room1, int room2);

private:
    std::string name;
    int room1;
    int room2;
};
#endif