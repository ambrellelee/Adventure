#ifndef DUNGEON_HPP
#define DUNGEON_HPP

#include <string.h>
#include <iostream>
#include <vector>
#include <iterator>
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
		std::vector<Room> allRooms; //vector of rooms

        std::vector<std::string> fileNames;
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
		bool useItem(std::string);

		//newly added functions
		bool itemInRoom(std::string iName);
        void getItemInfo(std::string);
		Item returnItem(std::string itemName);
		void viewCurRoom();
		bool useExit(std::string exitName);
};

#endif
