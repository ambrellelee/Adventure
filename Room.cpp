#include "Room.hpp"

/*Methods to check for interactivity will be in Features class
-Need to add methods to add and remove items from room to inventory/from inventory to room
-Add methods for features in room once Features class is finished
-Add method to look at item in a room
*/

#define NOISYTEST  //show tests


//Constructors
Room::Room()
{
	rName = "no name";
	rType = "no type";
}

Room::Room(std::string newName, std::vector<std::string> description, std::string tType, std::vector<std::string> exits)
{
	rName = newName;
	rDescription = description;
	rType = tType;
	exitVec = exits;
}

//Destructors
Room::~Room()
{
	inRoom.empty();
}

//setItem
void Room::setItem(std::string newItemName, std::string newItemDesc, std::string newUseDesc, int water, bool addable)
{
	inRoom.push_back(Item(newItemName, newItemDesc, newUseDesc, water, addable));
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
	rDescription.push_back(rdesc);
}

void Room::setExits(std::string newExit)
{
	exitVec.push_back(newExit);
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

std::vector<std::string> Room::getDescription()
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

void Room::lookItems(std::string rItem)
{
    std::cout << "return item description here..." << std::endl;

}
bool Room::checkRoomNames(std::string rName)
{
    //compare to vector of rooms
    //need a way to get list of room names
    //temp room name list

    if(rName == "treasure")
    {
#ifdef NOISYTEST
        std::cout << rName << " room found!" << std::endl;
#endif
        return true;
    }
    else
        return false;
}

bool Room::checkItemInRoom(std::string rItem)
{
    if(rItem == "sword")
    {
#ifdef NOISYTEST
        std::cout << rItem << " taken from room." << std::endl;
#endif
        return true;
    }
    else if(rItem == "chest")
    {
#ifdef NOISYTEST
        std::cout << rItem << " is in the room." << std::endl;
#endif
        return true;
    }
    else if(rItem == "sphinx")
    {
#ifdef NOISYTEST
        std::cout << rItem << " is in the room." << std::endl;
#endif
        return true;
    }
    else
        return false;

}
void Room::removeItem(std::string rItem)
{
    //remove item from room
    std::cout << rItem << " removed from room." << std::endl;

}
