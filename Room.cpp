
#include<string>
#include<iostream>


Room::Room()
{
	name = "default";
	type = "default";
	description = "default";
	itemUsed = 0;
}

Room::Room(string newName, string description, string tType, unsigned int used)
{
	name = newName;
	description = desc;
	type = tType;
	itemUsed = used;
}

Room::~Room()
{
}

void Room::setName(std::string newName)
{
	name = newName;
}

string Room::getName()
{
	return name;
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
	description = desc;
}

string Room::getDescription()
{
	return description;
}