#ifndef DUNGEON_HPP
#define DUNGEON_HPP 

#include <string.h>
#include <iostream>
#include "Room.hpp"
#include "Player.hpp"

//start adding functions

class Dungeon
{
	private:
		Room *newRoom;
		Player *newPlayer;
		Parser *newParser;

	public:
		Dungeon();
		Dungeon(Room *createRoom, Player *createPlayer, Parser *createParser();
		~Dungeon();
	

};

#endif 
