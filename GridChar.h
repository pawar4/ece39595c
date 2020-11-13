#include <vector>
#pragma once
#ifndef GRIDCHAR_H_
#define GRIDCHAR_H_

#include "Displayable.h"
//So this class is used basically as a wrapper for now
//We can see later if we need to expand functionality
class GridChar {
public:
	GridChar();
	GridChar(char display);
	virtual char getChar();
	virtual char checkItem();
	virtual void addChar(char _display);
	virtual void addObject(std::shared_ptr<Displayable> _object);
	virtual void popChar();
	virtual void popObject();
	virtual std::shared_ptr<Displayable> getObject();
private:
	//Gets character used to display this grid character and returns
	//character to display
	std::vector<char> display;
	std::vector<std::shared_ptr<Displayable>> objects;
};
#endif