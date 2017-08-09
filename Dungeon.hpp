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
        void setCurrRoom(std::string);  //needs work
        void setCurrentRoom(int i);
//       	void printRooms();
        void printCurLocation();
//		bool findRoom(std::string);
    //bool canOpen(std::string);
		//probably not needed since we are not using any item in room, most item in room need to be taken and used in player inventory.
		void useItem(std::string);
        void removeRoomItem(std::string);

		//newly added functions
		bool itemInRoom(std::string iName);
        void getItemInfo(std::string);
		Item returnItem(std::string itemName);
		void viewCurRoom();
		bool useExit(std::string exitName);

		bool featureInRoom(std::string fName);

		/////////////////-8/6-additions//////////////////
		bool checkRoomExitStatus(std::string exitStatus);
        bool itemAvailability(std::string availability);
        void validInteraction(std::string);
        void fIDesc(std::string);
        void getItemInteractDesc(std::string);
        void fDesc(std::string);

        ////////////////// 8/8- additions /////////////////
        bool verbCheck(std::string, std::string);


        ~Dungeon();
};

#endif
