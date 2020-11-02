#include "KeyboardListener.h"
#include <sstream>
#include <iostream>
#include <stdio.h>

KeyboardListener::KeyboardListener(std::shared_ptr<ObjDisplayGrid> _grid) : grid(_grid) {}

void KeyboardListener::run(std::shared_ptr<Player> _player) {
	grid->writeLine(0, "Press 'x' to exit");
	running = true;
	char input;

	do {
		input = std::tolower(getchar());

		switch (input) {
		case 'x': //exit the game
			running = false;
			grid->writeLine(2, "Exiting...");
			break;
		case 'k': //move up
			grid->addObjectToDisplay()
			break;
		
		case 'j': //move down
			break;
		
		case 'h': //move left
			break;
		
		case 'l': //move right
			break;
		
		default:
			break;
		}
		grid->update();

	} while(running)
}