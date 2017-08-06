#include "Dungeon.hpp"
#include <cctype>
#include <limits>
//add method to set exits to newRoom
//test and then add loop to create all rooms
using std::transform;
using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::cin;
typedef vector<Room> vectorRooms;
typedef std::vector<std::string> playerWords;

Dungeon::Dungeon()
{
	newRoom = new Room;
}

void Dungeon::setGameDescription(std::string newDesc)
{
	gameDesc = newDesc;
}

std::string Dungeon::showGameDescription()
{
	return gameDesc;
}

int Dungeon::showMenu()
{
   bool go = false;
    while(!go)
    {
        std::cout << "Welcome to the Dungeon! What would you like to do? \n Enter 1 to play \n 2 to demonstrate the file parsing software by making a room and printing its contents \n 3 to quit." << std::endl;
        std::cin >>playerInput;
        if(playerInput == 1)
        {
            go = true;
            return 1;
        }
        else if(playerInput == 2)
        {
            go = true;
            return 2;
        }
        else if (playerInput < 1 || playerInput > 3)
        {
            std::cout << "Please enter a valid option." <<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
        }
        else
        {
            go = true;
        }
    }
    return 3;
}

void Dungeon::playGame()
{

    const char* files[]= {"one.txt","two.txt","four.txt","five.txt","eight.txt"};
    for(size_t i= 0; i < 5; i++)
    {
        Room myRoom = Room(files[i], i);
        allRooms.push_back(myRoom);
    }

}

Dungeon::~Dungeon()
{
	delete newRoom;
}

void Dungeon::setCurrentRoom(int i)
{
    newRoom = &(allRooms[i]);
}
/***********************************
 moved down to bottom, revised.
 **********************************/
 /*
void Dungeon::setCurrRoom(std::string newRoomName)
{
	for(size_t  i = 0; i < allRooms.size(); i++)
	{
		if(allRooms[i].rName == newRoomName)
		{
			newRoom = &allRooms[i];
			break;
		}
	}
}
*/
/************************
 not needed anymore
 ***********************/
 /*
bool Dungeon::findRoom(std::string roomName)
{
	bool roomFound;

	for(size_t i = 0; i < allRooms.size(); i++)
	{
		if(allRooms[i].rName == roomName)
		{
			roomFound = true;
			break;
		}
		else
		{
			roomFound = false;
		}
	}

	return roomFound;
}
*/
bool Dungeon::canOpen(std::string featureName)
{
    return newRoom->canUseFeature(featureName); //still working on this in the room class
}

void Dungeon::printCurLocation()
{
    newRoom->printRoomInfo();
}

//new functions
bool Dungeon::itemInRoom(std::string itemName)
{
	return newRoom->checkItemInRoom(itemName);
}

void Dungeon::getItemInfo(std::string itemName)
{
    newRoom->lookItems(itemName);
}

Item Dungeon::returnItem(std::string itemName)
{
	return newRoom->getItemInRoom(itemName);
}

void Dungeon::viewCurRoom()
{
	 newRoom->printRoomDesc();
}

bool Dungeon::useExit(std::string exitName)
{
	return newRoom->canProceed(exitName);
}
/**************************************
 Yu's add
**************************************/

void Dungeon::useItem(std::string)
{
    cout << "using item..." <<endl;
}

bool Dungeon::featureInRoom(std::string fName)
{
    return newRoom->finRoom(fName);
}

///////////////////////NEW///////////////////
bool Dungeon::checkRoomExitStatus(std::string exitStatus)
{
    bool eStat = false;
    oldRoomDirection = newRoom->getOldRoom();
    if(oldRoomDirection == exitStatus)
    {
        eStat= true;
    }
    else
    {
        eStat = newRoom->getExitStatus();
    }
    return eStat;
}
//check if item can be taken.
bool Dungeon::itemAvailability(std::string availability)
{
    return newRoom->getAvailability(availability);
}
//valid cmd, increment interaction number
void Dungeon::validInteraction(std::string fName)
{
    newRoom->featureInteraction(fName);
}
//prints feature interaction description
void Dungeon::fIDesc(std::string fDescription)
{
    newRoom->featureIDescription(fDescription);
}
//prints item interaction description
void Dungeon::getItemInteractDesc(std::string iIdesc)
{
    newRoom->getItemIDesc(iIdesc);
}
void Dungeon::fDesc(std::string fdesc)
{
    newRoom->featureDescription(fdesc);
}

////////////////////////////////////////////////////////////////////////////
void Dungeon::setCurrRoom(std::string newRoomName)
{
    if(newRoom->rName == allRooms[0].rName)
    {
        if(newRoomName == "east")
        {
            newRoom = &allRooms[1];
        }
    }
    else if(newRoom->rName == allRooms[1].rName)
    {
        if(newRoomName == "north")
        {
            newRoom = &allRooms[2];

        }
        if(newRoomName == "west")
        {
            newRoom = &allRooms[0];
        }
    }
    else if(newRoom->rName == allRooms[2].rName)
    {
        if(newRoomName == "south")
        {
            newRoom = &allRooms[1];
        }
        else if(newRoomName == "north")
        {
            newRoom = &allRooms[3];
        }
    }
    else if(newRoom->rName == allRooms[3].rName)
    {
        if(newRoomName == "south")
        {
            newRoom = &allRooms[2];
        }
        else if(newRoomName == "north")
        {
            newRoom = &allRooms[4];
        }
    }
    else if(newRoom->rName == allRooms[4].rName)
    {
        if(newRoomName == "south")
        {
            newRoom = &allRooms[3];
        }
        else if(newRoomName == "east")
        {
            newRoom = &allRooms[0];
        }
    }
    /*
    if(newRoom->rName == allRooms[5].rName)
    {
        south = &allRooms[4];
        north = &allRooms[6];
        if(newRoomName == "south")
        {
            newRoom = south;
        }
        else if(newRoomName == "north")
        {
            newRoom = north;
        }
    }
    if(newRoom->rName == allRooms[6].rName)
    {
        south = &allRooms[5];
        north = &allRooms[7];
        if(newRoomName == "south")
        {
            newRoom = south;
        }
        else if(newRoomName == "north")
        {
            newRoom = north;
        }
    }
    if(newRoom->rName == allRooms[7].rName)
    {
        south = &allRooms[6];
        east = &allRooms[0];
        if(newRoomName == "south")
        {
            newRoom = south;
        }
        else if(newRoomName == "east")
        {
            newRoom = east;
        }
    }
    */
}
