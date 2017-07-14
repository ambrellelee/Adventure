#include "Dungeon.hpp"
//add method to set exits to newRoom
//test and then add loop to create all rooms

Dungeon::Dungeon()
{
	newRoom = new Room;
		newRoom->setName;
		newRoom->setType;
		newRoom->setDescription;	
		newRoom->setMonster;
		newRoom->setMonsterDesc;
		newRoom->setItem;

	newPlayer = new Player;
		newPlayer->setName;
		newplayer->setHitPoints;
		newPlayer->setStamina;
		newPlayer->setScore;		

	//newParser = new Parser;
}

void Dungeon::setGameDescription(newDesc)
{
	gameDesc = newDesc;
}

void Dungeon::showGameDescription()
{
	return gameDesc;
}

/*void Dungeon::playGame()	
{
}
*/

Dungeon::~Dungeon()
{
	delete newRoom;
	delete newPlayer;
	delete newParser;
}	
