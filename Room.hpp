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
		std::string rDescription;
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
		Room *isNorth, *isSouth, *isEast, *isWest;
          std::string rType;
          std::vector<Item> items;      //vector holding structs of items
          std::vector<Item> dropped;
          std::vector<std::string> exitVec;

	public:
		//Constructors
		Room();
		Room(std::string newName, std::string description, std::string tType, std::vector<std::string> exits);

	
		//Destructor
		~Room();

		//Set Values
		void setName(std::string newName);
		void setType(std::string tType);
		void setDescription(std::string rdesc);
		void setItem(std::string, std::string, std::string, int, bool);
		void setExits(std::vector<std::string> newExit);

		//Get Values
		std::string getName();
		std::string getType();
		std::string getDescription();
		std::vector<std::string> getExits();

		bool canProceed(std::string exitName);		//Finds whether an exit is valid or not
		void lookItems();		//look at an item in the room	
};

#endif 
