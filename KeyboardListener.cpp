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
	char input2;
	int itemPos = 0;
	do {
		//Might need to change this later if messages get cleared that we don't want cleared
		grid->clrBotMsg(); 
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
			grid->setInfo("", " ");
			grid->moveObject('@', oldX, newY, oldX, oldY, running);
			grid->hallucinate();
			break;

		case 'j': //move down
			oldX = grid->player->getPosX();
			oldY = grid->player->getPosY();
			newY = oldY + 1;
			newX = oldX;
			grid->setInfo("", " ");
			grid->moveObject('@', oldX, newY, oldX, oldY, running);
			grid->hallucinate();
			break;

		case 'h': //move left
			oldX = grid->player->getPosX();
			oldY = grid->player->getPosY();
			newX = oldX - 1;
			newY = oldY;
			grid->setInfo("", " ");
			grid->moveObject('@', newX, oldY, oldX, oldY, running);
			grid->hallucinate();
			break;

		case 'l': //move right
			oldX = grid->player->getPosX();
			oldY = grid->player->getPosY();
			newX = oldX + 1;
			newY = oldY;
			grid->setInfo("", " ");
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
			grid->clrBotMsg();
			grid->dispPackMsg();
			break;
		case 'c': //Change, or take off armor
			grid->dispPackMsg();
			break;
		case 'E': //End game
			grid->setInfo("Press Y | y to exit the game.", "");
			input2 = getchar();
			if (input2 == 'Y' || input2 == 'y') {
				*running = false;
				grid->setInfo("Player has left the game.", "");
				break;
			}	
			break;
		case '?': //Shows different Commands to the info seciton of the display
			grid->clrBotMsg();
			grid->setBotMessage(0, "Info: Change, or take off armor: 'c', Drop: 'd' <integer>, End Game: 'E' <Y|y>, Help: '?', Detailed Help: 'H' <command>, Show inventory: 'i', Pick up an item   from the dungeon floor: 'p' Read an item: 'r' <integer>, Take out a weapon: 'T',Wear Item: 'w' <integer>",  "");			
			break;
		case 'H': //Detailed Help
			grid->setInfo("H <command>","");
			grid->update();
			//input2 = getchar();
			switch (getchar()) {
			case 'c':
				grid->setBotMessage(0,"Help: Change, or take off armor 'c': armor that is being worn is taken off and  placed in the pack.","");
				grid->setInfo("", " ");
				break;
			case 'd':
				grid->setBotMessage(0, "Help: Drop 'd' <integer>: drop item <integer> from the pack.", "");
				grid->setInfo("", " ");
				break;
			case 'E':
				grid->setBotMessage(0, "Help: 'E' <Y | y>: ends the game, you coward.", "");\
				grid->setInfo("", " ");
				break;
			case '?':
				grid->setBotMessage(0, "Help: Help '?': show the different commands in the info section of the display.", "");
				grid->setInfo("", " ");
				break;
			case 'H':
				grid->setBotMessage(0, "Help: Help 'H' <command>: give more detailed information about the specified    command in the info section of the display.", "");
				grid->setInfo("", " ");
				break;
			case 'i':
				grid->setBotMessage(0, "Help: Show or display the inventory 'i' : show the contents of the pack. (w)    shows wielded sword, (a) shows equipped armor", "");
				grid->setInfo("", " ");
				break;
			case 'p':
				grid->setBotMessage(0, "Help: Pick up an item from the dungeon floor 'p': pick up the item on the       dungeon floor location that the player is standing on and adds it to the pack.", "");
				grid->setInfo("", " ");
				break;
			case 'r':
				grid->setBotMessage(0, "Read an item 'r' <integer>: Read a scroll specified by <integer>... iF y0u DAaaAaRrReEE!!!!!!!!", "");
				grid->setInfo("", " ");

				break;
			case 'T':
				grid->setBotMessage(0, "Help: Take out a weapon T <integer> : Takes out sword identified by <integer> from the pack and wield it. ", "");
				grid->setInfo("", " ");

				break;
			case 'w':
				grid->setBotMessage(0, "Help: Wear item 'w' <integer>: Equips armor identified by <integer>.", "");
				grid->setInfo("", " ");
				break;
			default:
				grid->setInfo("Wrong Key!!! Press H <command> to try again.", " ");
				break;
			}
			break;
		case 'r':
			//do item actions
			break;
		default:
			break;
		}	
		grid->update();

	} while (*running);
}