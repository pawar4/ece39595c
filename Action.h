#ifndef ACTION_H_
#define ACTION_H_

#include "Displayable.h"
#include <iostream>
#include "Creature.h"
#include <string>
#include <memory>

class Item;

class Action {
public:
	Action(int _v, int _c);
	Action();
	void setMessage(std::string _msg);
	void setIntValue(int _v);
	void setCharValue(char _c);
	virtual std::string getMsg();
	virtual char getCharVal();
	virtual int getIntValue();
	virtual std::string getMessage();
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
	//ItemAction(std::shared_ptr<Item> Owner);
	virtual void setName(std::string _name);
	virtual std::string getName();
private:
	std::string name;
};

class BlessCurseOwner : public ItemAction {
public:	
	//BlessCurseOwner(std::shared_ptr<Item> Owner);
};

class Hallucinate : public ItemAction {
public:
	//Hallucinate(std::shared_ptr<Item> Owner);
};
#endif

