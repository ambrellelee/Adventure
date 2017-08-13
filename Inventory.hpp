#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include<vector>
#include<iostream>
#include<string>
#include "Item.hpp"
#include<algorithm>
#include<list>
#include <sstream>

class Inventory
{
	private:
		std::vector<Item> stuff;		//stores items
		std::string containerName;	//names inventory

	public:
		Inventory();
		Inventory(std::string newName);
		void setName(std::string);
		std::string getName();
		void addInventory(Item& thing);		//adds an item to player's inventory
		void removeInventory(std::string);		//removes an item from the player's inventory
		void viewInventory();				//displays list of items in player's inventory
		bool inInventory(std::string thing);	//checks to see if an item is in player's inventory
		void viewItem(std::string);			//displays item's info
		bool drinkable(std::string);
		void fillFlask(int);
		void decreaseFlask(int);
};

#endif
