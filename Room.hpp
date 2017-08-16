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
		std::vector<Feature> roomFeatures;		//vector holding Features that are present in the room
		unsigned int roomNumber;
		std::vector<std::string> rDescription;
		std::string rType;			//indicates whether the room is the final room	
		std::vector<Item> inRoom;     //vector holding structs of items in the room
		std::vector<Item> dropped;	//vector holding structs of items that the player dropped in the room
		std::vector<std::string> interactions;	// vector holding descriptions for interactions that occur in the room
		bool canProceedForward;		//indicates whether or not the player can leave through the exit

	public:

		//Constructors
		Room();
		Room(std::string newName, std::vector<std::string> rDescription, std::string tType, std::vector<std::string> exits);
		Room(std::string roomFile, int thisRoomNum);

		//Destructor
		~Room();

		//Public Data Members
		std::string rName;
		std::vector<std::string> exitVec;		//vector holding exits
		std::vector<std::string> usedFeatures;
		std::vector<std::vector<std::string> > verbsList;
          std::vector<std::string> split(const std::string& s);
		std::vector<std::string> getExits();
		
		//Get and Set Values
		void setName(std::string newName);
		std::string getName();
		void setType(std::string tType);
		std::string getType();
		void setDescription(std::string rdesc);
		std::vector<std::string> getDescription();
		void setItem(std::string, std::string, std::string, int, int, bool, int, int);
		Item getItemInRoom(std::string itemName);
		void setExits(std::string newExit);

		//Room Functionality methods
		bool canProceed(std::string exitName);		//Finds whether an exit exists or not
		bool checkRoomNames(std::string rName);      //Find if parameter match any room names
		void printRoomInfo();
		void printRoomDesc();
//		void printAllData();
		void showHints();
          bool getCanProceed();
          bool getExitStatus();	
	
		//Methods Related to Items in Room
		void lookItems(std::string rItem);           //look at an item in the room
		bool checkItemInRoom(std::string rItem);     //check if item is in room
          void removeItem(std::string rItem);
          void addItem(Item);
		void printItemDescription(std::string);
		void getItemIDesc(std::string);
		bool getAvailability(std::string availability);

		//Methods Related to Features In Room
		bool canUseFeature(std::string, std::string);
		void featureInteraction(std::string);
		bool finRoom(std::string);
		void featureIDescription(std::string);
		void featureDescription(std::string);
		
		//Save and Load Room methods 	
		int saveRoom(std::string outFileName);
		int loadRoom(std::string inFileName);

};

#endif
