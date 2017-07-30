#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>
#include <string>
#include "Item.hpp"

class Inventory
{
	private:
	//	std::vector<std::string> stuff;		//stores items
	//	std::string containerName;
        std::string Name;
        std::string desc;
        std::string udesc;

	public:
	    Inventory();
/*************************************************
		Inventory(std::string newName);
		void setName(std::string);
		std::string getName();
		void addInventory(std::string);
		void removeInventory(std::string);
		void viewInventory();
		bool inInventory(std::string);
**************************************************/


		void setInventory(std::string iName, std::string idesc, std::string iudesc);

};

#endif
