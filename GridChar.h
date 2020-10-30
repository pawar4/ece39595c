
#include <vector>
#pragma once
#ifndef GRIDCHAR_H_
#define GRIDCHAR_H_

//So this class is used basically as a wrapper for now
//We can see later if we need to expand functionality
class GridChar {
public:
	GridChar();
	GridChar(char display);
	virtual char getChar();
	virtual void addChar(char _display);
	virtual void popChar();
private:
	//Gets character used to display this grid character and returns
	//character to display
	std::vector<char> display;
};
#endif