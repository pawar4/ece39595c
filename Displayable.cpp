#include "Displayable.h"

Displayable::Displayable(int _maxHit, int _hpMoves, int _Hp,
	char _t, int _v, int _PosX, int _PosY, int _x, int _y) : maxHit(_maxHit), hpMoves(_hpMoves),
	Hp(_Hp), type(_t), v(_v), PosX(_PosX), PosY(_PosY), Width(_x), Height(_y)
{
	//std::cout << "Displayble Constructor" << std::endl;
}
Displayable::Displayable() : maxHit(0), hpMoves(0),
Hp(0), type(0), v(0), PosX(0), PosY(0), Width(0), Height(0) {
	//std::cout << "Default Displayble Constructor" << std::endl;
}
void Displayable::setInvisible() {
	//std::cout << "Displayable::setInvisible" << std::endl;
}

void Displayable::setVisible() {
	//std::cout << "Displayable::setVisible" << std::endl;
}

void Displayable::setMaxHit(int _maxHit) {
	maxHit = _maxHit;
	//std::cout << "Displayable::setMaxHit" << std::endl;
	//std::cout << "MaxHit: " << std::to_string(maxHit) << std::endl;
}

void Displayable::setHpMove(int _hpMoves) {
	hpMoves = _hpMoves;
	//std::cout << "Displayable::setHpMove" << std::endl;
	//std::cout << "HpMoves: " << std::to_string(hpMoves) << std::endl;
}

void Displayable::setHp(int _Hp) {
	Hp = _Hp;
	//std::cout << "Displayable::setHp" << std::endl;
	//std::cout << "Hp: " << std::to_string(Hp) << std::endl;
}

void Displayable::setType(char _t) {
	type = _t;
	//std::cout << "Displayable::setType" << std::endl;
	//std::cout << "type: " << t << std::endl;
}

void Displayable::setIntValue(int _v)
{
	v = _v;
	//std::cout << "Displayable::setIntValue" << std::endl;
	//std::cout << "Value: " << std::to_string(v) << std::endl;
}

void Displayable::setPosX(int _x) {
	PosX = _x;
	//std::cout << "Displayable::SetPosX" << std::endl;
	//std::cout << "PosX: " << std::to_string(PosX) << std::endl;
}
void Displayable::setPosY(int _y) {
	PosY = _y;
	//std::cout << "Displayable::SetPosY" << std::endl;
	//std::cout << "PosY: " << std::to_string(PosY) << std::endl;

}

void Displayable::setWidth(int _x)
{
	 Width = _x;
	//std::cout << "Displayable::SetWidth" << std::endl;
	//std::cout << "Width: " << std::to_string(Width) << std::endl;

}

void Displayable::setHeight(int _y) {
	Height = _y;
	//std::cout << "Displayable::SetHeight" << std::endl;
	//std::cout << "Height: " << std::to_string(height) << std::endl;

}

int Displayable::getWidth()
{
	return Width;
}

int Displayable::getHeight()
{
	return Height;
}

int Displayable::getPosX()
{
	return PosX;
}

int Displayable::getPosY()
{
	return PosY;
}

char Displayable::getType()
{
	return type;
}

int Displayable::getMaxHit()
{
	return maxHit;
}

/*int Displayable::getHit(std::shared_ptr<Displayable> _hitter) {
	int damage = rand() % _hitter->getMaxHit();
	this->Hp -= damage;

	if (this->Hp <= 0) return 1;

	return 0;
}*/
