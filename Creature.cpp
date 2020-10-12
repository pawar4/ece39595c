#include "Creature.h"

Creature::Creature() : hp(0), hpm(0), da(0), ha(0)
{
	da.resize(0);
	ha.resize(0);
}


void Creature::setHp(int h) {
	hp = h;
	std::cout << "Creature::setHp" << std::endl;
}

void Creature::setHpMoves(int hpm) {
	hpm = hpm;
	std::cout << "Creature::setHpMoves" << std::endl;
}

void Creature::setDeathAction(std::shared_ptr<CreatureAction> _da) {
	da.resize(da.size() + 1);
	da.push_back(_da);
	std::cout << "Creature::setDeathAction" << std::endl;
}

void Creature::setHitAction(std::shared_ptr<CreatureAction> _ha) {
	ha.resize(ha.size() + 1);
	ha.push_back(_ha);
	std::cout << "Creature::setHitAction" << std::endl;
}


Player::Player() : sword(0),armor(0), room(0), serial(0) {
	std::cout << "Player Constructor" << std::endl;
}
void Player::setWeapon(std::shared_ptr<Item> _sword) {
	sword = _sword;
	std::cout << "Player::setWeapon" << std::endl;
}

void Player::setArmor(std::shared_ptr<Item> _armor) {
	armor = _armor;
	std::cout << "Player::setWeapon" << std::endl;
}

void Player::setID(int _room, int _serial) {
	room = _room;
	serial = _serial;
	std::cout << "Player::setID" << std::endl;
}

Monster::Monster()
{
	room = 0;
	serial = 0;
	std::cout << "Monster Constructor" << std::endl;
}

void Monster::setName(std::string _name) {
	name = _name;
	std::cout << "Monster Constructor" << std::endl;
}

void Monster::setID(int _room, int _serial)
{
	room = _room;
	serial = _serial;
}
