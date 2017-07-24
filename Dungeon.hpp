#ifndef DUNGEON_HPP
#define DUNGEON_HPP 

#include <string.h>
#include <iostream>
#include "Room.hpp"
#include "Player.hpp"
#include "Parser.hpp"

//start adding functions
//add method to display game description

class Dungeon
{
	private:
		Room *newRoom;
		Player *newPlayer;
		Parser *newParser;
		std::string gameDesc;
		int playerInput;	

	public:
		Dungeon();
		void showMenu();
		void setGameDescription(std::string);
		std::string showGameDescription();
		void initializeRooms();
		void playGame();

		~Dungeon();
	

};

#endif 
