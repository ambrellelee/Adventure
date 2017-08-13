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

//Get and Set Methods
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
	}

}

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
/*********************
 revised 8/8
 *******************/
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

/////////////////  8/6 additions ///////////////////

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
                break;
            }
        }
        else if(roomFeatures[i].getinteractionNum() > tempActions.size())
        {
            canProceedForward = true;
            break;
        }
        else
        {
            if(tempActions[roomFeatures[i].getinteractionNum()] == true)
            {
                canProceedForward = true;
                break;
            }
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

////////////////////// 8/8 additions ///////////////

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


////////////////////// 8/12 additions ///////////////
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
