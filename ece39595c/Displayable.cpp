#include "Displayable.h"

Displayable::Displayable(int maxHit, int hpMoves, int Hp, 
	char t, int v, int PosX, int PosY, int x, int y) : maxHit(maxHit), hpMoves(hpMoves),
	Hp(Hp), type(t), v(v), PosX(PosX), PosY(PosY), Width(x), Height(y)
{
	std::cout << "Displayble Constructor" << std::endl;
}
Displayable::Displayable() : maxHit(0), hpMoves(0),
Hp(0), type(0), v(0), PosX(0), PosY(0), Width(0), Height(0) {
	std::cout << "Default Displayble Constructor" << std::endl;
}
void Displayable::setInvisible() {
	std::cout << "Displayable::setInvisible" << std::endl;
}

void Displayable::setVisible() {
	std::cout << "Displayable::setVisible" << std::endl;
}

void Displayable::setMaxHit(int maxHit) {
	maxHit = maxHit;
	std::cout << "Displayable::setMaxHit" << std::endl;
	std::cout << "MaxHit: " << std::to_string(maxHit) << std::endl;
}

void Displayable::setHpMove(int hpMoves) {
	hpMoves = hpMoves;
	std::cout << "Displayable::setHpMove" << std::endl;
	std::cout << "HpMoves: " << std::to_string(hpMoves) << std::endl;
}

void Displayable::setHp(int Hp) {
	Hp = Hp;
	std::cout << "Displayable::setHp" << std::endl;
	std::cout << "Hp: " << std::to_string(Hp) << std::endl;
}

void Displayable::setType(char t) {
	type = t;
	std::cout << "Displayable::setType" << std::endl;
	std::cout << "MaxHit: " << t << std::endl;
}

void Displayable::setIntValue(int v)
{
	v = v;
	std::cout << "Displayable::setIntValue" << std::endl;
	std::cout << "Value: " << std::to_string(v) << std::endl;
}

void Displayable::setPosX(int x) {
	PosX = x;
	std::cout << "Displayable::SetPosX" << std::endl;
	std::cout << "PosX: " << std::to_string(PosX) << std::endl;
}
void Displayable::setPosY(int y) {
	PosY = y;
	std::cout << "Displayable::SetPosY" << std::endl;
	std::cout << "PosY: " << std::to_string(PosY) << std::endl;

}

void Displayable::setWidth(int x)
{
	int Width = x;
	std::cout << "Displayable::SetWidth" << std::endl;
	std::cout << "Width: " << std::to_string(Width) << std::endl;

}

void Displayable::setHeight(int y) {
	int height = y;
	std::cout << "Displayable::SetHeight" << std::endl;
	std::cout << "Height: " << std::to_string(height) << std::endl;

}
