#include "Inventory.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <string>
#include "Item.hpp"
#include <algorithm>
#include <list>
#include <sstream>

Inventory::Inventory()
{
	containerName = "testName";
}

Inventory::Inventory(std::string newName)
{
	containerName = newName;
}

//sets container name
void Inventory::setName(std::string newName)
{
	containerName = newName;
}

std::string Inventory::getName()
{
	return containerName;
}

//adds an item to inventory container
void Inventory::addInventory(Item& thing)
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

//removes and item from inventory container
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
		std::cout << "You have removed " << item << " from your inventory." << std::endl;

	}
}

//displays items in inventory container
void Inventory::viewInventory()
{
	std::cout << "You currently have " << stuff.size() << " items in your inventory." << std::endl;
	for(size_t i = 0; i < stuff.size(); i++)
	{
		std::cout << i+1 << ":" << stuff[i].iName <<std::endl;
	}
}

//checks for an item in inventory container
bool Inventory::inInventory(std::string thing)
{
	bool hasItem = false;
    std::vector<std::string> temp;
	for(size_t i = 0; i < stuff.size(); i++)
	{
        //split string into vector
        //http://code.runnable.com/VHb0hWMZp-ws1gAr/splitting-a-string-into-a-vector-for-c%2B%2B
        std::stringstream ss(stuff[i].iName);
        std::string tok;
        while(getline(ss, tok, ' '))
        {
            temp.push_back(tok);
        }
        for(size_t j = 0; j < temp.size(); j++)
        {
            if(temp[j] == thing)
            {
                hasItem = true;
                break;
            }
		}
		temp.clear();
	}
	return hasItem;
}

//displays item description
void Inventory::viewItem(std::string itemName)
{
	for(size_t i = 0; i < stuff.size(); i++)
	{
		if(stuff[i].iName == itemName)
		{
			std::cout << stuff[i].iDesc << std::endl;
		}
	}
}

//checks to see if an item can be drank from
bool Inventory::drinkable(std::string itemName)
{
	bool canDrink = false;

	if(inInventory(itemName))
	{
		for(size_t i = 0; i < stuff.size(); i++)
		{
			if(stuff[i].iName == itemName && stuff[i].waterLevel > 0)
			{
				canDrink = true;
				break;
			}
		}
    }
	return canDrink;
}

//adds water to the flask
void Inventory::fillFlask(int water)
{
      for(size_t i = 0; i < stuff.size(); i++)
      {
           if(stuff[i].iName == "flask")
          {
                stuff[i].waterLevel += water;

                if(stuff[i].waterLevel > stuff[i].maxWater)
               {
                    stuff[i].waterLevel = stuff[i].maxWater;
               }
           }
      }
} 

//subtracts water from flask
void Inventory::decreaseFlask(int water)
{
	for(size_t i = 0; i <stuff.size(); i++)
	{
		if(stuff[i].iName == "flask")
		{
			stuff[i].waterLevel -= water;
			if(stuff[i].waterLevel <= 0)
			{
				std::cout << "Your flask is empty" << std::endl;
				break;
			}
		}
	}
}

void Inventory::clearInventory()
{
        stuff.clear();
}

std::vector<Item> Inventory::getStuff()
{
	return stuff;
}
