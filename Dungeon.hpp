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
        void setCurrRoom(std::string);
        void setCurrentRoom(int i);
       	void printRooms();
        void printCurLocation();
		bool findRoom(std::string);
		bool canOpen(std::string);
		void useItem(std::string);

		bool findItemInRoom(std::string iName);
		bool canProceedCheck(std::string roomName);
		void lookItem(std::string);
		void look();
};

#endif
