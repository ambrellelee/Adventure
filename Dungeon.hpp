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
		typedef std::vector<std::string> playerWords;
		std::vector<Room> allRooms; //vector of rooms

	public:
		Dungeon();
		int showMenu();
		void setGameDescription(std::string);
		std::string showGameDescription();
		void initializeRooms();
		void playGame();
		
		~Dungeon();
	
		Dungeon(std::vector<Room> rooms);
		void readRooms(std::ifstream& readFile);
        	void setCurrRoom(std::string);
        	void setCurrentRoom(int i);
       	void printRooms();
        	void printCurLocation();
        	void sendParse(Player& curP, playerWords& curSentence);
		bool findRoom(std::string);
		bool canOpen(std::string);
		bool itemInRoom(std::string);
		void getItemInfo(std::string);
		void useItem(std::string);
};

#endif 
