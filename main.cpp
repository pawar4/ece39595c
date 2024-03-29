#include <iostream>
#include <string>
#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/XMLUni.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include "XMLHandler.h"
#include <exception>
//added 10/21/20
#include "GridChar.h"
#include <atomic>
#include <thread> //will need to use threads probably for mouse inputs
#include <vector>

int main(int argc, char* argv[]) {
   
    std::string fileName;
    std::shared_ptr<Dungeon> dungeon;// = std::shared_ptr<Dungeon>(new Dungeon("unit", 0, 0, 0, 0, 0));
    try {
        xercesc::XMLPlatformUtils::Initialize();
    }
    catch (const xercesc::XMLException& toCatch) {
        char* message = xercesc::XMLString::transcode(toCatch.getMessage());
        std::cout << "Error during initialization! :\n";
        std::cout << "Exception message is: \n"
            << message << "\n";
        xercesc::XMLString::release(&message);
        return 1;
    }
    switch (argc) {
    case 2:
        fileName = "./xmlfiles/" + ((std::string) argv[1]);
        break;
    default:
        std::cout << "C++ Test <xmlfilename>" << std::endl;
    }
    xercesc::SAX2XMLReader* parser = xercesc::XMLReaderFactory::createXMLReader();

    try {
        XMLHandler* handler = new XMLHandler();
        parser->setContentHandler(handler);
        parser->setErrorHandler(handler);
        parser->setFeature(xercesc::XMLUni::fgSAX2CoreValidation, true);
        parser->setFeature(xercesc::XMLUni::fgSAX2CoreNameSpaces, true);
        XMLCh* fileNameXMLEnc = xercesc::XMLString::transcode(fileName.c_str()); //Encode string as UTF-16, but transcode needs casting as const char * (not std::string)
        parser->parse(fileNameXMLEnc);
        xercesc::XMLString::release(&fileNameXMLEnc);
        //Do not need to print anything here because the functions do that alrady;
        //should the values be printed out though?

        dungeon = handler->getDungeon();
 
        delete parser;
        delete handler;

    } 
    catch (const xercesc::XMLException& toCatch) {
        char* message = xercesc::XMLString::transcode(toCatch.getMessage());
        std::cout << "Exception message is: \n"
            << message << "\n";
        xercesc::XMLString::release(&message);
        return -1;
    }
    catch (const xercesc::SAXParseException& toCatch) {
        char* message = xercesc::XMLString::transcode(toCatch.getMessage());
        std::cout << "Exception message is: \n"
            << message << "\n";
        xercesc::XMLString::release(&message);
        return -1;
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
    catch (...) {
        std::cout << "Unexpected Exception \n";
        return -1;
    }
    xercesc::XMLPlatformUtils::Terminate(); //valgrind will say there's memory errors if not included
    

    //Start of PDcurses calls for dungeon generation
    std::atomic_bool isRunning(true); //used for atomicity, though not sure exactly why
    //ObjDisplayGrid grid() start displaying in parser maybe?

    /*
    * Make 3 objDisplayGrids
    * 1. Room
    *   . Use the Room vector under dungeon and start adding rooms to obj display grid
    * 2. Passage
    * 3. Creatures/Items
    * Need to fix XMLHandler later
    */
    //dungeon->getRooms();
    std::vector<std::shared_ptr<Room>> rooms = dungeon->getRooms();
    ObjDisplayGrid grid(dungeon->getWidth(), dungeon->getGameHeight(), dungeon->getTopHeight());
    ObjDisplayGrid* pgrid = &grid;
    //pgrid->initRoomGrid(rooms[0]);
   
    for (int i = 0; i < rooms.size(); i++) {
        pgrid->initRoomGrid(rooms[i]);
    }
    std::shared_ptr<Creature> player(new Player);
    //Just to test funcitonality it seems like it works, so nice
    //Still have to figure out why all the things dissapear after parser class closes
    player->setName("player");
    player->setPosX(2);
    player->setPosY(2);
    pgrid->initCreatureGrid(player);
    return 0;
}