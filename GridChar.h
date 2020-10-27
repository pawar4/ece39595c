#pragma once
#ifndef GRIDCHAR_H_
#define GRIDCHAR_H_

//So this class is used basically as a wrapper for now
//We can see later if we need to expand functionality
class GridChar {
public:
	GridChar(char display);
	virtual char getChar();
private:
	//Gets character used to display this grid character and returns
	//character to display
	char display;
};

#endif