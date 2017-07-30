#include "Item.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;


//Constructors
Item::Item()
{
    Name = "Default";
    desc = "Default";
    udesc = "Default";
}

void Item::setItems(std::ifstream& readFile)
{
    std::string blank = "";
    readFile >> blank >> Name; //get the room number
    readFile >> blank;
    std::getline(readFile, desc); //read the description line
    readFile >> blank;
    std::getline(readFile, udesc); //read the use description line
}

void Item::printItemInfo()
{
    cout << "Item Name: "<< Name << endl;
    cout << "Item Description: ";
	for(std::string::size_type i = 0; i != desc.size(); i++)
    {
        cout << desc[i];
    }
    cout << endl;
    cout << "Item Use Description: ";
	for(std::string::size_type i = 0; i != udesc.size(); i++)
    {
        cout << udesc[i];
    }
    cout << endl;
}

std::string Item::getName()
{
    return Name;
}

bool Item::findIName(std::string iName)
{
    std::transform(Name.begin(), Name.end(), Name.begin(), ::tolower);
    if(iName == Name)
    {
        return true;
    }
    else
        return false;

}
void Item::getItemDesc(std::string iName)
{
    std::transform(Name.begin(), Name.end(), Name.begin(), ::tolower);
    if(iName == Name)
    {
        cout << "Item Name: "<< Name << endl;
        cout << "Item Description: ";
        for(std::string::size_type i = 0; i != desc.size(); i++)
        {
            cout << desc[i];
        }
        cout << endl;
    }
}
