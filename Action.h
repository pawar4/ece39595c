#ifndef ACTION_H_
#define ACTION_H_

#include "Displayable.h"
#include <iostream>
#include "Creature.h"
#include <string>
#include <memory>

class Action {
public:
	Action(int v, int c);
	Action();
	void setMessage(std::string msg);
	void setIntValue(int v);
	void setCharValue(char c);
	virtual std::string getMsg();
private:
	std::string msg;
	int v;
	char c;
};

class CreatureAction : public Action {
public:
	CreatureAction(std::shared_ptr<Creature> owner);
	virtual void setName(std::string _name);
	virtual std::string getName();
private:
	std::string name;

};
class ItemAction : public Action {
public:
	ItemAction(std::shared_ptr<Creature> Owner);
};

class BlessCurseOwner : public ItemAction {
public:	
	BlessCurseOwner(std::shared_ptr<Creature> Owner);
};

class Hallucinate : public ItemAction {
public:
	Hallucinate(std::shared_ptr<Creature> Owner);
};
#endif

