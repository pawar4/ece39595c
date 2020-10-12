#ifndef CHANGEDISPLAYEDTYPE_H_
#define CHANGEDISPLAYEDTYPE_H_

#include <iostream>
#include "Action.h"

class ChangeDisplayedType : public CreatureAction {
public:
    ChangeDisplayedType(std::string _name, std::shared_ptr<Creature> _owner);
private:
    std::string name;
}; 

#endif