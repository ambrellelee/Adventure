#ifndef DUNGEON_HPP
#define DUNGEON_HPP

#include <string.h>
#include <iostream>
#include <vector>
#include <iterator>
#include "Room.hpp"
#include "Player.hpp"

class Dungeon
{
	private:
		Room *newRoom;
		std::string gameDesc;
		int playerInput;
		std::vector<Room> allRooms; //vector of rooms

        std::vector<std::string> fileNames;

        ////////////NEW//////////////
        std::string oldRoomDirection;

	public:
		Dungeon();
		void setGameDescription(std::string);
          std::string showGameDescription();
		int showMenu();
		void instructions();
		void playGame();
		void help();

		Dungeon(std::vector<Room> rooms);
		void setCurrRoom(std::string);	//needs work
		void setCurrentRoom(int i);		
       	//void printRooms();
		void printCurLocation();
		//bool findRoom(std::string);
		bool canOpen(std::string);
		void useItem(std::string);
		void removeRoomItem(std::string);

		//newly added functions
		bool itemInRoom(std::string iName);
		void getItemInfo(std::string);
		Item returnItem(std::string itemName);
		void viewCurRoom();
		bool useExit(std::string exitName);

		//Yu's test on needed functions...
		bool featureInRoom(std::string fName);

		////////////////NEW//////////////////
		bool checkRoomExitStatus(std::string exitStatus);
		bool itemAvailability(std::string availability);
		void validInteraction(std::string);
		void fIDesc(std::string);
		void getItemInteractDesc(std::string);
		void fDesc(std::string);

		~Dungeon();
};

#endif
