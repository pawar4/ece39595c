#include "Creature.h"



Creature::Creature(int hp, int hpm, CreatureAction& da, CreatureAction& ha) 
	: hp(hp),hpm(hpm),da(da),ha(ha)
{

}

Creature::Creature()
{
	hp(0), hpm(0), da(0), ha(0)
}


void Creature::setHp(int h) {
	hp = h;
	std::cout << "Creature::setHp" << std::endl;
}

void Creature::setHpMoves(int hpm) {
	hpm = hpm;
	std::cout << "Creature::setHpMoves" << std::endl;
}

void Creature::setDeathAction(std::shared_ptr<CreatureAction> da) {
	da = da;
	std::cout << "Creature::setDeathAction" << std::endl;
}

void Creature::setHitAction(std::shared_ptr<CreatureAction> ha) {
	ha = ha;
	std::cout << "Creature::setHitAction" << std::endl;
}
void Creature::setID(int room, int serial)
{
	room = room;
	serial = serial;
}
Player::Player() : sword(0),armor(0), room(0), serial(0) {
	std::cout << "Player Constructor" << std::endl;
}
void Player::setWeapon(int sword) {
	sword = sword;
	std::cout << "Player::setWeapon" << std::endl;
}

void Player::setArmor(int armor) {
	armor = armor;
	std::cout << "Player::setWeapon" << std::endl;
}

Monster::Monster()
{
	room = 0;
	serial = 0;
	std::cout << "Monster Constructor" << std::endl;
}

void Monster::setName(std::string name) {
	name = name;
	std::cout << "Monster Constructor" << std::endl;
}

void Monster::setID(int room, int serial)
{
	room = room;
	serial = serial;
}
}
