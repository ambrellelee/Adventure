#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include<vector>
#include<iostream>
#include<string>

class Inventory
{
	private:
		std::vector<std::string> stuff;		//stores items
		std::string containerName;

	public:
		Inventory(std::string newName);
		void setName(std::string);
		std::string getName();
		bool addInventory(std::string);
		std::string removeInventory(std::string);
		std::string viewInventory();
		bool inInventory(std::string);
};

#endif
