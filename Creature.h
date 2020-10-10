#ifndef CREATURE_H_
#define CREATURE_H_
#include <iostream>
#include "Displayable.h"
#include "Action.h"
class CreatureAction;
class Creature : public Displayable { //make inherit from displayable later
public:
	Creature(int hp, int hpm, CreatureAction& da, CreatureAction& ha);
	Creature();
	virtual void setHp(int h);
	virtual void setHpMoves(int hpm);
	virtual void setDeathAction(CreatureAction& da);
	virtual void setHitAction(CreatureAction& ha);
private:
	int hp;
	int hpm;
	CreatureAction& da; //change to creatureaction
	CreatureAction& ha;	//change to action
};



class Player : public Creature {
public:
	Player();
	void setWeapon(int sword); //change to item
	void setArmor(int armor);  //change to item

private:
	int sword;
	int armor;

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
#endif /* CREATURE_H_*/