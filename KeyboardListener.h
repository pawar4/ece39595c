#pragma once
#include "ObjDisplayGrid.h"
#include "Creature.h"
#include <memory>

class KeyboardListener {
private:
	std::shared_ptr<ObjDisplayGrid> grid;
	bool * running = nullptr;

public:
	KeyboardListener(std::shared_ptr<ObjDisplayGrid> grid);
	~KeyboardListener();
	virtual void run();
};


