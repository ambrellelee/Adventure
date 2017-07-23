#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include<vector>
#include<iostream>
#include<string>
#include <algorithm>

class Inventory
{
	private:
		std::vector<std::string> stuff;		//stores items
		std::string containerName;

	public:
		Inventory(std::string newName);
		void setName(std::string);
		std::string getName();
		void addInventory(std::string);
		void removeInventory(std::string);
		void viewInventory();
		bool inInventory(std::string);
};

#endif
