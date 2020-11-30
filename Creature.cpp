#include "Creature.h"
#include "YouWin.h"
#include "ObjDisplayGrid.h"
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

int Creature::getHit(std::shared_ptr<Displayable> _hitter) {
	int damage = (rand() % _hitter->getMaxHit()) + 1;
	this->hp -= damage;

	return damage;
}

int Creature::getHP()
{
	return hp;
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

char Creature::executeHA(ObjDisplayGrid* objGrid)
{
	char c = NULL;
	for (std::shared_ptr<CreatureAction> action : ha) {
		if (action->getName() == "DropPack") {
			//objGrid->setInfo(action->getMsg());
			//implement droppack functionality

			objGrid->dropItem(objGrid->player->getPosX(), 
				objGrid->player->getPosY(), 1);
		}
		else if (action->getName() == "Teleport") {
			//objGrid->setInfo(action->getMsg());
			//implement teleport functionality
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

char Player::executeIA(ObjDisplayGrid* objGrid, int item)
{	//getitem 
	char c;
	/*std::shared_ptr<Scroll> scroll = std::dynamic_pointer_cast<Scroll>(pack[item]);
	if (scroll) {
		//scroll->
	}*/
	return c;
}

Player::Player() : sword(0),armor(0), room(0), serial(0) {
	//std::cout << "Player Constructor" << std::endl;
	setName("Player");;
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