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
        std::cout << "Welcome to the Dungeon! What would you like to do? \n Enter 1 to play \n 2 to load saved game \n 3 to quit." << std::endl;
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

    const char* files[]= {"one.txt", "two.txt", "three.txt", "four.txt", "five.txt", "six.txt", "seven.txt", "eight.txt", "nine.txt", "ten.txt", "eleven.txt", "twelve.txt", "thirteen.txt", "fourteen.txt", "fifteen.txt"};
    for(size_t i= 0; i < 15; i++)
    {
        Room myRoom = Room(files[i], i);
        allRooms.push_back(myRoom);
    }

}

void Dungeon::help()
{
	cout << "Allowed commands:\n" "look \n" "take \n" "use \n" "go \n" "inventory \n" "drink \n" "attack \n" "savegame \n" "loadgame \n" << endl;
}

void Dungeon::setCurrentRoom(int i)
{
    newRoom = &(allRooms[i]);
}
// remove
/*
bool Dungeon::canOpen(std::string featureName)
{
    return newRoom->canUseFeature(featureName); //still working on this in the room class
}
*/
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

void Dungeon::removeRoomItem(std::string itemName)
{
	newRoom->removeItem(itemName);
}

/**************************************
 Yu's add
**************************************/
//maybe use item is not needed
/*
void Dungeon::useItem(std::string)
{
    cout << "using item..." <<endl;
}
*/
bool Dungeon::featureInRoom(std::string fName)
{
    return newRoom->finRoom(fName);
}

///////////////////////NEW///////////////////
bool Dungeon::checkRoomExitStatus(std::string exitStatus)
{
    bool eStat = false;
    if(newRoom->exitVec[0] == exitStatus)
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
    for (size_t i = 0; i < allRooms.size(); i++)
	{
        if(allRooms[i].getName() == newRoom->getName())
		{
			//for entry room since it only has one exit
			if(newRoom->exitVec.size() == 1 && newRoom->exitVec[0] == newRoomName)
			{
				newRoom = &allRooms[i+1];
				break;
			}
			//the rest of the room that have more than 1 exitVec
			else if(newRoom->exitVec[0] == newRoomName)
			{
				newRoom = &allRooms[i-1];
				break;
			}
			else if(newRoom->exitVec[1] == newRoomName)
			{
			    if(newRoom->getName() == allRooms[allRooms.size()-1].getName())
                {
                    cout << "Congratulations you have finished the game!" << endl;
                    exit(0);
                }
                else
                {
                    newRoom = &allRooms[i+1];
                    break;
                }
			}
		}
	}
}


////////////////// 8/8- additions /////////////////
bool Dungeon::verbCheck(std::string feature, std::string verbs)
{
    return newRoom->canUseFeature(feature, verbs);
}

////////////////// 8/12- additions /////////////////
void Dungeon::hints()
{
    newRoom->showHints();
}

bool Dungeon::previousRooms(std::string newRoomName)
{
    bool previouslyEnteredRoom = false;
    if(newRoom->getName() != allRooms[0].getName())
    {
        if(newRoom->exitVec[0] == newRoomName)
        {
            previouslyEnteredRoom = true;
        }
    }

    return previouslyEnteredRoom;
}
Dungeon::~Dungeon()
{
	delete newRoom;
}
