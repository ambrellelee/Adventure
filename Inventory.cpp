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

bool Inventory::addInventory(std::string item)
{
	if(inInventory(item))
	{
		std::cout << item << " is already in your inventory." << std::endl;
	}
	else
	{
		stuff.push_back(item);
	}
}

std::string Inventory::removeInventory(std::string item)
{
	if(stuff.empty())
	{
		std::cout << "You do not have any items in your inventory." << std::endl;
	}
	else
	{
		viewInventory();
		for(int i = 0; i < stuff.size(); i++)
		{
			if(stuff[i] == item)
			{	
				stuff.erase(i);
			}
		}
		std::cout << "You have removed << item << from your inventory." << std::endl;

	}	
}

std::string Inventory::viewInventory()
{
	std::cout << "You currently have " << stuff.size() << "items in your inventory." << std::endl;
	for(int i = 0; i < stuff.size(); i++)
	{
		std::cout << i+1 << ":" << stuff[i] <<std::endl;	
	}
}

bool Inventory::inInventory(std::string item)
{
	for(int i = 0; i < stuff.size(); i++)
	{
		if(stuff[i] == item)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
