#include <iostream>
#include "ObjDisplayGrid.h"
#include <curses.h>
#ifdef _WIN32
#include <windows.h>
#endif

std::shared_ptr<ObjDisplayGrid> ObjDisplayGrid::instance = nullptr;

ObjDisplayGrid::ObjDisplayGrid(int _width, int _gameHeight, int _topHeight) :
    width(_width), gameHeight(_gameHeight), topHeight(_topHeight) {
    //2D array of GridChars
    objectGrid = new GridChar * *[width];

    for (int i = 0; i < width; i++) {
        objectGrid[i] = new GridChar * [gameHeight];
        for (int j = 0; j < gameHeight; j++) {
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
        instance = std::shared_ptr<ObjDisplayGrid>(new ObjDisplayGrid(_width, _gameHeight, _topHeight));
        instance->gameHeight = _gameHeight;
        instance->width = _width;
        instance->topHeight = _topHeight;
    }
   // std::cout << "ObjDisplayGrid::getObjDisplayGrid" << std::endl;
    
    return instance;
}

void ObjDisplayGrid::setTopMessageHeight(int _topHeight) {
    instance->topHeight = _topHeight;
    std::cout << "ObjDisplayGrid::setTopMessageHeight" << std::endl;
    std::cout << "TopMessageHeight: " << std::to_string(instance -> topHeight) << std::endl;
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
