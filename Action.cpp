#include "Action.h"
Action::Action(int _v, int _c) : v(_v), c(_c) {
	//std::cout << "Action Constructor" << std::endl;
}
Action::Action() : v(0), c(0) {
	//std::cout << "Action Constructor" << std::endl;
}
void Action::setMessage(std::string _msg) {
	msg = _msg;
	//std::cout << "Action::setMessage" << std::endl;
	//std::cout << msg << std::endl;
}

void Action::setIntValue(int _v) {
	v = _v;
	//std::cout << "Action::setIntValue" << std::endl;
	//std::cout << "Int Value: "<< std::to_string(v) << std::endl;
}

void Action::setCharValue(char _c) {
	c = _c;
	//std::cout << "Action::setCharValue" << std::endl;
	//std::cout << "Char Value: " << c << std::endl;
}

std::string Action::getMsg()
{
	return msg;
}

char Action::getCharVal()
{
	return c;
}

int Action::getIntValue()
{
	return v;
}

std::string Action::getMessage()
{
	return msg;
}

CreatureAction::CreatureAction(std::shared_ptr<Creature> owner) {
	//std::cout << "CreatureAction Constructor" << std::endl;
}

void CreatureAction::setName(std::string _name)
{
	name = _name;
}

std::string CreatureAction::getName()
{
	return name;
}

/*ItemAction::ItemAction(std::shared_ptr<Item> owner) {
	//std::cout << "ItemAction Constructor" << std::endl;
}*/

void ItemAction::setName(std::string _name)
{
	name = _name;
}

std::string ItemAction::getName()
{
	return name;
}

/*BlessCurseOwner::BlessCurseOwner(std::shared_ptr<Item> Owner) : ItemAction(Owner) {
	//std::cout << "BlessCurseOwner Constructor" << std::endl;
}

Hallucinate::Hallucinate(std::shared_ptr<Item> Owner) :ItemAction(Owner) {
	//std::cout << "Hallucinate Constructor" << std::endl;
}*/
