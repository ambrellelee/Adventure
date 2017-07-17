#include "Room.hpp"

/*Methods to check for interactivity will be in Features class
-Need to add methods to add and remove items from room to inventory/from inventory to room
*/

//Constructors
Room::Room()
{
	rName = "no name";
 	rDescription = "no description";
	rType = "no type";
}

Room::Room(std::string newName, std::string description, std::string tType, std::vector<std::string> exits)
{
	rName = newName;
	rDescription = description;
	rType = tType;
	exitVec = exits;
}

//Destructors
Room::~Room()
{
	items.empty();
}

//setItem
void Room::setItem(std::string newItemName, std::string newItemDesc, std::string newUseDesc, int water, bool addable)
{
	items.push_back(Item(newItemName, newItemDesc, newUseDesc, water, addable));
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

void Room::setExits(std::vector<std::string> newExit)
{
	exitVec = newExit;
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

std::vector<std::string> Room::getExits()
{
	return exitVec;	
}

bool Room::canProceed(std::string exitName)
{
	bool exitPresent = false;

	for(int i = 0; i < exitVec.size(); i++)
	{
		if (exitVec[i] == exitName)
		exitPresent = true;
		break;
	}

	return exitPresent;
}
