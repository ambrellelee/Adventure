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
	newPlayer = new Player;
	newParser = new Parser;
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
	    std::cin.clear(); // reset failbit
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
	//readRoom();
		
}

Dungeon::~Dungeon()
{
	delete newRoom;
	delete newPlayer;
	delete newParser;
}	
void Dungeon::readRooms(std::ifstream& readFile)
{
    while(!readFile.eof()) //loop until end
    {
        Room load;
        load.setRooms(readFile); //set up the variables of the room.
        allRooms.push_back(load); //push room into dungeon
    }
}

void Dungeon::printRooms()
{
    for(vectorRooms::iterator i = allRooms.begin(); i != allRooms.end(); ++i)
    {
        i->printRoomInfo();
    }
}
void Dungeon::printCurLocation()
{
    newRoom->printRoomInfo();
}
void Dungeon::sendParse(Player& curP, playerWords& curSentence)
{
    Room testRoom;
    Parser* p = new Parser;
    p->parser(testRoom, curP, curSentence);
 //   curD.setCurrentRoom(1);
//    curD.printCurLocation();

}
void Dungeon::setCurrentRoom(int i)
{
    newRoom = &(allRooms[i]);
}
