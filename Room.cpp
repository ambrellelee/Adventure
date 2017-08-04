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

	for(size_t i = 0; i < exitVec.size(); i++)
	{
		if (exitVec[i] == exitName)
        {
            exitPresent = true;
            break;
        }
	}

	return exitPresent;
}

void Room::addItem(Item thing)
{
	dropped.push_back(thing);
}

void Room::removeItem(std::string rItem)
{
	std::vector<Item>::iterator i = std::find_if(inRoom.begin(), inRoom.end(), findItem(rItem));
	inRoom.erase(i);
}

void Room::lookItems(std::string rItem)
{
	for( size_t i = 0; i< inRoom.size(); i++)
	{
		if(inRoom[i].iName == rItem)
		{
			std::cout << inRoom[i].iDesc << std::endl;
		}
	}
}

bool Room::checkItemInRoom(std::string rItem)
{
	bool itemPresent;

    std::vector<string> temp;

	for(size_t i = 0; i < inRoom.size(); i++)
	{
        //split string into vector
        //http://code.runnable.com/VHb0hWMZp-ws1gAr/splitting-a-string-into-a-vector-for-c%2B%2B
        std::stringstream ss(inRoom[i].iName);
        std::string tok;

        while(getline(ss, tok, ' '))
        {
            temp.push_back(tok);
        }
        for(size_t j = 0; j < temp.size(); j++)
        {

            if(temp[j] == rItem)
            {
                temp.clear();
                return true;
            }
            else
            {
                itemPresent = false;
            }

        }
        /*
		if(inRoom[i].iName == rItem)
		{
			return true;                                  //a little change to return true
		}
		*/
        temp.clear();
	}
	return itemPresent;;
}

void Room::printRoomInfo()
{
	cout << "Room Name: " << rName << endl;
        cout << "Room Type: " << rType << endl;
        cout << "Room Descriptions:" << endl;

        for (size_t i = 0; i < rDescription.size(); i++) {
                cout << rDescription[i] << endl;
        }
        cout << "The door you see that you can to go to are " ;
        cout << "Exits:" << endl;

        for (size_t i = 0; i < exitVec.size(); i++) {
                cout << exitVec[i] << endl;
        }

        cout << "Items:" << endl;

        for (size_t i = 0; i < inRoom.size(); i++)
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

	cout << endl;
	cout << endl;
	cout << "What do you want to do ? " << endl;
}
/****************************************************************************
//not needed

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

        cout << "Features:" << endl;

        for (int i = 0; i < roomFeatures.size(); i++)
        {
                cout << "Feature number " << i << endl;
                cout << "Feature name: " << roomFeatures[i].getName() << endl;
                fDescTest = roomFeatures[i].getFeatureDesc();
                interactionDescTest = roomFeatures[i].getInteractionDesc();
                canLeaveTest = roomFeatures[i].getActions();

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
        }

        if (canProceedForward == true)
        {
             cout << "Can leave room now" << endl;
             std::cout << "Thanks you for playing~ Good-Bye~" << std::endl;
             exit(0);
        }

        else
                cout << "Can not leave room now" << endl;

}
****************************************************************************/

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

                Feature myFeat = Feature(featName, fDesc, interactionDesc, canLeave);
                roomFeatures.push_back(myFeat);
                fDesc.clear();
                interactionDesc.clear();
                canLeave.clear();
        }

        inputFile.close();
}


/****************************
 newly added functions
 ***************************/

Item Room::getItemInRoom(std::string itemName)
{
     Item tempItem = Item("", "", "", 0, 0, 0, 0, 0);
     std::vector<string> temp;
     for(size_t i =0; i < inRoom.size(); i++)
     {
        //split string into vector
        //http://code.runnable.com/VHb0hWMZp-ws1gAr/splitting-a-string-into-a-vector-for-c%2B%2B
        std::stringstream ss(inRoom[i].iName);
        std::string tok;

        while(getline(ss, tok, ' '))
        {
            temp.push_back(tok);
        }
        for(size_t j = 0; j < temp.size(); j++)
        {
            if(temp[j] == itemName)
            {
                tempItem = inRoom[i];
                temp.clear();
            }
            temp.clear();
        }
     }
     return tempItem;
}

void Room::printRoomDesc()
{
    for (size_t i = 0; i < rDescription.size(); i++)
    {
        cout << rDescription[i] << endl;
    }
}

bool Room::canUseFeature(std::string itemName)
{
//	bool canUse = false;
	/*
	for(int i = 0; i <roomFeatures.size(); i++)
	{
		if(itemName = roomFeatures[i].fName)
		{
			if(i)
		}
	}
	*/
	return true;
}
