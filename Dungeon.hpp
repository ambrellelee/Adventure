#ifndef DUNGEON_HPP
#define DUNGEON_HPP

#include <string.h>
#include <iostream>
#include "Room.hpp"
#include "Player.hpp"

//start adding functions
//add method to display game description

class Dungeon
{
	private:
		Room *newRoom;
		Player *newPlayer;
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
        void setCurrentRoom(Room& currRoom);
        void setCurrentRoom(int i);
        void printRooms();
        void printCurLocation();
 //       void sendParse(Player& curP, playerWords& curSentence);
        bool checkRoomNames(std::string rName);
        bool checkItemInRoom(std::string rItem);
        void lookItems(std::string rItem);		//look at an item in the room
};

#endif
