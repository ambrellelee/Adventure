#ifndef ROOM_H
#define ROOM_H

#include<iostream>
#include<string>

class Room
{
	private:
		std::string rName;
		std::string rDesciption;
		std::string rMonster;
		std::string rItems[12];	

	public:
		//Constructors
		Room();
		Room(std::string newName, std::string description, std::string tType, unsigned int used)
	
		//Destructor
		~Room();

		//Pointers to connecting rooms
		Room * east();
		Room * west();
		Room * north();
		Room * south();

		void Room::setName(std::string newName);
		string Room:getName();
		void Room::setType(std::string tType);
		string Room::getType();
		void Room::setDescription(std::string desc);
		string Room::getDescription();
		//bool Room::getMonster();
		//bool Room::getItem();	
};

#endif 
