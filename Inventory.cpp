#include "Inventory.hpp"

Inventory::Inventory(std::string newName)
{
	containerName = newName;
}

void Inventory::setName(std::string newName)
{
	containerName = newName;
}
std::string Inventory::getName()
{
	return containerName;
}

void Inventory::addInventory(Item thing)
{
	if(inInventory(thing.iName))
	{
		std::cout << thing.iName << " is already in your inventory." << std::endl;
	}
	else
	{
		stuff.push_back(thing);
		std::cout << thing.iName << " has been added to your inventory." <<std::endl;
	}
}

void Inventory::removeInventory(std::string item)
{
	if(stuff.empty())
	{
		std::cout << "You do not have any items in your inventory." << std::endl;
	}
	else
	{
		std::vector<Item>::iterator i = std::find_if(stuff.begin(), stuff.end(), findItem(item));
		stuff.erase(i);
		std::cout << "You have removed << item << from your inventory." << std::endl;

	}
}

void Inventory::viewInventory()
{
	std::cout << "You currently have " << stuff.size() << "items in your inventory." << std::endl;
	for(int i = 0; i < stuff.size(); i++)
	{
		std::cout << i+1 << ":" << stuff[i].iName <<std::endl;
	}
}

bool Inventory::inInventory(std::string thing)
{
	bool hasItem;

	for(int i = 0; i < stuff.size(); i++)
	{
		if(stuff[i].iName == thing)
		{

			hasItem = true;
		}
		else
		{
			hasItem = false;
		}
	}

	return hasItem;
}

void Inventory::viewItem(std::string itemName)
{
	for(int i = 0; i < stuff.size(); i++)
	{
		if(stuff[i].iName == itemName)
		{
			std::cout << stuff[i].iDesc << std::endl;
		}
	}
}
