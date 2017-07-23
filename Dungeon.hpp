#ifndef DUNGEON_HPP
#define DUNGEON_HPP
#include <fstream>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include "Room.hpp"
#include "Player.hpp"
#include "Parser.hpp"

//#include "Parser.hpp"

//start adding functions
//add method to display game description

class Dungeon
{
	private:
        typedef std::vector<std::string> playerWords;
		std::vector<Room> allRooms; //vector of rooms
		Room *newRoom;
		Player *newPlayer;
		std::string gameDesc;
		int playerInput;


	public:
		Dungeon();
		Dungeon(std::vector<Room> rooms);

		~Dungeon();
		void menu();
		void setGameDescription(std::string);
		std::string showGameDescription();
		void initializeRooms();
		void playGame();

        void readRooms(std::ifstream& readFile);
        void setCurrentRoom(Room& currRoom);
        void setCurrentRoom(int i);
        void printRooms();
        void printCurLocation();
        void sendParse(Player& curP, playerWords& curSentence);


};

#endif
