#ifndef ROOM_H
#define ROOM_H

#include<iostream>
#include<string>

/*need to:
	-Add text Parser Object
	-Add number of times features have been accessed
	-Items
*/

class Room
{
	private:
		std::string rName;
		std::string rDescription;
		std::string rMonster;
		std::string rItems[12];	
		std::string monsterDesc;
		std::string rType;
		int itemUsed;

	public:
		//Constructors
		Room();
		Room(std::string newName, std::string description, std::string tType, std::string newMonster, std::string mdesc, int used);
	
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

		//Get Values
		std::string getName();
		std::string getType();
		std::string getDescription();
		std::string getMonster();
		std::string getMonsterDesc();

		bool isMonster();	//Checks for Monster in the room
};

#endif 
