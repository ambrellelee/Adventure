#include "Room.hpp"
#include "Item.hpp"
#include "Feature.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

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
    hasVisited = false;
}

Room::Room(std::string newName, std::vector<std::string> description, std::string tType, std::vector<std::string> exits)
{
	rName = newName;
	rDescription = description;
	rType = tType;
	exitVec = exits;
	hasVisited = false;
}

//Destructor
Room::~Room()
{
	inRoom.empty();
}

//Get and Set Methods
void Room::setItem(std::string newItemName, std::string newItemDesc, std::string newUseDesc, int water, int waterMax, bool addable, int featSource, int interactionGet)
{
	inRoom.push_back(Item(newItemName, newItemDesc, newUseDesc, water, waterMax, addable, featSource, interactionGet));
}

void Room::setName(std::string newName)
{
	rName = newName;
}

std::string Room::getName()
{
     return rName;
}

void Room::setType(std::string tType)
{
	rType = tType;
}

std::string Room::getType()
{
     return rType;
}

void Room::setDescription(std::string rdesc)
{
	rDescription.push_back(rdesc);
}

std::vector<std::string> Room::getDescription()
{
	return rDescription;
}

void Room::setExits(std::string newExit)
{
	exitVec.push_back(newExit);
}

std::vector<std::string> Room::getExits()
{
	return exitVec;
}

bool Room::getHasVisited()
{
	return hasVisited;
}

void Room::setHasVisited(bool visited)
{
	hasVisited = visited;
}

//checks whether or not an exit exists
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

//adds an Item to the room
void Room::addItem(Item thing)
{
	dropped.push_back(thing);
}

//removes an item from the room
void Room::removeItem(std::string rItem)
{
    std::vector<string> temp;
    string targetItem;
	for( size_t i = 0; i< inRoom.size(); i++)
	{
	    temp = split(inRoom[i].iName);
	    for(size_t j = 0; j < temp.size(); j++)
        {
            if(temp[j] == rItem)
            {
                targetItem = inRoom[i].iName;
                std::vector<Item>::iterator i = std::find_if(inRoom.begin(), inRoom.end(), findItem(targetItem));
                inRoom.erase(i);
                cout << "removing " << targetItem << " from room" <<endl;
                break;
            }
        }
        temp.clear();
	}
	for( size_t i = 0; i< dropped.size(); i++)
	{
	    temp = split(dropped[i].iName);
	    for(size_t j = 0; j < temp.size(); j++)
        {
            if(temp[j] == rItem)
            {
                targetItem = dropped[i].iName;
                std::vector<Item>::iterator i = std::find_if(dropped.begin(), dropped.end(), findItem(targetItem));
                dropped.erase(i);
                cout << "removing " << targetItem << " from room" <<endl;
                break;
            }
        }
        temp.clear();
	}

}

//lists at the items present in the room
void Room::lookItems(std::string rItem)
{
    std::vector<string> temp;
	for( size_t i = 0; i< inRoom.size(); i++)
	{
	    temp = split(inRoom[i].iName);
	    for(size_t j = 0; j < temp.size(); j++)
        {
            if(temp[j] == rItem)
            {
                std::cout << inRoom[i].iDesc << std::endl;
            }
        }
	}
}

//checks to see if a specific item is present in the room
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
        temp.clear();
	}
	return itemPresent;;
}

void Room::printRoomInfo()
{
	cout << "Room Name: " << rName << endl;
    cout << "Room Descriptions:" << endl;
    cout << rDescription[0] << endl;
    /*
    for (size_t i = 0; i < rDescription.size(); i++) {
        cout << rDescription[i] << endl;
    }
    */
    cout << "The door you see that you can to go to are " ;
    cout << "Exits:" << endl;

    cout << "++++++++++++++++++++++++++" << endl;
    for (size_t i = 0; i < exitVec.size(); i++) {
        cout << "-------->  " << exitVec[i] << endl;
    }
    cout << "++++++++++++++++++++++++++" << endl;
/*
    cout << "Items:" << endl;

        ///////////////////////////////////////////////////////////////////////////////
        vector<string> fDescTest;
        vector<string> interactionDescTest;
        vector<bool> canLeaveTest;
        vector<vector<string> > verbTest;

        cout <<"\n******************************************************************************"<<endl;
        cout << "Features:" << endl;

        for (size_t i = 0; i < roomFeatures.size(); i++)
        {
                cout << "Feature number " << i << endl;
                cout << "Feature name: " << roomFeatures[i].getName() << endl;
                fDescTest = roomFeatures[i].getFeatureDesc();
                verbTest = roomFeatures[i].getVerbs();

                cout << fDescTest[0] << endl;
                interactionDescTest = roomFeatures[i].getInteractionDesc();
                cout << "List of verbs that can be used on this feature are: " << endl;
                for(size_t j = 0; j < verbTest.size(); j++)
                {
                    cout << "Potential verbs for interaction number " << j << endl;

                    for (size_t k = 0; k < verbTest[j].size(); k++)
                    {
                        cout << verbTest[j][k] << ", ";
                    }
                    cout << endl;
                }
                cout << endl;
                canLeaveTest = roomFeatures[i].getActions();
                cout << "Exit status: " << canLeaveTest[roomFeatures[i].getinteractionNum()] << endl;
                cout << "------------------------------------------------------------------------" << endl;
        }

	cout << endl;
	cout << endl;
*/
	cout << "What do you want to do ? " << endl;
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
        hasVisited = false;

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
                    while ((line != "@@") && (line != "@@@"))
                    {
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
                for (size_t j = 0; j < verbs.size(); j++)
                {
                    verbs[j].clear();
                }
                verbs.clear();
        }

        inputFile.close();
}

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
 //               cout << inRoom[i].iName << endl;
                tempItem = inRoom[i];
            }
        }
        temp.clear();
     }
     return tempItem;
}

void Room::printRoomDesc()
{
    /*
    for (size_t i = 0; i < rDescription.size(); i++)
    {
        cout << rDescription[i] << endl;
    }
    */
    cout << rDescription[1] << endl;
    cout << "The door you see that you can to go to are " ;
    cout << "Exits:" << endl;

    cout << "++++++++++++++++++++++++++" << endl;
    for (size_t i = 0; i < exitVec.size(); i++)
    {
        cout << "------>  " << exitVec[i] << "      +++ " << endl;
    }
    cout << "++++++++++++++++++++++++++" << endl;
}

//checks to see if the player can interact with the feature
bool Room::canUseFeature(std::string fName, std::string verb)
{
    bool allowed = false;
    std::vector<string> temp;

    for(size_t i = 0; i < roomFeatures.size(); i++)
    {
        std::stringstream ss(roomFeatures[i].getName());
        std::string tok;

        while(getline(ss, tok, ' '))
        {
            temp.push_back(tok);
        }
        for(size_t j = 0; j < temp.size(); j++)
        {
            if(temp[j] == fName)
            {
                verbsList = roomFeatures[i].getVerbs();
                for(size_t j = 0; j < verbsList[roomFeatures[i].getinteractionNum()].size(); j++)
                {
                    if(roomFeatures[i].getinteractionNum() >= verbsList.size())
                    {
                        break;
                    }
                    if(verbsList[roomFeatures[i].getinteractionNum()][j] == verb)
                    {
                        allowed = true;
                    }
                }
                verbsList.clear();
            }
        }
        temp.clear();
    }
    return allowed;
}

//checks to see if the player can go through the exit
bool Room::getExitStatus()
{
    std::vector<bool> tempActions;

    for(size_t i = 0; i < roomFeatures.size(); i++)
    {
        tempActions = roomFeatures[i].getActions();
        if(tempActions.size() == 1)
        {
            if(roomFeatures[i].getinteractionNum() > 0 && tempActions[0] == true)
            {
                canProceedForward = true;
            }
        }
        else if(tempActions.size() != 1 && roomFeatures[i].getinteractionNum() < tempActions.size())
        {
            canProceedForward = tempActions[roomFeatures[i].getinteractionNum()];
        }
        else if(tempActions.size() != 1 && roomFeatures[i].getinteractionNum() >= tempActions.size())
        {
            canProceedForward = tempActions[tempActions.size()-1];
        }
        tempActions.clear();
    }

    return canProceedForward;
}

//see if an item can be taken
bool Room::getAvailability(std::string availability)
{
    bool available = false;
    std::vector<string> temp;
    for(size_t i = 0; i < inRoom.size(); i++)
	{
        std::stringstream ss(inRoom[i].iName);
        std::string tok;

        while(getline(ss, tok, ' '))
        {
            temp.push_back(tok);
        }
        for(size_t j = 0; j < temp.size(); j++)
        {
            if(temp[j] == availability)
            {
                available = inRoom[i].available;
            }
        }
        temp.clear();
        size_t x = inRoom[i].whenCanTake;
        if(x == roomFeatures[inRoom[i].featureSource].getinteractionNum())
        {
            available = true;
        }

	}
	return available;
}

//valid cmd interact with a feature increments interaction number
void Room::featureInteraction(std::string fName)
{
    usedFeatures.push_back(fName);
    std::vector<string> temp;

    for(size_t i = 0; i < roomFeatures.size(); i++)
    {
        std::stringstream ss(roomFeatures[i].getName());
        std::string tok;

        while(getline(ss, tok, ' '))
        {
            temp.push_back(tok);
        }
        for(size_t j = 0; j < temp.size(); j++)
        {
            if(temp[j] == fName)
            {
                if(roomFeatures[i].getinteractionNum()+1 > (roomFeatures[i].getInteractionDesc()).size())
                {
                    break;
                }
                else
                {
                    roomFeatures[i].setInteractionNum();
                }
            }
        }
        temp.clear();
    }
    for(size_t i = 0; i < inRoom.size(); i++)
    {
        std::stringstream ss(inRoom[i].iName);
        std::string tok;

        while(getline(ss, tok, ' '))
        {
            temp.push_back(tok);
        }
        for(size_t j = 0; j < temp.size(); j++)
        {
            if(temp[j] == fName)
            {
                roomFeatures[inRoom[i].featureSource].setInteractionNum();
            }
        }
        temp.clear();
    }
}

//check if feature is in the room
bool Room::finRoom(std::string fName)
{
    bool found = false;
    std::vector<string> temp;
    for(size_t i = 0; i < roomFeatures.size(); i++)
    {
        std::stringstream ss(roomFeatures[i].getName());
        std::string tok;
        while(getline(ss, tok, ' '))
        {
            temp.push_back(tok);
        }
        for(size_t j = 0; j < temp.size(); j++)
        {
            if(temp[j] == fName)
            {
                found = true;
            }
        }
        temp.clear();
    }
    return found;
}

//prints feature interaction description
void Room::featureIDescription(std::string fDesc)
{
    std::vector<string> temp;
    std::vector<std::string> FeatureDesc;
    for(size_t i = 0; i < roomFeatures.size(); i++)
    {
        std::stringstream ss(roomFeatures[i].getName());
        std::string tok;

        while(getline(ss, tok, ' '))
        {
            temp.push_back(tok);
        }
        for(size_t j = 0; j < temp.size(); j++)
        {
            if(temp[j] == fDesc)
            {
                if(roomFeatures[i].getinteractionNum() >= (roomFeatures[i].getInteractionDesc()).size())
                {
                    break;
                }
                else
                {
                    FeatureDesc = roomFeatures[i].getInteractionDesc();
                    cout << FeatureDesc[roomFeatures[i].getinteractionNum()] << endl;
                    break;
                }
            }
        }
        temp.clear();
    }

}

//print item interaction description
 void Room::getItemIDesc(std::string iDesc)
 {
    std::vector<string> temp;
    std::vector<std::string> FeatureDesc;
    for(size_t i = 0; i < inRoom.size(); i++)
    {
        std::stringstream ss(inRoom[i].iName);
        std::string tok;

        while(getline(ss, tok, ' '))
        {
            temp.push_back(tok);
        }
        for(size_t j = 0; j < temp.size(); j++)
        {
            if(temp[j] == iDesc)
            {
                FeatureDesc = roomFeatures[inRoom[i].featureSource].getInteractionDesc();
                cout << FeatureDesc[roomFeatures[inRoom[i].featureSource].getinteractionNum()] << endl;
              //  break;
            }
        }
        temp.clear();
    }
 }

//prints feature description
void Room::featureDescription(std::string fDesc)
{
    std::vector<string> temp;
    std::vector<std::string> FeatureDesc;
    for(size_t i = 0; i < roomFeatures.size(); i++)
    {
        std::stringstream ss(roomFeatures[i].getName());
        std::string tok;

        while(getline(ss, tok, ' '))
        {
            temp.push_back(tok);
        }
        for(size_t j = 0; j < temp.size(); j++)
        {
            if(temp[j] == fDesc)
            {
                FeatureDesc = roomFeatures[i].getFeatureDesc();
                cout << FeatureDesc[roomFeatures[i].getinteractionNum()] << endl;
                //break;
            }
        }
        temp.clear();
    }

}

std::vector<string> Room::split(const string& s)
{
	std::vector<string> temp;

	//split string into vector
	//http://code.runnable.com/VHb0hWMZp-ws1gAr/splitting-a-string-into-a-vector-for-c%2B%2B
	std::stringstream ss(s);
	std::string tok;

	while(getline(ss, tok, ' '))
    {
        temp.push_back(tok);
    }

	return temp;
}

void Room::showHints()
{
    cout << "You have activated hints for this room. " << endl;
    cout << "Features you can interact with for this room are: " << endl;
    for(size_t i = 0; i < roomFeatures.size(); i++)
    {
        cout << "Feature " << i +1 << ": " << roomFeatures[i].getName() << endl;
    }
    cout << "\nItems you can take from this room are: " << endl;
    for(size_t j = 0; j < inRoom.size(); j++)
    {
        cout << "Item " << j+1 << ": " << inRoom[j].iName << endl;
    }
    cout << "*Note: Some items may require interactions with features\nin the room before you can take them.*" << endl;
    cout << "*Always LOOK at capitalized keywords to find more hints on what to do..." << endl;
}

bool Room::getCanProceed()
{
    return canProceedForward;
}

void Room::saveDroppedItems(Item& droppedItem)
{
    dropped.push_back(droppedItem);
    std::cout << droppedItem.iName << " has been dropped in " << rName << "." <<std::endl;
}

bool Room::itemsDroppedInRoom(std::string itemName)
{
    std::vector<string> temp;
    bool inDropped = false;
    for(size_t i = 0; i < dropped.size(); i++)
    {
        //split string into vector
        //http://code.runnable.com/VHb0hWMZp-ws1gAr/splitting-a-string-into-a-vector-for-c%2B%2B
        std::stringstream ss(dropped[i].iName);
        std::string tok;
        while(getline(ss, tok, ' '))
        {
            temp.push_back(tok);
        }
        for(size_t j = 0; j < temp.size(); j++)
        {
            if(temp[j] == itemName)
            {
                inDropped = true;
            }
        }
        temp.clear();
     }
     return inDropped;
}

Item Room::getItemInDrop(std::string itemName)
{
    Item tempItem = Item("", "", "", 0, 0, 0, 0, 0);
    std::vector<string> temp;
    for(size_t i =0; i < dropped.size(); i++)
    {
        //split string into vector
        //http://code.runnable.com/VHb0hWMZp-ws1gAr/splitting-a-string-into-a-vector-for-c%2B%2B
        std::stringstream ss(dropped[i].iName);
        std::string tok;
        while(getline(ss, tok, ' '))
        {
            temp.push_back(tok);
        }
        for(size_t j = 0; j < temp.size(); j++)
        {
            if(temp[j] == itemName)
            {
                tempItem = dropped[i];
            }
        }
        temp.clear();
     }
     return tempItem;
}
int Room::saveRoom(std::string outFileName)
{
        fstream outputFile;
        std::string line;
        std::string directory = "saveData";
        std::string fileName;
        std::string fullPath;

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

        for (size_t i = 0; i < rDescription.size(); i++)
        {
                outputFile << rDescription[i] << "@@" << endl;
        }

        outputFile << rName << endl << "@@" << endl;
        outputFile << rType << endl << "@@" << endl;
        outputFile << exitVec.size() << endl << "@@" << endl;

        for (size_t i = 0; i < exitVec.size(); i++)
        {
                outputFile << exitVec[i] << endl << "@@" << endl;
        }

        if (canProceedForward == true)
                outputFile << "True" << endl << "@@" << endl;
        else
                outputFile << "False" << endl << "@@" << endl;

        outputFile << inRoom.size() << endl << "@@" << endl;

        for (size_t i = 0; i < inRoom.size(); i++)
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


        for (size_t i = 0; i < roomFeatures.size(); i++)
        {
                outputFile << roomFeatures[i].getName() << endl << "@@" << endl;
                fDescTest = roomFeatures[i].getFeatureDesc();
                interactionDescTest = roomFeatures[i].getInteractionDesc();
                canLeaveTest = roomFeatures[i].getActions();
                verbTest = roomFeatures[i].getVerbs();

                outputFile << fDescTest.size() << endl << "@@" << endl;
                for (size_t j = 0; j < fDescTest.size(); j++)
                {
                        outputFile << fDescTest[j] << "@@" << endl;
                }

                for (size_t j = 0; j < interactionDescTest.size(); j++)
                {
                        outputFile << interactionDescTest[j] << "@@";
                        outputFile << endl;
                }

                for (size_t j = 0; j < canLeaveTest.size(); j++)
                {
                        if (canLeaveTest[j] == true)
                                outputFile << "True" << endl << "@@" << endl;
                        else
                                outputFile << "False" << endl << "@@" << endl;
                }

                for (size_t j = 0; j < verbTest.size(); j++)
                {
                        for (size_t k = 0; k < verbTest[j].size(); k++)
                        {
                                outputFile << verbTest[j][k] << endl;
                        }

                        outputFile << "@@" << endl;
                }

                outputFile << roomFeatures[i].getinteractionNum() << endl << "@@";
                outputFile << endl;
                outputFile << roomFeatures[i].getExactLookingNum() << endl << "@@";
                outputFile << endl;

                fDescTest.clear();
                interactionDescTest.clear();
                canLeaveTest.clear();
                for (size_t j = 0; j < verbTest.size(); j++)
                {
                        verbTest[j].clear();
                }
                verbTest.clear();
        }

        outputFile << roomNumber << endl << "@@" << endl;

        outputFile << dropped.size() << endl << "@@" << endl;

        for (size_t i = 0; i < dropped.size(); i++)
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

	if (hasVisited)
		outputFile << "True" << endl;
	else
		outputFile << "False" << endl;

        outputFile.close();
        return 0;
}

int Room::loadRoom(std::string inFileName)
{
        fstream inputFile;
        string line;
        string fullMessage = "";
        string directory = "saveData";
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

        fullPath = directory + "/" + inFileName;

        inputFile.open(fullPath.c_str(), ios::in);
        if (!inputFile)
        {
                cout << "ERROR: Could not open file: " << fullPath << endl;
                cout << "Ending program" << endl;
                return 1; //TODO: Change this to exit(1)
        }

        //roomNumber = thisRoomNum + 1; //set roomNumber data member

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

        rDescription.clear();
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

        exitVec.clear();
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

        inRoom.clear();
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
        size_t intNum;
        size_t lookNum;

        getline(inputFile, line);
        stringstream numFeatures(line);
        numFeatures >> numberFeatures;
        getline(inputFile, line);
        getline(inputFile, line);

        roomFeatures.clear();

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

                stringstream intNumber(line);
                intNumber >> intNum;
                getline(inputFile, line);
                getline(inputFile, line);
                stringstream lookNumber(line);
                lookNumber >> lookNum;
                getline(inputFile, line);
                getline(inputFile, line);


                Feature myFeat = Feature(featName, fDesc, interactionDesc, canLeave, verbs);
                myFeat.setExactInteractionNum(intNum);
                myFeat.setExactLookingNum(lookNum);
                roomFeatures.push_back(myFeat);
                fDesc.clear();
                interactionDesc.clear();
                canLeave.clear();
                for (size_t j = 0; j < verbs.size(); j++)
                {
                        verbs[j].clear();
                }
                verbs.clear();

        }

        stringstream numRoom(line);
        numRoom >> roomNumber;
        getline(inputFile, line);
        getline(inputFile, line);
        int numDropped;
        stringstream numItemsDropped(line);
        numItemsDropped >> numDropped;
        getline(inputFile, line);
        dropped.clear();


        for (int i = 0; i < numDropped; i++)
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
                dropped.push_back(newItem);


        }

	getline(inputFile, line);

	hasVisited = setBool(line);
        inputFile.close();


        return 0;
}
