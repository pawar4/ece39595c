#include <iostream>
#include "ObjDisplayGrid.h"
#include "Scroll.h"
#include "Sword.h"
#include "Armor.h"
#include <curses.h>
#include <algorithm>
#include <memory>

#ifdef _WIN32
#include <windows.h>
#endif


std::shared_ptr<ObjDisplayGrid> ObjDisplayGrid::instance = nullptr;

ObjDisplayGrid::ObjDisplayGrid(int _width, int _gameHeight, int _topHeight, int _botHeight) :
    width(_width), gameHeight(_gameHeight), topHeight(_topHeight), botHeight(_botHeight) {
    //2D array of GridChars
    objectGrid = new GridChar **[width]; //make a 2d array that has 1 vector of GridChar
    //std::vector<GridChar>** pop character if it leaves
    gridHeight = gameHeight + topHeight + botHeight;
    for (int i = 0; i < width; i++) {
        objectGrid[i] = new GridChar * [gridHeight];
        for (int j = 0; j < gridHeight; j++) { //topHeight bad for some reason
            objectGrid[i][j] = new GridChar();
        }
    }
    //std::cout << "ObjDisplayGrid::ObjDisplayGrid" << std::endl;


// initialize ncurses

// set command window size if running on windows, useful when running in Visual Studio
// as far as I am aware, no way to do this on linux
#ifdef _WIN32
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD size = { (short)width, (short)(gameHeight + topHeight + botHeight) };
    SMALL_RECT DisplayArea = { 0, 0, (short)(size.X - 1), (short)(size.Y - 1) };
    SetConsoleScreenBufferSize(handle, size);
    SetConsoleWindowInfo(handle, TRUE, &DisplayArea);
#endif
    //initializes ncurses
    initscr();
    //makes characters typed immediately available, instead of waiting for enter to be pressed
    cbreak();
    //stops typed characters from being shown, makes it easier to get keypresses
    noecho();
    // clears the screen to start
    clear();
}

void ObjDisplayGrid::initRoomGrid(std::shared_ptr<Room> room)
{
    int width = room->getWidth(); //but attributes not saved from handler for some reason
    int height = room->getHeight();
    int posX = room->getPosX(); //if i = posX or i = posX - 1
    int posY = room->getPosY();
    for (int i = posX; i < width + posX; i++) {
        for (int j = posY + topHeight; j < height + posY + topHeight; j++) {
            char c;
            if (i % (width + posX - 1) == 0 || j % (height + topHeight + posY - 1) == 0 || i == posX || j == (posY + topHeight)) {
                c = 'X';
            }
            else {
                c = '.';
            }
            addCharToDisplay(c, i, j);
        }
    }
    //refreshes ncurses
    update();
}
//Not working yet will finish tomorrow on 10/29/2020
void ObjDisplayGrid::initPassageGrid(std::shared_ptr<Passage> passage)
{
    std::vector<int> xVec = passage->getVecX();
    std::vector<int> yVec = passage->getVecY();
    int posX;
    int posY;
    char c = '#'; //iterate from 1 to end of the list. Current point (i) and (i-1) draw all those points
    int posX1;
    int posX2;
    int posY1;
    int posY2;

    for (int i = 1; i < xVec.size(); i++) {
        if (xVec[i] == xVec[i - 1]) {
            if (yVec[i] > yVec[i - 1]) {
                posX1 = xVec[i - 1];
                posY1 = yVec[i - 1];
                posX2 = xVec[i];
                posY2 = yVec[i];
            }
            else {
                posX1 = xVec[i];
                posY1 = yVec[i];
                posX2 = xVec[i - 1];
                posY2 = yVec[i - 1];
            }
        }
        else {
            if (xVec[i] > xVec[i - 1]) {
                posX1 = xVec[i - 1];
                posY1 = yVec[i - 1];
                posX2 = xVec[i];
                posY2 = yVec[i];
            }
            else {
                posX1 = xVec[i];
                posY1 = yVec[i];
                posX2 = xVec[i - 1];
                posY2 = yVec[i - 1];
            }
        }
        for (int j = posX1; j <= posX2; j++) {
            for (int k = posY1; k <= posY2; k++) {
                if (objectGrid[j][k + topHeight]->getChar() == 'X') {
                    addCharToDisplay('+', j, k + topHeight);
                }
                else {
                    addCharToDisplay(c, j, k + topHeight);
                }
            }

        }
    }
    //refreshes ncurses
    update();
}

void ObjDisplayGrid::initCreatureGrid(std::shared_ptr<Creature> creature, std::shared_ptr<Room> room)
{   
    //make error validation if creature is on our outside dungeon boundries or rooms
    char c;
    std::string name = creature->getName();
    std::transform(name.begin(), name.end(), name.begin(), ::tolower);
    
    if (name == "player") {
        player = std::dynamic_pointer_cast<Player>(creature); //cast to player eventually
        c = '@';
        std::string hpVal = std::to_string(creature->getHP());
        setTopMessage(0, "HP: " + hpVal + " Score: ");
        creature->setPosX(creature->getPosX() + room->getPosX());
        creature->setPosY(creature->getPosY() + room->getPosY() + topHeight);
        addCharToDisplay(c, creature->getPosX(), creature->getPosY());
    }
    else {
        c = creature->getType();
        creature->setPosX(creature->getPosX() + room->getPosX());
        creature->setPosY(creature->getPosY() + room->getPosY() + topHeight);
        addObjectToDisplay(c, creature->getPosX(), creature->getPosY(), creature);
    }

    update();
}

void ObjDisplayGrid::initItemGrid(std::shared_ptr<Item> item, std::shared_ptr<Room> room) {
    char c;
    std::shared_ptr<Scroll> scroll = std::dynamic_pointer_cast<Scroll>(item);
    std::shared_ptr<Armor> armor = std::dynamic_pointer_cast<Armor>(item);
    std::shared_ptr<Sword> sword = std::dynamic_pointer_cast<Sword>(item);
    if (scroll) {
        c = '?';
    }
    else if (armor) {
        c = ']';
    }
    else if (sword) {
        c = ')';
    }
    else {
        return;
    }
    addObjectToDisplay(c, item->getPosX() + room->getPosX()
        , item->getPosY() + room->getPosY() + topHeight, item);
    update();
}

//added destructor 10/21/20
ObjDisplayGrid::~ObjDisplayGrid()
{
    // free memory from the dynamically sized object grid
    for (int i = 0; i < width; i++) {
        // delete all character objects in the grid
        for (int j = 0; j < gameHeight; j++) {
            delete objectGrid[i][j];
        }
        // delete the column
        delete[] objectGrid[i];
    }
    // delete the array of columns
    delete[] objectGrid;
    objectGrid = NULL;

    // free ncurses data
    endwin();
}

std::shared_ptr<ObjDisplayGrid> ObjDisplayGrid::getObjDisplayGrid(int _gameHeight, int _width, int _topHeight) {
    if (instance == nullptr) {
        instance = std::shared_ptr<ObjDisplayGrid>(new ObjDisplayGrid(_width, _gameHeight, _topHeight, botHeight));
        instance->gameHeight = _gameHeight;
        instance->width = _width;
        instance->topHeight = _topHeight;
    }
    
    return instance;
}

void ObjDisplayGrid::setTopMessageHeight(int _topHeight) {
    instance->topHeight = _topHeight;
}

void ObjDisplayGrid::addCharToDisplay(char ch, int x, int y) {
    // note grid objects start from 0,0 and go until width,height
    // x between 0 and width
    if ((0 <= x) && (x < width)) {
        // y between 0 and height
        if ((0 <= y) && (y < gridHeight)) { //valid on the whole grid
            // delete existing character if present


            // add new character to the internal character list
            objectGrid[x][y]->addChar(ch);
            // draws the character on the screen, note it is relative to 0,0 of the terminal
            mvaddch(y, x, objectGrid[x][y]->getChar());
        }
    }
}

void ObjDisplayGrid::addObjectToDisplay(char ch, int x, int y, std::shared_ptr<Displayable> object) {
    // note grid objects start from 0,0 and go until width,height
    // x between 0 and width
    if ((0 <= x) && (x < width)) {
        // y between 0 and height
        if ((0 <= y) && (y < gridHeight)) { //valid on the whole grid
            // delete existing character if present


            // add new character to the internal character list
            objectGrid[x][y]->addChar(ch);
            objectGrid[x][y]->addObject(object);
            // draws the character on the screen, note it is relative to 0,0 of the terminal
            mvaddch(y, x, objectGrid[x][y]->getChar());
        }
    }
}

void ObjDisplayGrid::moveObject(char ch, int newX, int newY, int oldX, int oldY, bool * _run) {
    // note grid objects start from 0,0 and go until width,height
    // x between 0 and width
    if ((0 <= newX) && (newX < width)) {
        // y between 0 and height
        if ((0 <= newY) && (newY < gameHeight)) {
            //Hitting monster case
            if (objectGrid[newX][newY]->getChar() == 'T' ||
                objectGrid[newX][newY]->getChar() == 'S' ||
                objectGrid[newX][newY]->getChar() == 'H')
            {
                std::shared_ptr<Creature> monster = std::dynamic_pointer_cast<Monster>(objectGrid[newX][newY]->getObject());
                /*step1 : player hits monster
                step2 : check if monster is alive
                step3a : monster alive, monster hits player
                step3b : monster dead, drop item, execute YouWin
                step4 : check if player dead
                step5 : if player dead, execute EndGame*/
                std::string mName;
                if (objectGrid[newX][newY]->getChar() == 'T') { mName = "Troll"; }
                else if (objectGrid[newX][newY]->getChar() == 'S') { mName = "Snake"; }
                else if (objectGrid[newX][newY]->getChar() == 'H') { mName = "Hobgoblin"; }

                monster->getHit(player);
                monster->executeHA(this);
                setTopMessage(0, "HP: " + std::to_string(player->getHP()) + " Score: 1337"); //sets score and HP
                if (monster->getHP() <= 0) {
                    monster->executeDA(this);
                    //Assuming dungeon has a copy of every monster so I can freely pop it from grid
                    objectGrid[newX][newY]->popChar();
                    objectGrid[newX][newY]->popObject();
                    mvaddch(newY, newX, objectGrid[newX][newY]->getChar());
                    
                    //std::string msg = monster->executeDAmsg("YouWin");
                    //setInfo(msg);
                    //I think the monsters drop there stuff and should be handled here
                }
                else {
                    int damage_dealt = player->getHit(monster);
                    std::string mDmgStr = mName + " did " + std::to_string(damage_dealt) + " dmg to player. ";
                    setInfo(mDmgStr, ""); //sets dmg info when attacking
                    player->executeHA(this);
                    if (player->getHP() < 0) {
                        //execute EndGame action here
                        objectGrid[oldX][oldY]->popChar();
                        mvaddch(oldY, oldX, objectGrid[oldX][oldY]->getChar());
                        char deathChar = player->executeDA(this);
                        if (deathChar != NULL) {
                            objectGrid[oldX][oldY]->addChar(deathChar);
                            mvaddch(oldY, oldX, objectGrid[oldX][oldY]->getChar());
                        }
                        *_run = false;
                        setTopMessage(0, "HP: " + std::to_string(player->getHP()) + " Score: 1337");

                    }
                }
            }
            //normal movement case
            else if (objectGrid[newX][newY]->getChar() != 'X' && objectGrid[newX][newY]->getChar() != ' ') {
                // add new character to the internal character list
                objectGrid[newX][newY]->addChar(ch);
                objectGrid[oldX][oldY]->popChar();
                player->setPosX(newX);
                player->setPosY(newY);
                // draws the character on the screen, note it is relative to 0,0 of the terminal
                mvaddch(newY, newX, objectGrid[newX][newY]->getChar());
                mvaddch(oldY, oldX, objectGrid[oldX][oldY]->getChar());
            }
        }
    }
}

void ObjDisplayGrid::setTopMessage(int line, std::string _message)
{
    // messages start from 0, height and go until width,(height + messages)
    mvaddstr(line, 0, _message.c_str());
    // clear after what we wrote to EOL
    clrtoeol();
}

void ObjDisplayGrid::setBotMessage(int line, std::string _topMessage, std::string _botMessage)
{
    // messages start from 0, height and go until width,(height + messages)
    if (!_topMessage.empty())
    mvaddstr(gridHeight - botHeight + line - 1, 0, _topMessage.c_str());
    if (!_botMessage.empty()) {
        std::string btMsg = "      " + _botMessage;
        mvaddstr(gridHeight - botHeight + line, 0, btMsg.c_str());
    }
    
    // clear after what we wrote to EOL
    clrtoeol();
}

void ObjDisplayGrid::setInfo(std::string _topMessage, std::string _botMessage)
{
    ObjDisplayGrid::setBotMessage(3, "Info: " + _topMessage, _botMessage);
}

void ObjDisplayGrid::dispPackMsg()
{
    //only update when 'i' is pressed
    std::string packMsg = "Pack: ";

    std::vector<std::shared_ptr<Item>> pPack = player->getPack();
    for (int i = 0; i < pPack.size(); i++) {
        if (std::shared_ptr<Sword> item = std::dynamic_pointer_cast<Sword>(pPack[i])) 
        {
            if (i > 0) {
                packMsg = packMsg + ", ";
            }
            packMsg = packMsg + std::to_string(i+1) + ": " + item->getName();
        }
        else if (std::shared_ptr<Armor> item = std::dynamic_pointer_cast<Armor>(pPack[i]))
        {
            if (i > 0) {
                packMsg = packMsg + ", ";
            }
            packMsg = packMsg + std::to_string(i+1) + ": " + item->getName();
        }
        else if (std::shared_ptr<Scroll> item = std::dynamic_pointer_cast<Scroll>(pPack[i]))
        {
            if (i > 0) {
                packMsg = packMsg + ", ";
            }
            packMsg = packMsg + std::to_string(i+1) + ": " + item->getName();
        }
    }
    ObjDisplayGrid::setBotMessage(0, packMsg, "");
}


void ObjDisplayGrid::pickItem(int _x, int _y) {
    char temp = objectGrid[_x][_y]->getChar();
    if (objectGrid[_x][_y]->checkItem() == '?' ||
        objectGrid[_x][_y]->checkItem() == ']' ||
        objectGrid[_x][_y]->checkItem() == ')')
    {
        std::shared_ptr<Item> itemPick = std::dynamic_pointer_cast<Item> (objectGrid[_x][_y]->getObject());

        //add item to player inventory
        if (objectGrid[_x][_y]->checkItem() == ')') {
            std::shared_ptr<Sword> addItem = std::dynamic_pointer_cast<Sword> (itemPick);
            setInfo("adding " + addItem->getName() + " to the pack", ""); //adds item to pack
        }
        else if (objectGrid[_x][_y]->checkItem() == ']') {
            std::shared_ptr<Armor> addItem = std::dynamic_pointer_cast<Armor> (itemPick);
            setInfo("adding " + addItem->getName() + " to the pack", ""); //adds item to pack
        }
        else {
            std::shared_ptr<Scroll> addItem = std::dynamic_pointer_cast<Scroll> (itemPick);
            setInfo("adding " + addItem->getName() + " to the pack", ""); //adds item to pack
        }

        player->addItem(itemPick);
        objectGrid[_x][_y]->popChar();
        objectGrid[_x][_y]->popObject();
    }
}

void ObjDisplayGrid::dropItem(int _x, int _y, int _itemPos) {
    if (player->isPackEmpty()) {
        setInfo("Pack is empty", "");
        return;
    }

    std::shared_ptr<Item> item = player->dropItem(_itemPos);
    if (item) {
        char c;

        std::shared_ptr<Scroll> scroll = std::dynamic_pointer_cast<Scroll>(item);
        std::shared_ptr<Armor> armor = std::dynamic_pointer_cast<Armor>(item);
        std::shared_ptr<Sword> sword = std::dynamic_pointer_cast<Sword>(item);

        if (scroll) { c = '?'; setInfo("Dropping " + scroll->getName(), ""); }
        else if (armor) { c = ']'; setInfo("Dropping " + armor->getName(), ""); }
        else if (sword) { c = ')'; setInfo("Dropping " + sword->getName(), ""); }
        
        objectGrid[_x][_y]->popChar();
        addObjectToDisplay(c, _x, _y, item);
        addCharToDisplay('@', _x, _y);
    }
    
}

void ObjDisplayGrid::update() {
    // refreshes ncurses
    refresh();
}

