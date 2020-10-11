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
        Dungeon dungeon = Dungeon(); //insert above values here once Dungeon class is written
    }
    else if (case_insensitive_match(qNameStr, "Rooms")) {} //not sure what to do here
    else if (case_insensitive_match(qNameStr, "Room")) {
        int roomID = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
        Room room = Room("noname"); //room constructor requires a string but xml doesnt give one.
        room.setID(roomID);
        Dungeon.addRoom(room);
    }
    else if (case_insensitive_match(qNameStr, "Monster")) {
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        int roomID = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
        int serialID = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));
        Monster monster = Monster();
        monster.setName(name);
        monster.setID(roomID, serialID);
        Dungeon.addMonster(Monster);
    }
    else if (case_insensitive_match(qNameStr, "Player")) {
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        int roomID = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
        int serialID = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));
        Player player = Player();
        player.setID(roomID, serialID);
    //Not sure about how to do CreatureAction
    else if (case_insensitive_match(qNameStr, "CreatureAction")) {

    }
}

