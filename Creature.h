#ifndef CREATURE_H_
#define CREATURE_H_

#include <iostream>
#include <vector>
#include <string>
#include "Displayable.h"
//#include "scroll.h"
#include <memory>
//#include "ObjDisplayGrid.h"

class CreatureAction;
class Item;
class Sword;
class Armor;
class Scroll;

class Creature : public Displayable {
public:
	Creature(); //initialize everything to zero here
	virtual void setHp(int h);
	virtual void setHpMoves(int hpm);
	virtual void setDeathAction(std::shared_ptr<CreatureAction> da);
	virtual void setHitAction(std::shared_ptr<CreatureAction> ha);
	virtual void setName(std::string _name);
	virtual std::string getName();
	virtual int getHit(std::shared_ptr<Displayable> _hitter, int _dmgBuff, int _dmgDebuff);
	virtual int getHP();
	virtual void regenHP(int _amount);
	virtual std::string executeDAmsg(std::string actionType);
	virtual char executeDA(ObjDisplayGrid* objGrid);
	virtual char executeHA(ObjDisplayGrid* objGrid);
	virtual int getHpMoves();
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
	virtual void addItem(std::shared_ptr<Item> itemPick);
	virtual std::shared_ptr<Item> dropItem(int _itemPos);
	virtual int isPackEmpty();
	virtual char executeIA(ObjDisplayGrid* objGrid, int item);
	virtual std::shared_ptr<Item> getSword();
	virtual std::shared_ptr<Item> getArmor();
	virtual int takeOffArmor();
	virtual void setScrollEffect(int _effect);
	virtual int getScrollEffect();
	bool hallucinate;
	int movesCounter;
	int hallucinateCounter;
private:
	int scrollEffect;
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

