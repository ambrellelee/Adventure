#include "Dungeon.hpp"
//add method to set exits to newRoom
//test and then add loop to create all rooms

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

void Dungeon::showMenu()
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
	else
	{
		playGame();
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
