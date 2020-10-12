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
        dungeonBeingParsed = new Dungeon(); //insert above values here once Dungeon class is written
        //bDungeon = true;
    }
    else if (case_insensitive_match(qNameStr, "Rooms")) {} //not sure what to do here
    else if (case_insensitive_match(qNameStr, "Room")) {
        int roomID = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
        roomBeingParsed = new Room("lol"); //room constructor requires a string but xml doesnt give one.
        roomBeingParsed->setID(roomID);
        dungeonBeingParsed->addRoom(roomBeingParsed); //make addRoom take pointer type
        bRoom = true;
    }
    else if (case_insensitive_match(qNameStr, "Monster")) {
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        int roomID = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
        int serialID = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));
        //  int posX = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));
        std::shared_ptr<Monster> monster(new Monster);
        monsterBeingParsed = monster; //make creature reference?
        monsterBeingParsed -> setName(name);
        monsterBeingParsed->setID(roomID, serialID);
        dungeonBeingParsed->addMonster(monsterBeingParsed); //Being added later
        creatureP = monsterBeingParsed;
        bMonster = true;
    }

    else if (case_insensitive_match(qNameStr, "Player")) {
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        int roomID = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
        int serialID = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));
        std::shared_ptr<Player> player(new Player);
        playerBeingParsed = player;
        playerBeingParsed->setID(roomID, serialID);
        creatureP = playerBeingParsed;
        bPlayer = true;
    }

    else if (case_insensitive_match(qNameStr, "Armor")) {
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        int roomID = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
        int serialID = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));
        armorBeingParsed = new Armor(name);
        armorBeingParsed->setID(roomID, serialID);
        bArmor = true;
    }
    else if (case_insensitive_match(qNameStr, "Sword")) {
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        int roomID = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
        int serialID = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));
        swordBeingParsed = new Sword(name);
        swordBeingParsed->setID(roomID, serialID);
        bSword = true;
    }
    else if (case_insensitive_match(qNameStr, "Scroll")) {
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        int roomID = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
        int serialID = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));
        scrollBeingParsed = new Scroll(name);
        scrollBeingParsed->setID(roomID, serialID);
        bScroll = true;
    }

    //Not sure about how to do CreatureAction
    else if (case_insensitive_match(qNameStr, "CreatureAction")) {
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        std::string type = xmlChToString(getXMLChAttributeFromString(attributes, "type"));
        CreatureAction * creatureAction;
        if (type.compare("death") == 0) {
            creatureP->setDeathAction(creatureAction);
        }
        creatureActionBeingParsed = creatureAction;
        bCreatureAction = true;
    }
    else if (case_insensitive_match(qNameStr, "posX")) {
        bPosX = true;
    }
    else if (case_insensitive_match(qNameStr, "posY")) {
        bPosY = true;
    }
    else if (case_insensitive_match(qNameStr, "width")) {
        bWidth = true;
    }
    else if (case_insensitive_match(qNameStr, "height")) {
        bHeight = true;
    }
    else {
        std::cout << "Unknown qname: " << qNameStr << std::endl;
    }
    xercesc::XMLString::release(&qNameStr);
        return;
}

void XMLHandler::endElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName) {
     //Displayable* displayable;
    if (bPosX) {    // && room then roombPosX
        if (bScroll) {
            //displayable = (Displayable*) roomBeingParsed;
            roomBeingParsed->setPosX(data);
            bPosX = false;
        }
        else if (bPlayer) {

        }
    }
    else if()
}