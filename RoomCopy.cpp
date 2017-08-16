#include "Room.hpp"
#include "Item.hpp"
#include "Feature.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

/*Methods to check for interactivity will be in Features class
-Need to add methods to add and remove items from room to inventory/from inventory to room
-Add methods for features in room once Features class is finished
-Add method to look at item in a room
*/

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

//Constructors
Room::Room()
{
	rName = "no name";
	rType = "no type";
}

Room::Room(std::string newName, std::vector<std::string> description, std::string tType, std::vector<std::string> exits)
{
	rName = newName;
	rDescription = description;
	rType = tType;
	exitVec = exits;
}

//Destructors
Room::~Room()
{
	inRoom.empty();
}

//setItem
void Room::setItem(std::string newItemName, std::string newItemDesc, std::string newUseDesc, int water, int waterMax, bool addable, int featSource, int interactionGet)
{
	inRoom.push_back(Item(newItemName, newItemDesc, newUseDesc, water, waterMax, addable, featSource, interactionGet));
}

//Set Values Methods
void Room::setName(std::string newName)
{
	rName = newName;
}

void Room::setType(std::string tType)
{
	rType = tType;
}

void Room::setDescription(std::string rdesc)
{
	rDescription.push_back(rdesc); 
}

void Room::setExits(std::string newExit)
{
	exitVec.push_back(newExit);
}

//Get Values Methods
std::string Room::getName()
{
     return rName;
}

std::string Room::getType()
{
     return rType;
}

std::vector<std::string> Room::getDescription()
{
	return rDescription;
}

std::vector<std::string> Room::getExits()
{
	return exitVec;	
}

bool Room::canProceed(std::string exitName)
{
	bool exitPresent = false;

	for(int i = 0; i < exitVec.size(); i++)
	{
		if (exitVec[i] == exitName)
		exitPresent = true;
		break;
	}

	return exitPresent;
}
/*
void Room::addItem(Item thing)
{
	dropped.push_back(thing);
}
*/
/*void Room::removeItem(Item thing)
{
	std::vector<Item>::iterator i = std::find(inRoom.begin(), inRoom.end(), thing);
	inRoom.erase(i);
}*/

//hardcoded comparison for now to show it works.
bool Room::checkRoomNames(std::string rName)
{
    //compare to vector of rooms
    //temp room name list

    if(rName == "court")
    {
#ifdef NOISYTEST
        std::cout << rName << " room found!" << std::endl;
#endif
        return true;
    }
    else
        return false;
}
//hardcoded comparison for now to show it works until we have item working
bool Room::checkItemInRoom(std::string rItem)
{
    if(rItem == "sword")
    {
#ifdef NOISYTEST
        std::cout << rItem << " taken from room." << std::endl;
#endif
        return true;
    }
    else if(rItem == "chest")
    {
#ifdef NOISYTEST
        std::cout << rItem << " is in the room." << std::endl;
#endif
        return true;
    }
    else if(rItem == "sphinx")
    {
#ifdef NOISYTEST
        std::cout << rItem << " is in the room." << std::endl;
#endif
        return true;
    }
    else
        return false;

}
/*
void Room::setRooms(std::ifstream& readFile)
{
    std::string blank = "";
    int exitDoors = 0; //read in number of exit doors in the room
    std::string curDoor = "";
    readFile >> blank >> roomNumber; //get the room number
    readFile >> blank >> rName;
    readFile >> blank;
    std::getline(readFile, description); //read the description line
    readFile >> blank >> exitDoors; //get the number of exit doors.
    int i;
    for(i = 0; i != exitDoors; i++)
    {
        readFile >> blank >> curDoor;
        doors.push_back(curDoor); //get the door name
    }
    int numOfItems = 0; //read in number of exit doors in the room
    std::string curItem = "";
    readFile >> blank >> numOfItems;
    for(i = 0; i !=numOfItems; i++)
    {
        readFile >> blank >> curItem;
        inRoom.push_back(curItem); //TODO: Changed to inRoom from itemInRoom, which has not been declared. What is this meant to be?
    }
}

void Room::printRoomInfo()
{
	cout << "Room number: "<< roomNumber << endl;
	cout << "Room name: " + rName << endl;
	cout << "Room desccription: " <<  endl;
	for(std::string::size_type i = 0; i != description.size(); i++)
    {
        cout << description[i];
        if(description[i] == '.')
        {
            cout << endl;
        }
    }
	cout << endl;
	cout << "The door you see that you can to go to are " ;
	for (Container::size_type i = 0; i != doors.size(); i++)//print doors
	{
		cout << " -->" << doors[i] << " --> ";
	}
	cout << endl;
	cout << "What do you want to do ? " << endl;
}
*/
void Room::printAllData()
{
        cout << "Room Name: " << rName << endl;
        cout << "Room Type: " << rType << endl;
        cout << "Room Descriptions:" << endl;

        for (int i = 0; i < rDescription.size(); i++) {
                cout << rDescription[i] << endl;
        }

        cout << "Exits:" << endl;

        for (int i = 0; i < exitVec.size(); i++) {
                cout << exitVec[i] << endl;
        }

        cout << "Items:" << endl;

        for (int i = 0; i < inRoom.size(); i++)
        {
                cout << "Item number " << (i+1) << endl;

                cout << "Item name: " << inRoom[i].iName << endl;
                cout << "Item description: " << inRoom[i].iDesc << endl;
                cout << "Item use text: " << inRoom[i].useDesc << endl;
                cout << "Water in item: " << inRoom[i].waterLevel << endl;
                cout << "Max. water capacity: " << inRoom[i].maxWater << endl;

                if (inRoom[i].available == true)
                        cout << "Player can pick up item now" << endl;
                else
                        cout << "Player cannot take item now" << endl;

                cout << "Item taken from feature at index " << inRoom[i].featureSource  << endl;
                cout << "Item can be taken at interaction number " << inRoom[i].whenCanTake << endl;
        }


        vector<string> fDescTest;
        vector<string> interactionDescTest;
        vector<bool> canLeaveTest;
        vector<vector<string> > verbTest;

        cout << "Features:" << endl;

        for (int i = 0; i < roomFeatures.size(); i++)
        {
                cout << "Feature number " << i << endl;
                cout << "Feature name: " << roomFeatures[i].getName() << endl;
                fDescTest = roomFeatures[i].getFeatureDesc();
                interactionDescTest = roomFeatures[i].getInteractionDesc();
                canLeaveTest = roomFeatures[i].getActions();
		verbTest = roomFeatures[i].getVerbs();

                cout << "Descriptions read upon 'look' command used (changes after player interacts with and thus changes the feature" << endl;

                for (int j = 0; j < fDescTest.size(); j++)
                {
                        cout << "Description number " << j << ":" << endl;
                        cout << fDescTest[j] << endl;
                }

                cout << "Text printed upon each successive interaction" << endl;
                for (int j = 0; j < interactionDescTest.size(); j++)
                {
                        cout << "Interaction text " << j << ":" << endl;
                        cout << interactionDescTest[j] << endl;
                }


                cout << "Bools returned to show whether player's ability to";
                cout << " leave the room changes upon the interaction" << endl;
                cout << "at the cooresponding index in the interaction array";
                cout << endl;
                for (int j = 0; j < canLeaveTest.size(); j++)
                {
                        if (canLeaveTest[j] == true)
                                cout << "action for " << j << " is true" << endl;
                        else
                                cout << "action for " << j << " is false" << endl;
                }
		
                for (int j = 0; j < verbTest.size(); j++)
                {
                        cout << "Potential verbs for interaction number " << j << endl;

                        for (int k = 0; k < verbTest[j].size(); k++)
                        {
                                cout << verbTest[j][k] << endl;
                        }
                }


        }

        if (canProceedForward == true)
                cout << "Can leave room now" << endl;
        else
                cout << "Can not leave room now" << endl;

}

int Room::saveRoom(std::string outFileName)
{
	fstream outputFile;
	std::string line;
	std::string directory = "saveData";
	std::string fileName;
	std::string fullPath;
	int numEntries;

	fullPath = directory + "/" + outFileName;

	outputFile.open(fullPath.c_str(), ios::out);
	if (!outputFile)
	{
		cout << "ERROR: Could not open file: " << fullPath << endl;
		cout << "Terminating savegame command" << endl;
		return 1;
	}

	outputFile << rDescription.size() << endl;
	outputFile << "@@" << endl;

	for (int i = 0; i < rDescription.size(); i++)
	{
		outputFile << rDescription[i] << "@@" << endl;
	}

	outputFile << rName << endl << "@@" << endl;
	outputFile << rType << endl << "@@" << endl;
	outputFile << exitVec.size() << endl << "@@" << endl;
	
	for (int i = 0; i < exitVec.size(); i++)
	{
		outputFile << exitVec[i] << endl << "@@" << endl;
	}

	if (canProceedForward == true)
		outputFile << "True" << endl << "@@" << endl;
	else
		outputFile << "False" << endl << "@@" << endl;

	outputFile << inRoom.size() << endl << "@@" << endl;
	
	for (int i = 0; i < inRoom.size(); i++)
	{
		outputFile << inRoom[i].iName << endl << "@@" << endl;
		outputFile << inRoom[i].iDesc << endl << "@@" << endl;
		outputFile << inRoom[i].useDesc << endl << "@@" << endl;
		outputFile << inRoom[i].waterLevel << endl << "@@" << endl;
		outputFile << inRoom[i].maxWater << endl << "@@" << endl;

		if (inRoom[i].available == true)
			outputFile << "True" << endl << "@@" << endl;
		else
			outputFile << "False" << endl << "@@" << endl;

		outputFile << inRoom[i].featureSource << endl << "@@" << endl;
		outputFile << inRoom[i].whenCanTake << endl << "@@" << endl;
	
	}

	outputFile << roomFeatures.size() << endl << "@@" << endl;
        vector<string> fDescTest;
        vector<string> interactionDescTest;
        vector<bool> canLeaveTest;
        vector<vector<string> > verbTest;

	
	for (int i = 0; i < roomFeatures.size(); i++)
	{
		outputFile << roomFeatures[i].getName() << endl << "@@" << endl;
                fDescTest = roomFeatures[i].getFeatureDesc();
                interactionDescTest = roomFeatures[i].getInteractionDesc();
                canLeaveTest = roomFeatures[i].getActions();
                verbTest = roomFeatures[i].getVerbs();

		outputFile << fDescTest.size() << endl << "@@" << endl;
		for (int j = 0; j < fDescTest.size(); j++)
		{
			outputFile << fDescTest[j] << "@@" << endl;
		}
		
		for (int j = 0; j < interactionDescTest.size(); j++)
		{
			outputFile << interactionDescTest[j] << "@@";
			outputFile << endl;
		}

		for (int j = 0; j < canLeaveTest.size(); j++)
		{
			if (canLeaveTest[j] == true)
				outputFile << "True" << endl << "@@" << endl;
			else
				outputFile << "False" << endl << "@@" << endl;
		}

		for (int j = 0; j < verbTest.size(); j++)
		{
			for (int k = 0; k < verbTest[j].size(); k++)
			{
				outputFile << verbTest[j][k] << endl;
			}
			
			outputFile << "@@" << endl;
		}

		fDescTest.clear();
		interactionDescTest.clear();
		canLeaveTest.clear();
		for (int j = 0; j < verbTest.size(); j++)
		{
			verbTest[j].clear();
		}
		verbTest.clear();
	}

	outputFile << roomNumber << endl << "@@" << endl;

        outputFile << dropped.size() << endl << "@@" << endl;

        for (int i = 0; i < dropped.size(); i++)
        {
                outputFile << dropped[i].iName << endl << "@@" << endl;
                outputFile << dropped[i].iDesc << endl << "@@" << endl;
                outputFile << dropped[i].useDesc << endl << "@@" << endl;
                outputFile << dropped[i].waterLevel << endl << "@@" << endl;
                outputFile << dropped[i].maxWater << endl << "@@" << endl;

                if (dropped[i].available == true)
                        outputFile << "True" << endl << "@@" << endl;
                else
                        outputFile << "False" << endl << "@@" << endl;

                outputFile << dropped[i].featureSource << endl << "@@" << endl;
                outputFile << dropped[i].whenCanTake << endl << "@@" << endl;

        }


	outputFile.close();
	return 0;
}

Room::Room(std::string roomFile, int thisRoomNum)
{
        fstream inputFile;
        string line;
        string fullMessage = "";
        string directory = "roomData";
        string fileName;
        string fullPath;
        string roomName;
        string roomType;
        int numExits;
        vector<string> exits;
        vector<Item> roomItems;
        //bool canProceed;

        vector<string> roomDescriptions;
        int numRoomDescriptions;

        fullPath = directory + "/" + roomFile;

        inputFile.open(fullPath.c_str(), ios::in);
        if (!inputFile)
        {
                cout << "ERROR: Could not open file: " << fullPath << endl;
                cout << "Ending program" << endl;
                return; //TODO: Change this to exit(1)
        }

        roomNumber = thisRoomNum + 1; //set roomNumber data member

        getline(inputFile, line);

        stringstream numEntries(line);
        numEntries >> numRoomDescriptions;
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

        rDescription = roomDescriptions;

        roomName = line;
        rName = roomName;               //set rName data member
        getline(inputFile, line);
        getline(inputFile, line);

        roomType = line;
        rType = roomType;               //set rType data member

        getline(inputFile, line);
        getline(inputFile, line);

        stringstream numEx(line);
        numEx >> numExits;
        getline(inputFile, line);

        for (int i = 0; i < numExits; i++)
        {
                getline(inputFile, line);
                exits.push_back(line);
                getline(inputFile, line);
        }

        exitVec = exits;

        getline(inputFile, line);

        canProceedForward = setBool(line);

        getline(inputFile, line);
        getline(inputFile, line);
        int numItems;
        stringstream itemNum(line);
        itemNum >> numItems;
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

        inRoom = roomItems;

        string featName;
        vector<string> fDesc;
        vector<string> interactionDesc;
        int numDesc;
        vector<bool> canLeave;
        bool canLeaveNow;
        int numberFeatures;
        vector<vector<string> > verbs;
        vector<string> verbRow;


        getline(inputFile, line);
        stringstream numFeatures(line);
        numFeatures >> numberFeatures;
        getline(inputFile, line);
        getline(inputFile, line);

        //vector<Feature> roomFeatures;

        for (int i = 0; i < numberFeatures; i++)
        {
                fullMessage = "";
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

                for (int j = 0; j < (numDesc-1); j++)
                {
                        while ((line != "@@") && (line != "@@@")) {
                                verbRow.push_back(line);

                                getline(inputFile, line);

			}
                        getline(inputFile, line);
                        verbs.push_back(verbRow);
                        verbRow.clear();
                }

		Feature myFeat = Feature(featName, fDesc, interactionDesc, canLeave, verbs);
                roomFeatures.push_back(myFeat);
                fDesc.clear();
                interactionDesc.clear();
                canLeave.clear();
                for (int j = 0; j < verbs.size(); j++)
                {
                        verbs[j].clear();
                }
                verbs.clear();

        }

        inputFile.close();
}

