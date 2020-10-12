#ifndef CREATURE_H_
#define CREATURE_H_

#include <iostream>
#include <vector>

#include "Displayable.h"
#include "Item.h"
class Item;
class Action;
class CreatureAction;
class Creature : public Displayable {
public:
	Creature(); //initialize everything to zero here
	virtual void setHp(int h);
	virtual void setHpMoves(int hpm);
	virtual void setDeathAction(std::shared_ptr<CreatureAction> da);
	virtual void setHitAction(std::shared_ptr<CreatureAction> ha);
	virtual void setID(int room, int serial);
private:
	int hp;
	int hpm;
	std::vector<std::shared_ptr<CreatureAction>> da; //change to creatureaction
	std::vector<std::shared_ptr<CreatureAction>> ha; //change to action
};


class Player : public Creature {
public:
	Player();
	void setWeapon(std::shared_ptr<Item> sword); //change to item
	void setArmor(std::shared_ptr<Item> armor);  //change to item

private:
	int sword;
	int armor;
	int room;
	int serial;
};

class Monster : public Creature {
public:
	Monster();
	void setName(std::string name);
	void setID(int room, int serial);
private:
	std::string name;
	int room;
	int serial;
};
#endif // !CREATURE_H_

