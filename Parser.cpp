#include"Parser.hpp"

void parser::parser(Room& curRoom, Player& curPlayer, playerString& curSentence)
{
    if (verbInSentence(curSentence, goTo) == true)
	{
		//search for the next room and if found, go to next room.
		findNextRoom(curSentence, curRoom, curPlayer);
	}
	else if(verbInSentence(curSentence, useItem) == true)
	{
		//search for item name in inventory and if it exist, use it.
		searchItemToUse(curSentence, curPlayer, curRoom);
	}
	else if (verbInSentence(curSentence, take) == true)
	{
		//search for item in room to take if exist
		takeItemInRoom(curSentence, curPlayer, curRoom);
	}
	else
	{
		//entered wrong verb
		cout << "Sorry, that command is not recognized." << endl;
	}
}

//return true or false if the verb is found in player string
bool parser::verbInSentence(playerString& curSentence, std::string stringToCompare)
{	
	//iterate through vector of strings
	//https://stackoverflow.com/questions/11170349/how-do-i-iterate-over-a-vector-of-c-strings
	for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
	{
		//converts the chars in string all into lower case to compare
		//https://notfaq.wordpress.com/2007/08/04/cc-convert-string-to-upperlower-case/
		std::transform(i.begin(), i.end(), i.begin(), ::tolower);
		if (i == stringToCompare)
		{
			//word found
			return true;
		}
	}	
	//word not found
	return false;
} 
 
//for verb go
void parser::findNextRoom(playerString& curSentence, Room& curRoom, Player& curPlayer)
{
	bool roomFound = false;

	//interate through vector of strings to find room names
	for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
	{
		//check if any string matches the room names
		//room should return true or false if name is found or not
		if (curRoom.checkRoomNames((*i)) == true)
		{
			cout << "You have entered: " << (*i) << endl;
			
			//need a way to set current room to room name found.

			roomFound = true;
			break;
		}
	}
	if (roomFound == false)
	{
		cout << "Invalid room." << endl;
	}
}

//for verb use
void parser::searchItemToUse(playerString& curSentence, Player& curPlayer, Room& curRoom)
{
	bool itemFound = false;
	
	//interate through vector of strings to find item name
	for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
	{
		//check if item is in player inventory
		if (curPlayer.itemInInventory((*i)) == true)
		{
			//use item in player inventory if it can be used
			if(curPlayer.useItem(*i) == true)
			{
				cout << "You used " << (*i) << endl;
				curPlayer.removeItem((*i));//remove item from player inventory
				itemFound = true;
				break;
			}
			else
			{
				cout << "Item can not be used." << endl;
				itemFound = true;
				break;
			}
		}
	}
	if (itemFound == false)
	{
		cout << "Item not in inventory." << endl;
	}
}

//for verb take
void parser::takeItemInRoom(playerString& curSentence, Player& curPlayer, Room& curRoom)
{
	bool itemTaken = false;
	
	//interate through vector of strings to find item name
	for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
	{
		//check if item is in room
		if (curRoom.checkItemInRoom((*i)) == true)
		{
			//item is in room, pick up item and place in player inventory
			curPlayer.pickUpItem(*i);
			//remove item from the room
			curRoom.removeItem(*i);
			cout << "You picked up " << (*) << endl;	
			itemTaken = true;
			break;
		}
	}
	if (itemTaken == false)
	{
		cout << "Item can not be picked up." << endl;
	}
	
}