#include "Room.h"

Room::Room()
{
	rName = "default";
	type = "default";
	rDescription = "default";
	itemUsed = 0;
}

Room::Room(string newName, string description, string tType, unsigned int used)
{
	rName = newName;
	rDescription = desc;
	type = tType;
	itemUsed = used;
}

Room::~Room()
{
}

void Room::setName(std::string newName)
{
	rName = newName;
}

string Room::getName()
{
	return rName;
}

void Room::setType(std::string tType)
{
	type = tType;
}

string Room::getType()
{
	return type;
}

void Room::setDescription(std::string desc)
{
	rDescription = desc;
}

string Room::getDescription()
{
	return rDescription;
}
