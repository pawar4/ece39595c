#include "KeyboardListener.h"
#include <sstream>
#include <iostream>
#include <stdio.h>

KeyboardListener::KeyboardListener(std::shared_ptr<ObjDisplayGrid> _grid) : grid(_grid) {}

void KeyboardListener::run() {
	running = true;
	char input;
	int itemPos = 0;
	do {
		input = std::tolower(getchar());
		int oldX = 0;
		int oldY = 0;
		int newX = 0;
		int newY = 0;
		switch (input) {
		case 'x': //exit the game
			running = false;
			break;
		case 'k': //move up
			oldX = grid->player->getPosX();
			oldY = grid->player->getPosY();
			newY = oldY - 1;
			newX = oldX;
			grid->moveObject('@', oldX, newY, oldX, oldY);
			break;

		case 'j': //move down
			oldX = grid->player->getPosX();
			oldY = grid->player->getPosY();
			newY = oldY + 1;
			newX = oldX;
			grid->moveObject('@', oldX, newY, oldX, oldY);
			break;

		case 'h': //move left
			oldX = grid->player->getPosX();
			oldY = grid->player->getPosY();
			newX = oldX - 1;
			newY = oldY;
			grid->moveObject('@', newX, oldY, oldX, oldY);
			break;

		case 'l': //move right
			oldX = grid->player->getPosX();
			oldY = grid->player->getPosY();
			newX = oldX + 1;
			newY = oldY;
			grid->moveObject('@', newX, oldY, oldX, oldY);
			break;
		//case 'i': //updates pack			
			//grid->setPack(item); //need to find a way to update this with picked up item
		case 'p': //pick up item
			oldX = grid->player->getPosX();
			oldY = grid->player->getPosY();
			grid->pickItem(oldX, oldY);
			break;
		case 'd':
			oldX = grid->player->getPosX();
			oldY = grid->player->getPosY();
			while(itemPos <= 0 || itemPos > 9) itemPos = getchar() - 48;
			//scanf("%d", &itemPos);
			grid->dropItem(oldX, oldY, itemPos);
			break;
		case 'i':
			grid->dispPackMsg();
			break;

		default:
			break;
		}
		grid->update();

	} while (running);
}