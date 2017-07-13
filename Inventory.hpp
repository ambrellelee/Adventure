#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory
{
	private:
		std::vector<std::string> bag;		//stores items

	public:
		Inventory();
		bool add();
		std::string remove();
		void view();
		bool full();
		bool empty();		
};

#endif
