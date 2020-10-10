#include "Creature.h"

Creature::Creature(int hp, int hpm, CreatureAction da, CreatureAction ha) :
	hp(hp), hpm(hpm), da(da), ha(ha) {
	std::cout << "Creature::Creature" << std::endl;
}

void Creature::setHp(int h) {
	hp = h;
	std::cout << "Creature::setHp" << std::endl;
}

void Creature::setHpMoves(int hpm) {
	hpm = hpm;
	std::cout << "Creature::setHpMoves" << std::endl;
}

void Creature::setDeathAction(CreatureAction da) {
	da = da;
	std::cout << "Creature::setDeathAction" << std::endl;
}

void Creature::setHitAction(CreatureAction ha) {
	ha = ha;
	std::cout << "Creature::setHitAction" << std::endl;
}
Player::Player() {
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
	std::cout << "Monster Constructor" << std::endl;
}

void Monster::setName(std::string name) {
	name = name;
	std::cout << "Monster Constructor" << std::endl;
}
