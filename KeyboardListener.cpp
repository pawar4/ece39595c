#include "KeyboardListener.h"
#include <sstream>
#include <iostream>
#include <stdio.h>

KeyboardListener::KeyboardListener(std::shared_ptr<ObjDisplayGrid> _grid) : grid(_grid) {
	running = new bool;
	*running = false;
}

KeyboardListener::~KeyboardListener()
{
	delete running;
}

void KeyboardListener::run() {
	*running = true;
	char input;
	int itemPos = 0;
	do {
		//input = std::tolower(getchar());
		input = getchar();
		int oldX = 0;
		int oldY = 0;
		int newX = 0;
		int newY = 0;
		switch (input) {
		case 'x': //exit the game
			*running = false;
			break;

		case 'k': //move up
			oldX = grid->player->getPosX();
			oldY = grid->player->getPosY();
			newY = oldY - 1;
			newX = oldX;
			grid->moveObject('@', oldX, newY, oldX, oldY, running);
			grid->hallucinate();
			break;

		case 'j': //move down
			oldX = grid->player->getPosX();
			oldY = grid->player->getPosY();
			newY = oldY + 1;
			newX = oldX;
			grid->moveObject('@', oldX, newY, oldX, oldY, running);
			grid->hallucinate();
			break;

		case 'h': //move left
			oldX = grid->player->getPosX();
			oldY = grid->player->getPosY();
			newX = oldX - 1;
			newY = oldY;
			grid->moveObject('@', newX, oldY, oldX, oldY, running);
			grid->hallucinate();
			break;

		case 'l': //move right
			oldX = grid->player->getPosX();
			oldY = grid->player->getPosY();
			newX = oldX + 1;
			newY = oldY;
			grid->moveObject('@', newX, oldY, oldX, oldY, running);
			grid->hallucinate();
			break;

		case 'p': //pick up item
			oldX = grid->player->getPosX();
			oldY = grid->player->getPosY();
			grid->pickItem(oldX, oldY);
			break;

		case 'd':
			oldX = grid->player->getPosX();
			oldY = grid->player->getPosY();
			while(itemPos <= 0 || itemPos > 9) itemPos = getchar() - 48;
			grid->dropItem(oldX, oldY, itemPos);
			break;

		case 'i':
			grid->dispPackMsg();
			break;

		case 'c':
			//grid->player->takeOffArmor();
			break;

		case 'E':
			break;

		case '?':
			break;

		case 'H':
			break;

		case 'r':
			break;

		case 'T':
			break;

		case 'w':
			break;

		default:
			break;
		}
		
		grid->update();

	} while (*running);
}