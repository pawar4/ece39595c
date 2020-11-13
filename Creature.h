#ifndef CREATURE_H_
#define CREATURE_H_

#include <iostream>
#include <vector>
#include <string>
#include "Displayable.h"
#include <memory>

class CreatureAction;
class Item;
class Sword;
class Armor;

class Creature : public Displayable {
public:
	Creature(); //initialize everything to zero here
	virtual void setHp(int h);
	virtual void setHpMoves(int hpm);
	virtual void setDeathAction(std::shared_ptr<CreatureAction> da);
	virtual void setHitAction(std::shared_ptr<CreatureAction> ha);
	virtual void setName(std::string _name);
	virtual std::string getName();
	virtual int getHit(std::shared_ptr<Displayable> _hitter);
	virtual int getHP();
	
private:
	int hp;
	int hpm;
	std::vector<std::shared_ptr<CreatureAction>> da; //change to creatureaction
	std::vector<std::shared_ptr<CreatureAction>> ha; //change to action
	std::string name;
};

class Player : public Creature {
public:
	Player();
	void setWeapon(std::shared_ptr<Item> sword); //change to item
	void setArmor(std::shared_ptr<Item> armor);  //change to item
	void setID(int _room, int _serial);
	virtual std::vector<std::shared_ptr<Item>> getPack();
private:
	std::shared_ptr<Item> sword;
	std::shared_ptr<Item> armor;
	int room;
	int serial;
	std::vector<std::shared_ptr<Item>> pack; // used for the item pack
};

class Monster : public Creature {
public:
	Monster();
	//void setName(std::string name);
	void setID(int room, int serial);
private:
	//std::string name;
	int room;
	int serial;
};
#endif // !CREATURE_H_

