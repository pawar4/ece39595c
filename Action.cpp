#include "Action.h"
Action::Action(int v, int c) : v(v), c(c) {
	//std::cout << "Action Constructor" << std::endl;
}
Action::Action() : v(0), c(0) {
	//std::cout << "Action Constructor" << std::endl;
}
void Action::setMessage(std::string msg) {
	msg = msg;
	//std::cout << "Action::setMessage" << std::endl;
	//std::cout << msg << std::endl;
}

void Action::setIntValue(int v) {
	v = v;
	//std::cout << "Action::setIntValue" << std::endl;
	//std::cout << "Int Value: "<< std::to_string(v) << std::endl;
}

void Action::setCharValue(char c) {
	c = c;
	//std::cout << "Action::setCharValue" << std::endl;
	//std::cout << "Char Value: " << c << std::endl;
}

CreatureAction::CreatureAction(std::shared_ptr<Creature> owner) {
	//std::cout << "CreatureAction Constructor" << std::endl;
}

ItemAction::ItemAction(std::shared_ptr<Creature> owner) {
	//std::cout << "ItemAction Constructor" << std::endl;
}

BlessCurseOwner::BlessCurseOwner(std::shared_ptr<Creature> Owner) : ItemAction(Owner) {
	//std::cout << "BlessCurseOwner Constructor" << std::endl;
}

Hallucinate::Hallucinate(std::shared_ptr<Creature> Owner) :ItemAction(Owner) {
	//std::cout << "Hallucinate Constructor" << std::endl;
}
