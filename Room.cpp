#include "Room.h"

//Constructors
Room::Room()
{
	rName = "default";
	rType = "default";
	rDescription = "default";
	rMonster = "default";
	monsterDesc = "default";
	itemUsed = 0;
}

Room::Room(std::string newName, std::string description, std::string tType, std::string newMonster, std::string mdesc, int used)
{
	rName = newName;
	rDescription = description;
	rType = tType;
	rMonster = newMonster;
	monsterDesc = mdesc;
	itemUsed = used;
}

//Destructors
Room::~Room()
{
}

//Set Values Methods
void Room::setName(std::string newName)
{
	rName = newName;
}

void Room::setType(std::string tType)
{
	rType = tType;
}

void Room::setDescription(std::string rdesc)
{
	rDescription = rdesc;
}

//void Room::setMonster(std::newMonster)
		
void Room::setMonsterDesc(std::string mdesc)
{
	monsterDesc = mdesc;
}

//Get Values Methods
std::string Room::getName()
{
     return rName;
}

std::string Room::getType()
{
     return rType;
}

std::string Room::getDescription()
{
	return rDescription;
}

std::string Room::getMonsterDesc()
{
	return monsterDesc;
}

std::string Room::getMonster()
{
	return rMonster();
}
