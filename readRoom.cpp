#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>
#include <sstream>
//#include "Room.hpp"

using std::string;
using std::vector;
using namespace std;

struct Item                   //holds information about items in room
{
        std::string iName;
        std::string iDesc;
        std::string iUse;
        int waterUnits;
        int maxWater;
        bool canTake;
        int featureSource;
        int WhenCanTake;
        Item(std::string newItemName, std::string newItemDesc, std::string newItemUse, int waterU, int waterMax, bool canPickUp, int featureIndex, int interactionNum)
        {
                iName = newItemName;
                iDesc = newItemDesc;
                iUse = newItemUse;
                waterUnits = waterU;
                maxWater = waterMax;
                canTake = canPickUp;
                featureSource = featureIndex;
                WhenCanTake = interactionNum;
        }
};


int main(int argc, char *argv[])
{
	if (argc != 2)
		cout << "USAGE: " << argv[0] << "[directoryName]" << endl;

	fstream inputFile;
	string line;
	string fullMessage = "";
	string directory;
	string fileName;
	string fullPath;
	string roomName;
	string roomType;
	int numExits;
	vector<string> exits;
	vector<Item> roomItems;

	vector<string> roomDescriptions;
	int numRoomDescriptions;

	directory = argv[1];
	//dp = opendir(dir.c_str());
	fullPath = directory + "/" + "one.txt";

	inputFile.open(fullPath.c_str(), ios::in);
	if (!inputFile)
	{
		cout << "ERROR: Could not open file: " << fullPath << endl;
		cout << "Ending program" << endl;
	}

	getline(inputFile, line);

	stringstream numEntries(line);
	numEntries >> numRoomDescriptions;
	cout << numRoomDescriptions << endl;
	getline(inputFile, line);
	getline(inputFile, line);
	//cout << line << endl;
	
	for (int i = 0; i < numRoomDescriptions; i++) 
	{
		while (inputFile && line != "@@") 
		{
			fullMessage = fullMessage + line + "\n";
			getline(inputFile, line);
			
		}
		//	cout << fullMessage << endl;
			getline (inputFile, line);
			roomDescriptions.push_back(fullMessage);
			fullMessage = "";
		
	}

	for (int i = 0; i < roomDescriptions.size(); i++) {
		cout << roomDescriptions[i];
	}

	roomName = line;
	getline(inputFile, line);
	getline(inputFile, line);

	roomType = line;
	cout << roomName << endl << roomType << endl;
	return 0;
}
