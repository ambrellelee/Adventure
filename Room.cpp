#include "Room.hpp"

/*Methods to check for interactivity will be in Features class
-Need to add methods to add and remove items from room to inventory/from inventory to room
-Add methods for features in room once Features class is finished
-Add method to look at item in a room
*/

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
void Room::setItem(std::string newItemName, std::string newItemDesc, std::string newUseDesc, int water, bool addable)
{
	inRoom.push_back(Item(newItemName, newItemDesc, newUseDesc, water, addable));
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

void Room::addItem(Item thing)
{
	dropped.push_back(thing);
}

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
    unsigned int i;
    for(i = 0; i != exitDoors; i++)
    {
        readFile >> blank >> curDoor;
        doors.push_back(curDoor); //get the door name
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
