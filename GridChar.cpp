#include "GridChar.h"

GridChar::GridChar()
{
	display.push_back(' ');
	objects.resize(0);
}

GridChar::GridChar(char _display) {
	display.push_back(_display);
}

char GridChar::getChar() {
	return display.back();
}

char GridChar::checkItem()
{
	return display[display.size() - 2];
}

void GridChar::addChar(char _display)
{
	display.push_back(_display);
}

void GridChar::addObject(std::shared_ptr<Displayable> _object) {
	objects.push_back(_object);
}

void GridChar::popChar()
{
	display.pop_back();
}

void GridChar::popObject()
{
	objects.pop_back();
}

std::shared_ptr<Displayable> GridChar::getObject()
{
	return objects.back();
}
