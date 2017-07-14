#include "Room.hpp"

/*Methods to check for interactivity will be in Features class
-Need to add methods to add and remove items to/from inventory
-Need to get and set exits
*/

//Constructors
Room::Room()
{
	rName = "no name";
 	rDescription = "no description";
	rType = "no type";
	rMonster = "no monster";
	monsterDesc = "no monster description";
//	itemUsed = 0;
}

Room::Room(std::string newName, std::string description, std::string tType, std::string newMonster, std::string mdesc/*, int used*/)
{
	rName = newName;
	rDescription = description;
	rType = tType;
	rMonster = newMonster;
	monsterDesc = mdesc;
//	itemUsed = used;
}

//Destructors
Room::~Room()
{
	items.empty();
}

//setItem
void Room::setItem(std::string iName, std::string iDesc)
{
	items.push_back(Item(iName, iDesc));
}

//Get and Set Exits


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
	return rMonster;
}
