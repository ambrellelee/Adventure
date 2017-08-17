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
		bool finishGame;

	public:
		Dungeon();

		Dungeon(std::vector<Room> rooms);

		//related to game play
		void setGameDescription(std::string);
		std::string showGameDescription();
		int showMenu();
		void instructions();
		void playGame();
		bool finishCheck();
		void help();
		void hints();

		//related to Rooms
		void setCurrRoom(std::string);
		void setCurrentRoom(int i);
		void printCurLocation();
		void viewCurRoom();
        bool useExit(std::string exitName);
		bool checkRoomExitStatus(std::string exitStatus);
        bool itemAvailability(std::string availability);
		bool previousRooms(std::string);
		void setRoomVisited();
        bool getRoomVisited();

		//related to Items
		void useItem(std::string);
		void removeRoomItem(std::string);
		bool itemInRoom(std::string iName);
		void getItemInfo(std::string);
		Item returnItem(std::string itemName);
		void droppedInRoom(Item&);
		bool itemInDroppedList(std::string);

		//related to features
		void validInteraction(std::string);
		void fIDesc(std::string);
		void getItemInteractDesc(std::string);
		void fDesc(std::string);
		bool featureInRoom(std::string fName);

		bool verbCheck(std::string, std::string);

		int saveDungeon();
		int loadDungeon(Player *myPlayer);

		~Dungeon();

};

#endif
