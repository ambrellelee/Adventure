#ifndef ROOM_H
#define ROOM_H

#include<string>

class Room
{
	Room();
	Room(std::string newName, std::string description, std::string tType, unsigned int used)
	~Room();
	void Room::setName(std::string newName);
	std::string getName();
	void Room::setType(std::string tType);
	string Room::getType();
	void Room::setDescription(std::string desc);
	string Room::getDescription();
	
};

#endif 