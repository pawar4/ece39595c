#include "Creature.h"
#include "YouWin.h"
#include "ObjDisplayGrid.h"
Creature::Creature() : hp(0), hpm(0), da(0), ha(0)
{
	da.resize(0);
	ha.resize(0);
}


void Creature::setHp(int _h) {
	hp = _h;
	//std::cout << "HP: " << std::to_string(hp) << std::endl;
	//std::cout << "Creature::setHp" << std::endl;
}

void Creature::setHpMoves(int _hpm) {
	hpm = _hpm;
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

int Creature::getHit(std::shared_ptr<Displayable> _hitter, int _dmgBuff, int _dmgDebuff) {
	int damage = (rand() % _hitter->getMaxHit()) + 1 + _dmgBuff;
	if (damage > _dmgDebuff) this->hp -= (damage - _dmgDebuff);

	return damage;
}

int Creature::getHP()
{
	return hp;
}

void Creature::regenHP(int _amount)
{
	hp += _amount;
}

std::string Creature::executeDAmsg(std::string actionType)
{
	for (std::shared_ptr<CreatureAction> action: da) {
		if (action->getName() == actionType) return action->getMsg();
	}
	return " ";
}

char Creature::executeDA(ObjDisplayGrid* objGrid)
{
	char c = NULL;
	for (std::shared_ptr<CreatureAction> action : da) {
		if (action->getName() == "EndGame" || action->getName() == "YouWin") {
			objGrid->setInfo(action->getMsg(),"");
		}
		else if (action->getName() == "EndGame") {

		}
		else if (action->getName() == "Remove") {
			//ObjDisplayGrid::moveObject takes care of this functionality
		}
		else if (action->getName() == "ChangeDisplayedType") {
			c = action->getCharVal();
		}
	}
	return c;
}

char Creature::executeHA(ObjDisplayGrid* objGrid, int newX, int newY)
{
	char c = NULL;
	int tX = 0; 
	int tY = 0;
	for (std::shared_ptr<CreatureAction> action : ha) {
		if (action->getName() == "DropPack") {
			//objGrid->setInfo(action->getMsg());
			//implement droppack functionality

			objGrid->dropItem(objGrid->player->getPosX(),
				objGrid->player->getPosY(), 1);
		}
		else if (action->getName() == "Teleport") {
			/*//objGrid->setInfo(action->getMsg());
			//implement teleport functionality
			/*Srand, check the creatures new position, if valid ex objgrid has . 
			 or # move it there*/
			/*while (objGrid->getChar(tX,tY) != '.' || objGrid->getChar(tX, tY) != '#') {
				tY = rand() % (objGrid->getGameHeight() - objGrid->getTopHeight() + 1) + objGrid->getTopHeight();
				tX = rand() % (objGrid->getWidth() + 1);
			}
			objGrid->teleport(5, 4, newX, newY);*/
		}
		else if (action->getName() == "Remove") {
			//ObjDisplayGrid::moveObject takes care of this functionality
		}
		else if (action->getName() == "ChangeDisplayedType") {
			//c = action->getCharVal();
		}
		if (!action->getMsg().empty()) {
			objGrid->setInfo("", action->getMsg());
		}
	}
	return c;
}

char Creature::executeHA(ObjDisplayGrid* objGrid)
{
	char c = NULL;
	int tX, tY;
	for (std::shared_ptr<CreatureAction> action : ha) {
		if (action->getName() == "DropPack") {
			//objGrid->setInfo(action->getMsg());
			//implement droppack functionality

			objGrid->dropItem(objGrid->player->getPosX(),
				objGrid->player->getPosY(), 1);
		}
		/*else if (action->getName() == "Teleport") {
			//objGrid->setInfo(action->getMsg());
			//implement teleport functionality
			/*Srand, check the creatures new position, if valid ex objgrid has .
			 or # move it there
			while (objGrid->getChar(tX, tY) != '.' || objGrid->getChar(tX, tY) != '#') {
				tY = rand() % (objGrid->getGameHeight() - objGrid->getTopHeight() + 1) + objGrid->getTopHeight();
				tX = rand() % (objGrid->getWidth() + 1);
			}
			objGrid->teleport(tX, tY);
		}*/
		else if (action->getName() == "Remove") {
			//ObjDisplayGrid::moveObject takes care of this functionality
		}
		else if (action->getName() == "ChangeDisplayedType") {
			//c = action->getCharVal();
		}
		if (!action->getMsg().empty()) {
			objGrid->setInfo("", action->getMsg());
		}
	}
	return c;
}

int Creature::getHpMoves()
{
	return hpm;
}

char Player::executeIA(ObjDisplayGrid* objGrid, int item)
{	//getitem 
	char c;
	/*std::shared_ptr<Scroll> scroll = std::dynamic_pointer_cast<Scroll>(pack[item]);
	if (scroll) {
		//scroll->
	}*/
	return c;
}

Player::Player() : sword(0),armor(0), room(0), serial(0), hallucinate(false), movesCounter(0), hallucinateCounter(0), scrollEffect(0) {
	//std::cout << "Player Constructor" << std::endl;
	setName("Player");
	pack.resize(0);
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

std::vector<std::shared_ptr<Item>> Player::getPack()
{
	return pack;
}

void Player::addItem(std::shared_ptr<Item> itemPick)
{
	pack.push_back(itemPick);
}

std::shared_ptr<Item> Player::dropItem(int _itemPos)
{
	std::shared_ptr<Item> item = std::shared_ptr<Item>(nullptr);
	if (_itemPos <= pack.size() && _itemPos > 0) {
		item = pack[_itemPos - 1];
		pack.erase(pack.begin() + _itemPos - 1);
	}
	return item;
}

int Player::isPackEmpty()
{
	return pack.size() == 0 ? 1 : 0;
}

std::shared_ptr<Item> Player::getSword()
{
	return this->sword;
}

std::shared_ptr<Item> Player::getArmor()
{
	return this->armor;
}

int Player::takeOffArmor()
{
	if (armor) {
		armor = std::shared_ptr<Item>(nullptr);
		return 1;
	}
	return 0;
	//need to update inventory to remove a next to the armor
}

int Player::takeOffSword() 
{
	if (sword) {
		sword = std::shared_ptr<Item>(nullptr);
		return 1;
	}
	return 0;
}
void Player::setScrollEffect(int _effect)
{
	scrollEffect = _effect;
}

int Player::getScrollEffect()
{
	return scrollEffect;
}

bool Player::isPosVal(int _itemPos)
{
	if (_itemPos <= getPack().size() && _itemPos > 0) { return true; }
	return false;
}

Monster::Monster()
{
	room = 0;
	serial = 0;
	//std::cout << "Monster Constructor" << std::endl;
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