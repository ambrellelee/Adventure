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
            return 3;
        }
    }
}

void Dungeon::playGame()
{
	Room myRoom = Room("one.txt", 0);
	allRooms.push_back(myRoom);
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
	for( int i = 0; i < allRooms.size(); i++)
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

	for(int i = 0; i < allRooms.size(); i++)
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

bool Dungeon::canOpen(std::string itemName)
{

}

void Dungeon::useItem(std::string)
{

}
void Dungeon::printCurLocation()
{
    newRoom->printRoomInfo();
}
/**************************************
 Yu's add
**************************************/
bool Dungeon::findItemInRoom(std::string iName)
{
    bool itemFound;

    for(int i = 0; i < allRooms.size(); i++)
    {
        if(newRoom->checkItemInRoom(iName) == true)
        {
            itemFound = true;
            break;
        }
        else
        {
            itemFound = false;
        }
    }
    return itemFound;
}

bool Dungeon::canProceedCheck(std::string roomName)
{
    bool canProceed = false;
    if(newRoom->canProceed(roomName) == true)
    {
        canProceed = true;
    }
    return canProceed;
}

void Dungeon::lookItem(std::string)
{

}
void Dungeon::look()
{
    newRoom->printRoomInfo();
}
