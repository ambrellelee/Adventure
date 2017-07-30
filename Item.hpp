#ifndef ITEM_HPP
#define ITEM_HPP

#include<string>
#include<iostream>
#include<algorithm>
/*************************************************************************
struct Item                   //holds information about items in room
{
        std::string iName;
        std::string iDesc;
        std::string useDesc;
        int waterLevel;
        int maxWater;
        bool available;
        int featureSource;
        int whenCanTake;
        Item(std::string newItemName, std::string newItemDesc, std::string newItemUse, int waterU, int waterMax, bool canPickUp, int featureIndex, int interactionNum)
        {
                iName = newItemName;
                iDesc = newItemDesc;
                useDesc = newItemUse;
                waterLevel = waterU;
                maxWater = waterMax;
                available = canPickUp;
                featureSource = featureIndex;
                whenCanTake = interactionNum;
        }
};

struct findItem
{
	const std::string iName;
	findItem(const std::string& iName) : iName(iName) {}
	bool operator() (const Item& i) const
	{
		return i.iName == iName;
	}
};
*************************************************************************/
class Item
{
    private:
        std::string Name;
        std::string desc;
        std::string udesc;
    public:
        //Constructors
        Item();
        void setItems(std::ifstream& readFile);
        void printItemInfo();
        std::string getName();
        bool findIName(std::string iName);
        void getItemDesc(std::string iName);
        std::string getDesc();
        std::string getUDesc();
};
#endif
