#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include<vector>
#include<iostream>
#include<string>
#include "Item.hpp"
#include<algorithm>
#include<list>

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
		void addInventory(Item& thing);
		void removeInventory(std::string);
		void viewInventory();
		bool inInventory(std::string thing);
		void viewItem(std::string);
};

#endif
