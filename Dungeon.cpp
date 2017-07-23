#include "Dungeon.hpp"
#include <cctype>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
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
}
Dungeon::Dungeon(vectorRooms rooms)
{
    allRooms = rooms;
}
Dungeon::~Dungeon()
{
	delete newRoom;
	delete newPlayer;
}
void Dungeon::setGameDescription(std::string newDesc)
{
	gameDesc = newDesc;
}

std::string Dungeon::showGameDescription()
{
	return gameDesc;
}

void Dungeon::menu()
{
	std::cout << "Welcome to the Dungeon! What would you like to do? \n Enter 1 to play and 2 to quit." << std::endl;
	std::cin >>playerInput;
	if(playerInput == 2)
	{
		exit(0);
	}
	else if (playerInput != 1)
	{
		std::cout << "Please enter a valid option." <<std::endl;
	}
}
void Dungeon::initializeRooms()
{

}

void Dungeon::playGame()
{

}
void Dungeon::readRooms(std::ifstream& readFile)
{
    std::string blank;
    unsigned int totalRooms;
    readFile >> blank >> totalRooms; //read in how many rooms in file
    allRooms.reserve(totalRooms);   //reserve spaces in Room vector
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

