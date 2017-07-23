#ifndef ROOM_H
#define ROOM_H

#include<vector>
#include<iostream>
#include<string>
#include "Inventory.hpp"
#include "Feature.hpp"

class Room
{
	private:
		Feature *f1;
		Feature *f2;
		std::string rName;
		std::vector<std::string> rDescription;
		Room *north, *south, *east, *west;
          std::string rType;
		struct Item                   //holds information about items in room
		{
			std::string iName;
			std::string iDesc;
			std::string useDesc;
			int waterLevel;
			bool available;
			Item(std::string newItemName, std::string newItemDesc, std::string newUseDesc, int water, bool addable)
			{	
				iName = newItemName;
				iDesc = newItemDesc;
				useDesc = newUseDesc;
				waterLevel = water;
				available = addable;
			}
		};
		std::vector<Item> inRoom;      //vector holding structs of items in the room
          std::vector<Item> dropped;	//vector holding structs of items that the player dropped in the room
          std::vector<std::string> exitVec;		//vector holding exits
		std::vector<std::string> interactions;	// vector holding descriptions for interactions that occur in the room

	public:
		//Constructors
		Room();
		Room(std::string newName, std::vector<std::string> rDescription, std::string tType, std::vector<std::string> exits);

	
		//Destructor
		~Room();

		//Set Values
		void setName(std::string newName);
		void setType(std::string tType);
		void setDescription(std::string rdesc);
		void setItem(std::string, std::string, std::string, int, bool);
		void setExits(std::string newExit);

		//Get Values
		std::string getName();
		std::string getType();
		std::vector<std::string> getDescription();
		std::vector<std::string> getExits();

		bool canProceed(std::string exitName);		//Finds whether an exit is valid or not
		void lookItems();		//look at an item in the room	
};

#endif 