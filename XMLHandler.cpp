#include "XMLHandler.h"

int case_insensitive_match(std::string s1, std::string s2) {
    //convert s1 and s2 into lower case strings
    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower); //std overloads tolower, ::tolower is the definition in the global namespace
    std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    if (s1.compare(s2) == 0)
        return 1;
    return 0;
}

inline std::string boolToString(bool booleanValue) {
    return booleanValue ? "true" : "false";
}

//getvector function?

XMLHandler::XMLHandler() {

}

std::string xmlChToString(const XMLCh* xmlChName, int length = -1) {
    //Xerces Parses file into XMLCh* string. So use Transcode to allocate a char* buffer
    char* chStarName = xercesc::XMLString::transcode(xmlChName);
    if (length == -1) {
        std::string StrName(chStarName);
        xercesc::XMLString::release(&chStarName);
        return StrName;
    }
    else {
        std::string StrName(chStarName, 0, length);
        xercesc::XMLString::release(&chStarName);
        return StrName;
    }

}

const XMLCh* getXMLChAttributeFromString(const xercesc::Attributes& attributes, const char* strGet) {
    XMLCh* xmlChGet = xercesc::XMLString::transcode(strGet);
    const XMLCh* xmlChAttr = attributes.getValue(xmlChGet);
    xercesc::XMLString::release((&xmlChGet));
    return xmlChAttr;
}

void XMLHandler::startElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName, const xercesc::Attributes& attributes) {

    char* qNameStr = xercesc::XMLString::transcode(qName);
    if (DEBUG > 1) {
        std::cout << CLASSID << ".startElement qName: " << qNameStr << std::endl;
    }

    if (case_insensitive_match(qNameStr, "Dungeon")) {
        std::string dungeonName = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        int width = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "width")));
        int topHeight = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "topHeight")));
        int gameHeight = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "gameHeight")));
        int bottomHeight = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "bottomHeight")));
        dungeonBeingParsed = std::shared_ptr<Dungeon> (new Dungeon(dungeonName, width, topHeight, gameHeight, bottomHeight)); //insert above values here once Dungeon class is written
        dungeonBeingParsed->getDungeon(dungeonName, width, topHeight, gameHeight, bottomHeight);
        //bDungeon = true;
    }
    else if (case_insensitive_match(qNameStr, "Rooms")) {} //not sure what to do here
    else if (case_insensitive_match(qNameStr, "Room")) {
        int roomID = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
        roomBeingParsed = std::shared_ptr<Room>(new Room(std::to_string(roomID))); //room constructor requires a string but xml doesnt give one.
        roomBeingParsed->setID(roomID);
        dungeonBeingParsed->addRoom(roomBeingParsed); //make addRoom take pointer type
        bMonster = false; //want these values to be false when entering new room hope it's ok
        bPlayer = false;
        bRoom = true;
    }
    else if (case_insensitive_match(qNameStr, "Passages")) {}
    else if (case_insensitive_match(qNameStr, "Passage")) {
        int roomID1 = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room1")));
        int roomID2 = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room2")));
        passageBeingParsed = std::shared_ptr<Passage>(new Passage());
        passageBeingParsed->setID(roomID1, roomID2);
        dungeonBeingParsed->addPassage(passageBeingParsed);
        bPassage = true;
    }
    else if (case_insensitive_match(qNameStr, "Monster")) {
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        int roomID = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
        int serialID = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));
        //  int posX = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));
        std::shared_ptr<Monster> monster(new Monster);
        monsterBeingParsed = monster; //make creature reference?
        monsterBeingParsed->setName(name);
        monsterBeingParsed->setID(roomID, serialID);
        dungeonBeingParsed->addCreature(monsterBeingParsed); //Being added later
        roomBeingParsed->setCreature(monsterBeingParsed); //useful for display generation I think
        creatureBeingParsed = monsterBeingParsed;
        bMonster = true;
        bPlayer = false; //I don't know if this is a good fix
    }

    else if (case_insensitive_match(qNameStr, "Player")) {
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        int roomID = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
        int serialID = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));
        std::shared_ptr<Player> player(new Player);
        playerBeingParsed = player;
        playerBeingParsed->setID(roomID, serialID);
        creatureBeingParsed = playerBeingParsed;
        roomBeingParsed->setCreature(playerBeingParsed);
        bPlayer = true;
        bMonster = false;
        bScroll = false;
        bArmor = false;
        bSword = false;
    }

    else if (case_insensitive_match(qNameStr, "Armor")) {
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        int roomID = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
        int serialID = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));
        armorBeingParsed = std::shared_ptr<Armor>(new Armor(name));
        armorBeingParsed->setName(name);
        armorBeingParsed->setID(roomID, serialID);
        itemBeingParsed = armorBeingParsed;
        if (bPlayer) {
            playerBeingParsed->setArmor(armorBeingParsed); //change functionality later
        }
        else {
            roomBeingParsed->setItem(armorBeingParsed);
        }
        
        bArmor = true;
        bSword = false;
        bScroll = false;
    }
    else if (case_insensitive_match(qNameStr, "Sword")) {
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        int roomID = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
        int serialID = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));
        swordBeingParsed = std::shared_ptr<Sword>(new Sword(name)); //if player hasa item this is weird
        //swordBeingParsed->setName(name);
        swordBeingParsed->setID(roomID, serialID);
        itemBeingParsed = swordBeingParsed;
        if (bPlayer) {
            playerBeingParsed->setWeapon(swordBeingParsed); //change functionality later
        }
        else {
            roomBeingParsed->setItem(swordBeingParsed);
        }
        bSword = true; 
        bScroll = false;
        bArmor = false;
    }
    else if (case_insensitive_match(qNameStr, "Scroll")) {
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        int roomID = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
        int serialID = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));
        scrollBeingParsed = std::shared_ptr<Scroll>(new Scroll(name));
        //scrollBeingParsed->setName(name);
        scrollBeingParsed->setID(roomID, serialID);
        itemBeingParsed = scrollBeingParsed;
        roomBeingParsed->setItem(scrollBeingParsed);
        bScroll = true;
        bSword = false;
        bArmor = false;
        bPlayer = false; //Need better way to fix this
    }

    //Not sure about how to do CreatureAction
    else if (case_insensitive_match(qNameStr, "CreatureAction")) {
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        std::string type = xmlChToString(getXMLChAttributeFromString(attributes, "type"));
        std::shared_ptr<CreatureAction> creatureAction(new CreatureAction(creatureBeingParsed));
        if (type.compare("death") == 0) {
            creatureBeingParsed->setDeathAction(creatureAction);  
            creatureAction->setName(name);
        }
        else if (type.compare("death") != 0) {
            creatureBeingParsed->setHitAction(creatureAction);
            creatureAction->setName(name); //don't kow what to put for name here
        }
        actionBeingParsed = creatureAction;
    }
    else if (case_insensitive_match(qNameStr, "ItemAction")) {
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        std::string type = xmlChToString(getXMLChAttributeFromString(attributes, "type"));
        std::shared_ptr<ItemAction> itemAction(new ItemAction());
        itemAction->setName(name);
        itemBeingParsed->setAction(itemAction);
        bItemAction = true;
        actionBeingParsed = itemAction;
       
    }
    else if (case_insensitive_match(qNameStr, "visible")) {
        bVisible = true;
    }
    else if (case_insensitive_match(qNameStr, "posX")) {
        bPosX = true;
    }
    else if (case_insensitive_match(qNameStr, "posY")) {
        bPosY = true;
    }
    else if (case_insensitive_match(qNameStr, "hp")) {
        bHp = true;
    }
    else if (case_insensitive_match(qNameStr, "maxhit")) {
        bMaxHit = true;
    }
    else if (case_insensitive_match(qNameStr, "hpMoves")) {
        bHpMoves = true;
    }
    else if (case_insensitive_match(qNameStr, "actionMessage")) {
        bActionMessage = true;
    }
    else if (case_insensitive_match(qNameStr, "width")) {
        bWidth = true;
    }
    else if (case_insensitive_match(qNameStr, "height")) {
        bHeight = true;
    }
    else if (case_insensitive_match(qNameStr, "type")) {
        bType = true;
    }
    else if (case_insensitive_match(qNameStr, "ActionCharValue")) {
        bActionCharValue = true;
    }
    else if (case_insensitive_match(qNameStr, "ItemIntValue")) {
        bItemIntValue = true;
    }
    else if (case_insensitive_match(qNameStr, "ActionIntValue")) {
        bActionIntValue = true;
    }
    else if (case_insensitive_match(qNameStr, "/Player")) {
        bPlayer = false;
    }
    else {
        std::cout << "Unknown qname: " << qNameStr << std::endl;
    }
    xercesc::XMLString::release(&qNameStr);
        return;
}

void XMLHandler::endElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName) {
    if (bVisible) {
        if (std::stoi(data) == 1) { //if one make visible, else make invisible
            if (bScroll) {
                scrollBeingParsed->setVisible();
                bVisible = false;
            }
            else if (bArmor) {
                armorBeingParsed->setVisible();
                bVisible = false;
            }
            else if (bSword) {
                swordBeingParsed->setVisible();
                bVisible = false;
            }
            else if (bMonster) {
                monsterBeingParsed->setVisible();
                bVisible = false;
            }
            else if (bPlayer) {
                playerBeingParsed->setVisible();
                bVisible = false;
            }
            else if (bRoom) {
                roomBeingParsed->setVisible();
                bVisible = false;
            }
            else if (bPassage) {
                passageBeingParsed->setVisible();
                bVisible = false;
            }
        }
        else {
            if (bScroll) {
                scrollBeingParsed->setInvisible();
                bVisible = false;
            }
            else if (bArmor) {
                armorBeingParsed->setInvisible();
                bVisible = false;
            }
            else if (bSword) {
                swordBeingParsed->setInvisible();
                bVisible = false;
            }
            else if (bMonster) {
                monsterBeingParsed->setInvisible();
                bVisible = false;
            }
            else if (bPlayer) {
                playerBeingParsed->setInvisible();
                bVisible = false;
            }
            else if (bRoom) {
                roomBeingParsed->setInvisible();
                bVisible = false;
            }
            else if (bPassage) {
                passageBeingParsed->setInvisible();
                bVisible = false;
            }
        }
    }
    else if (bPosX) {
        if (bScroll) {
            scrollBeingParsed->setPosX(std::stoi(data));
            bPosX = false;
        }
        else if (bArmor) {
            armorBeingParsed->setPosX(std::stoi(data));
            bPosX = false;
        }
        else if (bSword) {
            swordBeingParsed->setPosX(std::stoi(data));
            bPosX = false;
        }
        else if (bMonster) {
            monsterBeingParsed->setPosX(std::stoi(data));
            bPosX = false;
        }
        else if (bPlayer) {
            playerBeingParsed->setPosX(std::stoi(data));
            bPosX = false;
        }
        else if (bRoom) {
            roomBeingParsed->setPosX(std::stoi(data));
            bPosX = false;
        }
        else if (bPassage) {
            passageBeingParsed->pushVecX(std::stoi(data));
            bPosX = false;
        }
    }
    else if (bPosY) {
        if (bScroll) {
            scrollBeingParsed->setPosY(std::stoi(data));
            bPosY = false;
        }
        else if (bArmor) {
            armorBeingParsed->setPosY(std::stoi(data));
            bPosY = false;
        }
        else if (bSword) {
            swordBeingParsed->setPosY(std::stoi(data));
            bPosY = false;
        }
        else if (bMonster) {
            monsterBeingParsed->setPosY(std::stoi(data));
            bPosY = false;
        }
        else if (bPlayer) {
            playerBeingParsed->setPosY(std::stoi(data));
            bPosY = false;
        }
        else if (bRoom) {
            roomBeingParsed->setPosY(std::stoi(data));
            bPosY = false;
        }
        else if (bPassage) {
            passageBeingParsed->pushVecY(std::stoi(data));
            bPosY = false;
        }
    }
    else if (bWidth) {
        if (bScroll) {
            scrollBeingParsed->setWidth(std::stoi(data));
            bWidth = false;
        }
        else if (bArmor) {
            armorBeingParsed->setWidth(std::stoi(data));
            bWidth = false;
        }
        else if (bSword) {
            swordBeingParsed->setWidth(std::stoi(data));
            bWidth = false;
        }
        else if (bMonster) {
            monsterBeingParsed->setWidth(std::stoi(data));
            bWidth = false;
        }
        else if (bPlayer) {
            playerBeingParsed->setWidth(std::stoi(data));
            bWidth = false;
        }
        else if (bRoom) {
            roomBeingParsed->setWidth(std::stoi(data));
            bWidth = false;
        }
    }
    else if (bHeight) {
        if (bScroll) {
            scrollBeingParsed->setHeight(std::stoi(data));
            bHeight = false;
        }
        else if (bArmor) {
            armorBeingParsed->setHeight(std::stoi(data));
            bHeight = false;
        }
        else if (bSword) {
            swordBeingParsed->setHeight(std::stoi(data));
            bHeight = false;
        }
        else if (bMonster) {
            monsterBeingParsed->setHeight(std::stoi(data));
            bHeight = false;
        }
        else if (bPlayer) {
            playerBeingParsed->setHeight(std::stoi(data));
            bHeight = false;
        }
        else if (bRoom) {
            roomBeingParsed->setHeight(std::stoi(data));
            bHeight = false;
        }
    }
    else if (bHp) {

        if (bMonster) {
            monsterBeingParsed->setHp(std::stoi(data));
            bHp = false;
        }
        else if (bPlayer) {
            playerBeingParsed->setHp(std::stoi(data));
            bHp = false;
        }
    }
    else if (bMaxHit) {
        if (bMonster) {
            monsterBeingParsed->setMaxHit(std::stoi(data));
            bMaxHit = false;
        }
        else if (bPlayer) {
            playerBeingParsed->setMaxHit(std::stoi(data));
            bMaxHit = false;
        }
    }
    else if (bHpMoves) {
        playerBeingParsed->setHpMoves(std::stoi(data));
        bHpMoves = false;
    }
    else if (bActionMessage) {
        actionBeingParsed->setMessage(data);
        bActionMessage = false;
    }
    else if (bType) {
        if (bMonster) {
            monsterBeingParsed->setType(data[0]);
            bType = false;
        }
    }
    else if (bActionCharValue) {
        actionBeingParsed->setCharValue(data[0]);
        bActionCharValue = false;
    }
    else if (bItemIntValue) {
        /*if (bScroll) {
            actionBeingParsed->setIntValue(std::stoi(data));
        }
        else if (bArmor) {
            actionBeingParsed->setIntValue(std::stoi(data));
        }
        else if (bSword) {
            actionBeingParsed->setIntValue(std::stoi(data));
        }*/
        if (bArmor) {
            armorBeingParsed->setIntValue(std::stoi(data));
        }
        else if (bSword) {
            swordBeingParsed->setIntValue(std::stoi(data));
        }
        bItemIntValue = false;
    }
    else if (bActionIntValue) {
        actionBeingParsed->setIntValue(std::stoi(data));
        bActionIntValue = false;
    }
    else if (bSword) {
        bSword = false;
    }
    else if (bScroll) {
        bScroll = false;
    }
    else if (bArmor) {
        bArmor = false;
    }
    else if (bPlayer) {
        bRoom = false;
    }
    else if (bMonster) {
        bRoom = false;
    }
    else if (bRoom) {
        bRoom = false;
    }
    else if (bPassage) {
        bPassage = false;
    }

}

void XMLHandler::characters(const XMLCh* const ch, const XMLSize_t length) {
    data = xmlChToString(ch, (int)length);
    if (DEBUG > 1) {
        std::cout << CLASSID + ".characters: " << data << std::endl;
        std::cout.flush();
    }
}

std::shared_ptr<Dungeon> XMLHandler::getDungeon()
{
    return dungeonBeingParsed;
}

void XMLHandler::fatalError(const xercesc::SAXParseException& exception) {
    char* message = xercesc::XMLString::transcode(exception.getMessage());
    std::cout << "Fatal Error: " << message
        << " at line: " << exception.getLineNumber()
        << std::endl;
    xercesc::XMLString::release(&message);
}