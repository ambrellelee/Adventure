#ifndef ROOM_H
#define ROOM_H
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include "Inventory.hpp"
#include "Feature.hpp"
#include "Item.hpp"

class Room
{
	private:
		std::vector<Feature> roomFeatures;
		unsigned int roomNumber;
		std::string description;
//		std::vector<std::string> doors;
		std::vector<std::string> rDescription;
        std::string rType;
		std::vector<Item> inRoom;      //vector holding structs of items in the room
        std::vector<Item> dropped;	//vector holding structs of items that the player dropped in the room

		std::vector<std::string> interactions;	// vector holding descriptions for interactions that occur in the room
		bool canProceedForward;

	public:

		//Constructors
		Room();
		Room(std::string newName, std::vector<std::string> rDescription, std::string tType, std::vector<std::string> exits);
		Room(std::string roomFile, int thisRoomNum);

		//Destructor
		~Room();

		//Get and Set Values
		std::string rName;
		std::vector<std::string> exitVec;		//vector holding exits
		void setName(std::string newName);
		std::string getName();
		void setType(std::string tType);
		std::string getType();
		void setDescription(std::string rdesc);
		std::vector<std::string> getDescription();
		void setItem(std::string, std::string, std::string, int, int, bool, int, int);
		void setExits(std::string newExit);
		std::vector<std::string> getExits();

		//Room Functionality methods
		bool canProceed(std::string exitName);		//Finds whether an exit is valid or not
		void lookItems(std::string rItem);		//look at an item in the room
		bool checkRoomNames(std::string rName);    //Find if parameter match any room names
		bool checkItemInRoom(std::string rItem);  //check if item is in room
		void removeItem(std::string rItem);
		void addItem(Item);
		void printRoomInfo();
//		void printAllData();
		void printItemDescription(std::string);

		//newly added functions
        Item getItemInRoom(std::string itemName);
        void printRoomDesc();
        bool canUseFeature(std::string, std::string);


		 ////////////// 8/6 additions//////////////////////
        bool getExitStatus();
        bool getAvailability(std::string availability);
        void featureInteraction(std::string);
        bool finRoom(std::string);
        void featureIDescription(std::string);
        std::vector<std::string> usedFeatures;
        void getItemIDesc(std::string);
        void featureDescription(std::string);


        ////////////////////// 8/8 additions ///////////////
        std::vector<std::vector<std::string> > verbsList;
        std::vector<std::string> split(const std::string& s);

};

#endif
