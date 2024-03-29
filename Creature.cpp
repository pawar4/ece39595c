#include "Creature.h"

Creature::Creature() : hp(0), hpm(0), da(0), ha(0)
{
	da.resize(0);
	ha.resize(0);
}


void Creature::setHp(int h) {
	hp = h;
	//std::cout << "HP: " << std::to_string(hp) << std::endl;
	//std::cout << "Creature::setHp" << std::endl;
}

void Creature::setHpMoves(int hpm) {
	hpm = hpm;
	//std::cout << "Creature::setHpMoves" << std::endl;
	//std::cout << "HPMoves: " << std::to_string(hpm) << std::endl;
}

void Creature::setDeathAction(std::shared_ptr<CreatureAction> _da) {
	//da.resize(da.size() + 1);
	da.push_back(_da);
	//std::cout << "Creature::setDeathAction" << std::endl;
}

void Creature::setHitAction(std::shared_ptr<CreatureAction> _ha) {
	//ha.resize(ha.size() + 1);
	ha.push_back(_ha);
	//std::cout << "Creature::setHitAction" << std::endl;
}

void Creature::setName(std::string _name)
{
	name = _name;
}

std::string Creature::getName()
{
	return name;
}


Player::Player() : sword(0),armor(0), room(0), serial(0) {
	//std::cout << "Player Constructor" << std::endl;
	setName("Player");
}
void Player::setWeapon(std::shared_ptr<Item> _sword) {
	sword = _sword;
	//std::cout << "Player::setWeapon" << std::endl;
}

void Player::setArmor(std::shared_ptr<Item> _armor) {
	armor = _armor;
	//std::cout << "Player::setWeapon" << std::endl;
}

void Player::setID(int _room, int _serial) {
	room = _room;
	serial = _serial;
	//std::cout << "Player::setID" << std::endl;
}

Monster::Monster()
{
	room = 0;
	serial = 0;
	std::cout << "Monster Constructor" << std::endl;
}
//Make this a virtual base function so we can differentiate between monster and troll
/*void Monster::setName(std::string _name) {
	name = _name;
	//std::cout << "Monster::setName" << std::endl;
	//std::cout << "Name: " << name << std::endl;
}*/

void Monster::setID(int _room, int _serial)
{
	room = _room;
	serial = _serial;
}
