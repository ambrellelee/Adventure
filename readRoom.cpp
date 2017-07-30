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
#include "Feature.hpp"
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
        int whenCanTake;
        Item(std::string newItemName, std::string newItemDesc, std::string newItemUse, int waterU, int waterMax, bool canPickUp, int featureIndex, int interactionNum)
        {
                iName = newItemName;
                iDesc = newItemDesc;
                iUse = newItemUse;
                waterUnits = waterU;
                maxWater = waterMax;
                canTake = canPickUp;
                featureSource = featureIndex;
                whenCanTake = interactionNum;
        }
};

bool setBool(string input)
{
	if (input == "True")
        {
                return true;
        }
        else
        {
                return false;
        }

}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		cout << "USAGE: " << argv[0] << "[directoryName]" << endl;
		return 1;
	}

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
	bool canProceed;

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
		return 1;
	}

	getline(inputFile, line);

	stringstream numEntries(line);
	numEntries >> numRoomDescriptions;
	cout << numRoomDescriptions << endl;
	getline(inputFile, line);
	getline(inputFile, line);
	
	
	for (int i = 0; i < numRoomDescriptions; i++) 
	{
		while (inputFile && line != "@@") 
		{
			fullMessage = fullMessage + line + "\n";
			getline(inputFile, line);			
		}		
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

	getline(inputFile, line);
	getline(inputFile, line);

	stringstream numEx(line);
        numEx >> numExits;
        cout << numExits << endl;
	getline(inputFile, line);
        //getline(inputFile, line);

        for (int i = 0; i < numExits; i++)
        {
                getline(inputFile, line);
                exits.push_back(line);
		getline(inputFile, line);
        }

        for (int i = 0; i < exits.size(); i++) {
                cout << exits[i] << endl;
        }

	getline(inputFile, line);
	
	canProceed = setBool(line);

	if (canProceed == true)
		cout << "CanProceed is true" << endl;
	else
		cout << "CanProceed is false" << endl;

	getline(inputFile, line);
	getline(inputFile, line);
	int numItems;
	stringstream itemNum(line);
        itemNum >> numItems;
        cout << numItems << endl;
        getline(inputFile, line);
        string iName, iDescription, iUse, waterLevel, maxWater, canGet;
	string inFeature, interactionGet;
	int waterNum, waterLimit, featNum, interactionNum;
	bool canPickUp;


        for (int i = 0; i < numItems; i++)
        {
		getline(inputFile, line);
		iName = line;
		
		getline(inputFile, line);
		getline(inputFile, line);
		iDescription = line;
		
		getline(inputFile, line);
		getline(inputFile, line);
		iUse = line;
		
		getline(inputFile, line);
		getline(inputFile, line);
		stringstream wLevel(line);
		wLevel >> waterNum;

		getline(inputFile, line);
		getline(inputFile, line);
		stringstream limit(line);
		limit >> waterLimit;
	
		getline(inputFile, line);
		getline(inputFile, line);
		canPickUp = setBool(line);
		
		getline(inputFile, line);
                getline(inputFile, line);
                stringstream fNum(line);
                fNum >> featNum;

                getline(inputFile, line);
                getline(inputFile, line);
                stringstream intNum(line);
                intNum >> interactionNum;

		getline(inputFile, line);
		Item newItem = Item(iName, iDescription, iUse, waterNum, waterLimit, canPickUp, featNum, interactionNum);
		roomItems.push_back(newItem);

		
        }

        for (int i = 0; i < roomItems.size(); i++)
	{
                cout << roomItems[i].iName << endl;
		cout << roomItems[i].iDesc << endl;
		cout << roomItems[i].iUse << endl;
                cout << roomItems[i].waterUnits << endl;
		cout << roomItems[i].maxWater << endl;

                if (roomItems[i].canTake == true)
                        cout << "canTake is true" << endl;
                else
                        cout << "canTake is false" << endl;

                cout << roomItems[i].featureSource  << endl;
		cout << roomItems[i].whenCanTake << endl;

        }



	string featName;
	vector<string> fDesc;
	vector<string> interactionDesc;
	int numDesc;
	vector<bool> canLeave;
	bool canLeaveNow;
	int numberFeatures;
	
	getline(inputFile, line);
        stringstream numFeatures(line);
        numFeatures >> numberFeatures;
	cout << numberFeatures << endl;
	getline(inputFile, line);
	getline(inputFile, line);

	vector<Feature> roomFeatures;

	for (int i = 0; i < numberFeatures; i++)
	{
		fullMessage = "";
		//getline(inputFile, line);
		featName = line;

		getline(inputFile, line);
		getline(inputFile, line);
		stringstream descNumber(line);
		descNumber >> numDesc;
		getline(inputFile, line);
		getline(inputFile, line);
		
		for (int j = 0; j < numDesc; j++)
		{
			while(line != "@@")
			{
				fullMessage = fullMessage + line + "\n";
				getline(inputFile, line);
			}
			
			getline(inputFile, line);
			fDesc.push_back(fullMessage);
			fullMessage = "";
		}

		for (int j = 0; j < (numDesc-1); j++)
		{
			while(line != "@@")
                        {
                                fullMessage = fullMessage + line + "\n";
                                getline(inputFile, line);
                        }

                        getline(inputFile, line);
                        interactionDesc.push_back(fullMessage);
                        fullMessage = "";
		}

		for (int j = 0; j < (numDesc-1); j++)
                {
                        canLeaveNow = setBool(line);

                        getline(inputFile, line);
			getline(inputFile, line);
                        canLeave.push_back(canLeaveNow);
                }
		
		//getline(inputFile, line);

		Feature myFeat = Feature(featName, fDesc, interactionDesc, canLeave);
		roomFeatures.push_back(myFeat);
		fDesc.clear();
		interactionDesc.clear();
		canLeave.clear();
	}
	
	//Feature::Feature(std::string featName, std::vector<std::string> fDescs, std::vector<std::string> interactions, std::vector<bool> actions)
	vector<string> fDescTest;
        vector<string> interactionDescTest;
        vector<bool> canLeaveTest;
	
	for (int i = 0; i < roomFeatures.size(); i++)
	{
		cout << roomFeatures[i].getName() << endl;
		fDescTest = roomFeatures[i].getFeatureDesc();
		interactionDescTest = roomFeatures[i].getInteractionDesc();
		canLeaveTest = roomFeatures[i].getActions();

		for (int j = 0; j < fDescTest.size(); j++)
		{
			cout << fDescTest[j] << endl;
		}

		for (int j = 0; j < interactionDescTest.size(); j++)
                {
                        cout << interactionDescTest[j] << endl;
                }

		for (int j = 0; j < canLeaveTest.size(); j++)
                {
                        if (canLeaveTest[j] == true)
				cout << "action for " << j << " is true" << endl;
			else
				cout << "action for " << j << " is false" << endl;
                }


	}


	return 0;
}
