<<<<<<< HEAD
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
            addObjectToDisplay(c, i, j);
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
    //not done yet. Still need to make modifications
    /*for (int i = 0; i < width + xVec.size(); i++) {
        posX = xVec[i];
        posY = yVec[i];
        for (int j = yVec[i] + topHeight; j < topHeight + yVec[i] + topHeight; j++) {
            addObjectToDisplay(c, i, j);
        }
    }*/
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
                    addObjectToDisplay('+', j, k + topHeight);
                }
                else {
                    addObjectToDisplay(c, j, k + topHeight);
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
        player = creature; //cast to player eventually
        c = '@';
    }
    else {
        c = creature->getType();
    }

    creature->setPosX(creature->getPosX() + room->getPosX());
    creature->setPosY(creature->getPosY() + room->getPosY() + topHeight);
    addObjectToDisplay(c, creature->getPosX(), creature->getPosY());
    //addObjectToDisplay(c, creature->getPosX() + room->getPosX()
     //   , creature->getPosY() + room->getPosY() + topHeight);

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
        , item->getPosY() + room->getPosY() + topHeight);
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
   // std::cout << "ObjDisplayGrid::getObjDisplayGrid" << std::endl;
    
    return instance;
}

void ObjDisplayGrid::setTopMessageHeight(int _topHeight) {
    instance->topHeight = _topHeight;
    //std::cout << "ObjDisplayGrid::setTopMessageHeight" << std::endl;
    //std::cout << "TopMessageHeight: " << std::to_string(instance -> topHeight) << std::endl;
}

void ObjDisplayGrid::addObjectToDisplay(char ch, int x, int y) {
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

void ObjDisplayGrid::moveObject(char ch, int newX, int newY, int oldX, int oldY) {
    // note grid objects start from 0,0 and go until width,height
    // x between 0 and width
    if ((0 <= newX) && (newX < width)) {
        // y between 0 and height
        if ((0 <= newY) && (newY < gameHeight + topHeight)) { // only valid in game area
            // add new character to the internal character list
            objectGrid[newX][newY]->addChar(ch);
            objectGrid[oldX][oldY]->popChar();
            // draws the character on the screen, note it is relative to 0,0 of the terminal
            mvaddch(newY, newX, objectGrid[newX][newY]->getChar());
            mvaddch(oldY, oldX, objectGrid[oldX][oldY]->getChar());
        }
    }
}


void ObjDisplayGrid::update() {
    // refreshes ncurses
    refresh();
}

=======
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
    int gridHeight = gameHeight + topHeight + botHeight;
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
    COORD size = { (short)width, (short)(gameHeight + topHeight) };
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
            if (i % (width + posX - 1) == 0 || j % (height + topHeight + posY - 1) == 0 || i == posX || j == posY + topHeight) {
                c = 'X';
            }
            else {
                c = '.';
            }
            addObjectToDisplay(c, i, j);
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
    //not done yet. Still need to make modifications
   /* for (int i = 0; i < width + xVec[i]; i++) {
        posX = xVec[i];
        posY = yVec[i];
        for (int j = yVec[i] + topHeight; j < topHeight + yVec[i] + topHeight; j++) {
            addObjectToDisplay(new GridChar(c), i, j);
        }
    }*/
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
        player = creature; //cast to player eventually
        c = '@';
    }
    else {
        c = creature->getType();
    }

    creature->setPosX(creature->getPosX() + room->getPosX());
    creature->setPosY(creature->getPosY() + room->getPosY() + topHeight);
    addObjectToDisplay(c, creature->getPosX(), creature->getPosY());
    //addObjectToDisplay(c, creature->getPosX() + room->getPosX()
     //   , creature->getPosY() + room->getPosY() + topHeight);

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
        , item->getPosY() + room->getPosY() + topHeight);
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
   // std::cout << "ObjDisplayGrid::getObjDisplayGrid" << std::endl;
    
    return instance;
}

void ObjDisplayGrid::setTopMessageHeight(int _topHeight) {
    instance->topHeight = _topHeight;
    //std::cout << "ObjDisplayGrid::setTopMessageHeight" << std::endl;
    //std::cout << "TopMessageHeight: " << std::to_string(instance -> topHeight) << std::endl;
}

void ObjDisplayGrid::addObjectToDisplay(char ch, int x, int y) {
    // note grid objects start from 0,0 and go until width,height
    // x between 0 and width
    if ((0 <= x) && (x < width)) {
        // y between 0 and height
        if ((0 <= y) && (y < gameHeight)) {
            // delete existing character if present


            // add new character to the internal character list
            objectGrid[x][y]->addChar(ch);
            // draws the character on the screen, note it is relative to 0,0 of the terminal
            mvaddch(y, x, objectGrid[x][y]->getChar());
        }
    }
}

void ObjDisplayGrid::moveObject(char ch, int newX, int newY, int oldX, int oldY) {
    // note grid objects start from 0,0 and go until width,height
    // x between 0 and width
    if ((0 <= newX) && (newX < width)) {
        // y between 0 and height
        if ((0 <= newY) && (newY < gameHeight)) {
            // add new character to the internal character list
            objectGrid[newX][newY]->addChar(ch);
            objectGrid[oldX][oldY]->popChar();
            // draws the character on the screen, note it is relative to 0,0 of the terminal
            mvaddch(newY, newX, objectGrid[newX][newY]->getChar());
            mvaddch(oldY, oldX, objectGrid[oldX][oldY]->getChar());
        }
    }
}


void ObjDisplayGrid::update() {
    // refreshes ncurses
    refresh();
}
>>>>>>> b86a801600ebc70b864534e8c253d7a085d56fe1
