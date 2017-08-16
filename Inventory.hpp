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
		std::string containerName;

	public:
		Inventory();
		Inventory(std::string newName);
		void setName(std::string);
		std::string getName();
		std::vector<Item> getStuff();
		void addInventory(Item& thing);
		void removeInventory(std::string);		//removes an item from the player's inventory
		void viewInventory();				//displays list of items in player's inventor
		bool inInventory(std::string thing);	//checks to see if an item is in player's inventory
		void viewItem(std::string);			//displays item's info
		void clearInventory();//TODO: Add To master
		bool drinkable(std::string);
		void fillFlask(int);
		void decreaseFlask(int);
		void getInfo(std::string);
};

#endif
