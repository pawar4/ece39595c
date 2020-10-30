#ifndef PASSAGE_H_
#define PASSAGE_H_

#include <iostream>
#include "Structure.h"
#include <string>
#include <memory>
#include <vector>

class Passage : public Structure {
public:
    Passage();
    virtual void Monster();
    virtual void setName(std::string _name);
    virtual void setID(int _room1, int _room2);
    virtual void pushVecX(int posX);
    virtual void pushVecY(int posY);
    virtual std::vector<int> getVecX();
    virtual std::vector<int> getVecY();

private:
    std::string name;
    int room1;
    int room2;
    std::vector<int> posXVec;
    std::vector<int> posYVec;
};
#endif