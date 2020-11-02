#pragma once
#include "ObjDisplayGrid.h"
#include "Creature.h"
#include <memory>

class KeyboardListener {
private:
	std::shared_ptr<ObjDisplayGrid> grid;
	bool running = false;

public:
	KeyboardListener(std::shared_ptr<ObjDisplayGrid> grid);
	virtual void run();
};


