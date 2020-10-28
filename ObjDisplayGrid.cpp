#include <iostream>
#include "ObjDisplayGrid.h"
#include <curses.h>
#include <algorithm>
#ifdef _WIN32
#include <windows.h>
#endif

std::shared_ptr<ObjDisplayGrid> ObjDisplayGrid::instance = nullptr;

ObjDisplayGrid::ObjDisplayGrid(int _width, int _gameHeight, int _topHeight, int _botHeight) :
    width(_width), gameHeight(_gameHeight), topHeight(_topHeight), botHeight(_botHeight) {
    //2D array of GridChars
    objectGrid = new GridChar **[width]; //make a 2d array that has 1 vectir of GridChar
    //std::vector<GridChar>** pop character if it leaves
    int gridHeight = gameHeight + topHeight + botHeight;
    for (int i = 0; i < width; i++) {
        objectGrid[i] = new GridChar * [gridHeight];
        for (int j = 0; j < gridHeight; j++) { //topHeight bad for some reason
            objectGrid[i][j] = NULL;
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
            addObjectToDisplay(new GridChar(c), i, j);
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
    for (int i = 0; i < width + xVec[i]; i++) {
        posX = xVec[i];
        posY = yVec[i];
        for (int j = yVec[i] + topHeight; j < topHeight + yVec[i] + topHeight; j++) {
            addObjectToDisplay(new GridChar(c), i, j);
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
        c = '@';
    }
    else {
        c = creature->getType();
    }
    addObjectToDisplay(new GridChar(c), creature->getPosX() + room->getPosX()
        , creature->getPosY() + room->getPosY() + topHeight);

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

void ObjDisplayGrid::addObjectToDisplay(GridChar* ch, int x, int y) {
    // note grid objects start from 0,0 and go until width,height
    // x between 0 and width
    if ((0 <= x) && (x < width)) {
        // y between 0 and height
        if ((0 <= y) && (y < gameHeight)) {
            // delete existing character if present
            if (objectGrid[x][y] != NULL) {
                delete objectGrid[x][y];
            }

            // add new character to the internal character list
            objectGrid[x][y] = ch;
            // draws the character on the screen, note it is relative to 0,0 of the terminal
            mvaddch(y, x, ch->getChar());
        }
    }
}

void ObjDisplayGrid::update() {
    // refreshes ncurses
    refresh();
}

