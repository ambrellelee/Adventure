#ifndef ROOM_H
#define ROOM_H
#include <fstream>
#include <vector>
#include <iostream>
#include<string>
#include "Inventory.hpp"
#include "Feature.hpp"
#include "Item.hpp"

class Room
{
	private:
		std::vector<Feature> roomFeatures;
		unsigned int roomNumber;
		std::string description;
		std::vector<std::string> doors;
		Room *north, *south, *east, *west;
        	std::string rType;
		std::vector<Item> inRoom;      //vector holding structs of items in the room
         	std::vector<Item> dropped;	//vector holding structs of items that the player dropped in the room
         	std::vector<std::string> exitVec;		//vector holding exits
		std::vector<std::string> interactions;	// vector holding descriptions for interactions that occur in the room
		bool canProceedForward;

		std::vector<std::string> itemInRoom;  //temp item vector

		 

	public:
		//Constructors
		Room();
		Room(std::string newName, std::vector<std::string> rDescription, std::string tType, std::vector<std::string> exits);
		Room(std::string roomFile, int thisRoomNum);

		//Destructor
		~Room();

		//Set Values
		void setName(std::string newName);
		void setType(std::string tType);
		void setDescription(std::string rdesc);
		void setItem(std::string, std::string, std::string, int, int, bool, int, int);
		void setExits(std::string newExit);

		//Get Values
		std::string rName;
		std::vector<std::string> rDescription;
		std::string getName();
		std::string getType();
		std::vector<std::string> getDescription();
		std::vector<std::string> getExits();

		bool canProceed(std::string exitName);		//Finds whether an exit is valid or not
		void lookItems(std::string rItem);		//look at an item in the room

		bool checkRoomNames(std::string rName);    //Find if parameter match any room names
		bool checkItemInRoom(std::string rItem);  //check if item is in room
		void removeItem(std::string rItem);
		void addItem(Item);
		void setRooms(std::ifstream& readFile);
		void printRoomDesc();
		void printRoomInfo();
		void printAllData();
		void printItemDescription(std::string);
		bool canUseFeature(std::string);
		Item getItemInRoom(std::string);
};

#endif
