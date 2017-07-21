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

void Inventory::addInventory(std::string item)
{
	if(inInventory(item))
	{
		std::cout << item << " is already in your inventory." << std::endl;
	}
	else
	{
		stuff.push_back(item);
		std::cout << item << " has been added to your inventory." <<std::endl;
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
		viewInventory();
		
		std::vector<std::string>::iterator i = std::find(stuff.begin(), stuff.end(), item); 		
		stuff.erase(i);
		std::cout << "You have removed << item << from your inventory." << std::endl;

	}	
}

void Inventory::viewInventory()
{
	std::cout << "You currently have " << stuff.size() << "items in your inventory." << std::endl;
	for(int i = 0; i < stuff.size(); i++)
	{
		std::cout << i+1 << ":" << stuff[i] <<std::endl;	
	}
}

bool Inventory::inInventory(std::string item)
{
	bool hasItem; 

	for(int i = 0; i < stuff.size(); i++)
	{
		if(stuff[i] == item)
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
