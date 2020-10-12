#include "Action.h"
Action::Action(int v, int c) : v(v), c(c) {
	std::cout << "Action Constructor" << std::endl;
}
Action::Action() {
	std::cout << "Action Constructor" << std::endl;
}
void Action::setMessage(std::string msg) {
	msg = msg;
	std::cout << "Action::setMessage" << std::endl;
}

void Action::setIntValue(int v) {
	v = v;
	std::cout << "Action::setIntValue" << std::endl;
}

void Action::setCharValue(char c) {
	c = c;
	std::cout << "Action::setCharValue" << std::endl;
}

CreatureAction::CreatureAction(std::shared_ptr<Creature> owner) {
	std::cout << "CreatureAction Constructor" << std::endl;
}

ItemAction::ItemAction(int owner) {
	std::cout << "ItemAction Constructor" << std::endl;
}

BlessCurseOwner::BlessCurseOwner(int Owner) : ItemAction(Owner) {
	std::cout << "BlessCurseOwner Constructor" << std::endl;
}

Hallucinate::Hallucinate(int Owner) :ItemAction(Owner) {
	std::cout << "Hallucinate Constructor" << std::endl;
}
