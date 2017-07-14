#ifndef ROOM_H
#define ROOM_H

#include<vector>
#include<iostream>
#include<string>
#include "Inventory.hpp"
#include "Feature.hpp"


/*need to:
	-Add number of times features have been accessed
*/

class Room
{
	private:
		Feature *f1;
		Feature *f2;
		std::string rName;
		std::string rDescription;
		std::string rMonster;
		std::string monsterDesc;
		std::string rType;
//		int itemUsed;
		struct Item				//holds information about items in room
          {
               std::string iName;
               std::string iDesc;
			Item(std::string newItemName, std::string newItemDesc)
			{
				iName = newItemName;
				iDesc = newItemDesc;
			}	

		};
		std::vector<Item> items;		//vector holding structs of items
	

	public:
		//Constructors
		Room();
		Room(std::string newName, std::string description, std::string tType, std::string newMonster, std::string mdesc/*, int used*/);
	
		//Destructor
		~Room();

		//Pointers to connecting rooms
		Room * east();
		Room * west();
		Room * north();
		Room * south();

		//Set Values
		void setName(std::string newName);
		void setType(std::string tType);
		void setDescription(std::string rdesc);
		void setMonster(std::string newMonster);
		void setMonsterDesc(std::string mdesc);
		void setItem(std::string, std::string);

		//Get Values
		std::string getName();
		std::string getType();
		std::string getDescription();
		std::string getMonster();
		std::string getMonsterDesc();

		bool itemUsed;

};

#endif 
