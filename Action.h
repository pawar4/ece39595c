#ifndef ACTION_H_
#define ACTION_H_
#include "Creature.h"
#include "Displayable.h"
#include <iostream>

class Action {
public:
	Action(int v, int c);
	Action();
	void setMessage(std::string msg);
	void setIntValue(int v);
	void setCharValue(char c);
private:
	std::string msg;
	int v = 0;
	int c = 1;
};

class CreatureAction : public Action {
public:
	CreatureAction(std::shared_ptr<Creature> owner);

};
class ItemAction : public Action {
public:
	ItemAction(int Owner);
};

class BlessCurseOwner : public ItemAction {
public:	
	BlessCurseOwner(int Owner);
};

class Hallucinate : public ItemAction {
public:
	Hallucinate(int Owner);
};
#endif

