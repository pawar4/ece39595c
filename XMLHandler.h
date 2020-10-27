#ifndef XMLHANDLER_H_
#define XMLHANDLER_H_

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <memory>
#include "Dungeon.h"
#include "ObjDisplayGrid.h"
#include "Structure.h"
#include "Creature.h"
#include "Item.h"
#include "Magic.h"
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
    
    
    std::shared_ptr<Dungeon> dungeonBeingParsed;
    
    std::shared_ptr<Room> roomBeingParsed;
    std::shared_ptr<Player> playerBeingParsed;
    std::shared_ptr<Monster> monsterBeingParsed;
    std::shared_ptr<Scroll> scrollBeingParsed;
    std::shared_ptr<Armor> armorBeingParsed;
    std::shared_ptr<Sword> swordBeingParsed;
    std::shared_ptr<Passage> passageBeingParsed; //not sure about this. Didnt see an example of this in the xml files
   
    std::shared_ptr<Creature> creatureBeingParsed;
    std::shared_ptr<Action> actionBeingParsed;
    std::shared_ptr<Item> itemBeingParsed;


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
    bool bItemAction = false;
    bool bPassage = false;
    bool bRoom = false;
    bool bMonster = false;
    bool bPlayer = false;
    bool bArmor = false;
    bool bSword = false;
    bool bScroll = false;

public:
    XMLHandler();
    void startElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName, const xercesc::Attributes& attributes);
    void endElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName);
    void fatalError(const xercesc::SAXParseException&);
    void characters(const XMLCh* const ch, const XMLSize_t length);
    std::string toString();
};

#endif