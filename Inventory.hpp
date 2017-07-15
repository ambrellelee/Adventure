#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include<vector>
#include<iostream>
#include<string>

class Inventory
{
	private:
		std::vector<std::string> bag;		//stores items

	public:
		Inventory();
		std::vector<std::string> stuff;

		bool add();
		std::string remove();
		std::string view();
		bool full();
		bool empty();		
		bool checkInventory();
};

#endif
