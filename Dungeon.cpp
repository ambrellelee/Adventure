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
    const char* files[]= {"one.txt","two.txt","three.txt","four.txt","five.txt","six.txt","seven.txt","eight.txt"};
    for(size_t i= 0; i < 8; i++)
    {
        Room myRoom = Room(files[i], 0);
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
bool Dungeon::useItem(std::string)
{
    return true;
}


