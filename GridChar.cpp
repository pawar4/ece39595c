#include "GridChar.h"

GridChar::GridChar()
{
	display.push_back(' ');
}

GridChar::GridChar(char _display) {
	display.push_back(_display);
}

char GridChar::getChar() {
	return display.back();
}

void GridChar::addChar(char _display)
{
	display.push_back(_display);
}

void GridChar::popChar()
{
	display.pop_back();
}
