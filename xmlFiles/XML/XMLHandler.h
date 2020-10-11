#ifndef XMLHANDLER_H_
#define XMLHANDLER_H_

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include "Dungeon.h"
#include "ObjDisplayGrid.h"
#include "Structure.h"
#include "Creature.h"
#include "Item.h"
//#include "Magic.h" resolve later
#include "Room.h"
#include "Passage.h"
//#include "Player.h"
//#include "Monstor.h"
#include "Scroll.h"
#include "Armor.h"
#include "Sword.h"
#include "Action.h"
//#include "CreatureAction.h"
//#include "ItemAction.h"
#include "Teleport.h"
#include "Remove.h"
#include "ChangeDisplayedType.h"
#include "DropPack.h"
#include "YouWin.h"
#include "EndGame.h"
#include "UpdateDisplay.h"

#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/sax2/Attributes.hpp>

class XMLHandler : public xercesc::DefaultHandler {
private:
    int DEBUG = 1;
    std::string CLASSID = "XMLHandler";
    std::string data;
    
    //int creatureCount = 0;
    Dungeon* dungeonBeingParsed;
    //std::vector<Room> rooms;
    //int roomCount = 0;
    Room* roomBeingParsed;
    std::shared_ptr<Player> playerBeingParsed;
    CreatureAction* creatureActionBeingParsed;
    std::shared_ptr<Monster> monsterBeingParsed;
    Scroll* scrollBeingParsed;
    ItemAction* itemActionBeingParsed;
    Armor* armorBeingParsed;
    Sword* swordBeingParsed;
    Passage* passageBeingParsed; //not sure about this. Didnt see an example of this in the xml files
   
    std::shared_ptr<Creature> creatureP;

    //Add more bool values
    bool bVisible = false;
    bool bPosX = false;
    bool bPosY = false;
    bool bHp = false;
    bool bMaxHit = false;
    bool bHpMoves = false;
    bool bActionMessage = false;
    bool bWidth = false;
    bool bHeight = false;
    bool bType = false;
    bool bActionCharValue = false;
    bool bItemIntValue = false;
    bool bActionIntValue = false;
    
    //bool bDungeon = false;
    //bool bRooms = false;
    bool bRoom = false;
    bool bMonster = false;
    bool bPlayer = false;
    bool bArmor = false;
    bool bSword = false;
    bool bScroll = false;
    bool bCreatureAction = false;


public:
    XMLHandler();
    void startElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName, const xercesc::Attributes& attributes);
    void endElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName);
    void fatalError(const xercesc::SAXParseException&);
    void characters(const XMLCh* const ch, const XMLSize_t length);
    std::string toString();
};

#endif