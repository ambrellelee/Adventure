#include"Parser.hpp"
#include<iostream>
#include<algorithm>

#define NOISYTEST //turn test comments on or off

using std::transform;
using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::cin;
void Parser::parser(Room& curRoom, Player& curPlayer, playerString& curSentence)
{
    if (verbInSentence(curSentence, goTo) == true)
	{
		//search for the next room and if found, go to next room.
#ifdef NOISYTEST
		std::cout << "'GO' detected...proceeding to 'GO' function." << std::endl;
#endif
		findNextRoom(curSentence, curRoom, curPlayer);
	}
	else if(verbInSentence(curSentence, useItem) == true)
	{
#ifdef NOISYTEST
		std::cout << "'Use' detected...proceeding to 'Use' function." << std::endl;
#endif
		//search for item name in inventory and if it exist, use it.
		searchItemToUse(curSentence, curPlayer, curRoom);
	}
	else if (verbInSentence(curSentence, take) == true)
	{
#ifdef NOISYTEST
		std::cout << "'Take' detected...proceeding to 'Take' function." << std::endl;
#endif
		//search for item in room to take if exist
		takeItemInRoom(curSentence, curPlayer, curRoom);
	}
	else if(verbInSentence(curSentence, openChest) == true)
    {
#ifdef NOISYTEST
		std::cout << "'Open' detected...proceeding to 'Open' function." << std::endl;
#endif
		//Open object in the room
		openObject(curSentence, curPlayer, curRoom);
    }
    else if(verbInSentence(curSentence, talk) == true)
    {
#ifdef NOISYTEST
		std::cout << "'Talk' detected...proceeding to 'Talk' function." << std::endl;
#endif
		//talk to NPC in the room
		talkToNPC(curSentence, curPlayer, curRoom);
    }
    else if(verbInSentence(curSentence, drink) == true)
    {
#ifdef NOISYTEST
		std::cout << "'Drink' detected...proceeding to 'Drink' function." << std::endl;
#endif
		//drink from item
		drinkSomething(curSentence, curPlayer, curRoom);
    }
    else if(verbInSentence(curSentence, drop) == true)
    {
#ifdef NOISYTEST
		std::cout << "'drop' detected...proceeding to 'drop' function." << std::endl;
#endif
		//drop item in inventory
		dropSomething(curSentence, curPlayer, curRoom);
    }
    else if(verbInSentence(curSentence, look) == true)
    {
#ifdef NOISYTEST
		std::cout << "'look' detected...proceeding to 'look' function." << std::endl;
#endif
		//look around room
		lookAtStuff(curSentence, curPlayer, curRoom);
    }
    else if(verbInSentence(curSentence, help) == true)
    {
        //print help stuffs
#ifdef NOISYTEST
		std::cout << "'help' detected....print all help stuff" << std::endl;
#endif
    std::cout << "All verbs you can use: go, use, take, open, talk, drink, drop, \n";
    std::cout << "look, help, inventory, fill, move, cross, unlock, investigate, \n";
    std::cout << "smell, sneak, attack, ring, say, block, touch. " << std::endl;

    }
    else if(verbInSentence(curSentence, inventory) == true)
    {
#ifdef NOISYTEST
		std::cout << "'inventory' detected...displaying items in inventory:" << std::endl;
#endif
		//print inventory
	//	curPlayer.lookBag(); buggy at this point.
    }
    else if(verbInSentence(curSentence, fills) == true)
    {
#ifdef NOISYTEST
		std::cout << "'fill' detected...proceeding to 'fill' function." << std::endl;
#endif
		//fill flask with water
		fillObject(curSentence, curPlayer, curRoom);
    }
    else if(verbInSentence(curSentence, moves) == true)
    {
#ifdef NOISYTEST
		std::cout << "'move' detected...proceeding to 'move' function." << std::endl;
#endif
		//move object
		moveStuff(curSentence, curPlayer, curRoom);
    }
    else if(verbInSentence(curSentence, cross) == true)
    {
#ifdef NOISYTEST
		std::cout << "'cross' detected...proceeding to 'cross' function." << std::endl;
#endif
		//cross somewhere
		crossObject(curSentence, curPlayer, curRoom);
    }
    else if(verbInSentence(curSentence, unlock) == true)
    {
#ifdef NOISYTEST
		std::cout << "'unlock' detected...proceeding to 'unlock' function." << std::endl;
#endif
		//unlock object
		unlockObject(curSentence, curPlayer, curRoom);
    }
    else if(verbInSentence(curSentence, investigate) == true)
    {
#ifdef NOISYTEST
		std::cout << "'investigate' detected...proceeding to 'investigate' function." << std::endl;
#endif
		//investigate room
		investigateStuff(curSentence, curPlayer, curRoom);
    }
    else if(verbInSentence(curSentence, smell) == true)
    {
#ifdef NOISYTEST
		std::cout << "'smell' detected...proceeding to 'smell' function." << std::endl;
#endif
		//smell
		smellStuff(curSentence, curPlayer, curRoom);
    }
    else if(verbInSentence(curSentence, sneak) == true)
    {
#ifdef NOISYTEST
		std::cout << "'sneak' detected...proceeding to 'sneak' function." << std::endl;
#endif
		//sneak around
		sneakSomewhere(curSentence, curPlayer, curRoom);
    }
    else if(verbInSentence(curSentence, attack) == true)
    {
#ifdef NOISYTEST
		std::cout << "'attack' detected...proceeding to 'attack' function." << std::endl;
#endif
		//attack enemy
		attackSomething(curSentence, curPlayer, curRoom);
    }
    else if(verbInSentence(curSentence, ring) == true)
    {
#ifdef NOISYTEST
		std::cout << "'ring' detected...proceeding to 'ring' function." << std::endl;
#endif
		//ring something
		ringObject(curSentence, curPlayer, curRoom);
    }
    else if(verbInSentence(curSentence, say) == true)
    {
#ifdef NOISYTEST
		std::cout << "'say' detected...proceeding to 'say' function." << std::endl;
#endif
		//say something
		saySomething(curSentence, curPlayer, curRoom);
    }
    else if(verbInSentence(curSentence, block) == true)
    {
#ifdef NOISYTEST
		std::cout << "'block' detected...proceeding to 'block' function." << std::endl;
#endif
		//block attack
		blockSomething(curSentence, curPlayer, curRoom);
    }
    else if(verbInSentence(curSentence, touch) == true)
    {
#ifdef NOISYTEST
		std::cout << "'touch' detected...proceeding to 'touch' function." << std::endl;
#endif
		//touch something
		touchSomething(curSentence, curPlayer, curRoom);
    }
	else
	{
		//entered wrong verb
		std::cout << "Sorry, that command is not recognized." << std::endl;
	}
}

//return true or false if the verb is found in player string
bool Parser::verbInSentence(playerString& curSentence, std::string stringToCompare)
{
	//iterate through vector of strings
	//https://stackoverflow.com/questions/11170349/how-do-i-iterate-over-a-vector-of-c-strings
	//https://stackoverflow.com/questions/2395275/how-to-navigate-through-a-vector-using-iterators-c
	for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
	{
		//converts the chars in string all into lower case to compare
		//https://notfaq.wordpress.com/2007/08/04/cc-convert-string-to-upperlower-case/
		std::transform(i->begin(), i->end(), i->begin(), ::tolower);
		if (*i == stringToCompare)
		{
			//word found
			return true;
		}
	}
	//word not found
	return false;
}

//for verb go
void Parser::findNextRoom(playerString& curSentence, Room& curRoom, Player& curPlayer)
{

#ifdef NOISYTEST
    std::cout << "'GO' function > proceeding to look for room name to go to." << std::endl;
#endif // NOISYTEST

	bool roomFound = false;

	//iterate through vector of strings to find room names
	for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
	{
	    /* test for string
	    if(*i == "west")
        {
            std::cout << "west room found" << std::endl;
            roomFound = true;
			break;
        }
        */
		//check if any string matches the room names
		//room should return true or false if name is found or not

		std::transform(i->begin(), i->end(), i->begin(), ::tolower);
		if (curRoom.checkRoomNames((*i)) == true)
		{
			std::cout << "You have entered: " << (*i) << "Room." << std::endl;

			//set current room to room name found here.

			roomFound = true;
			break;
		}

	}
	if (roomFound == false)
	{
		std::cout << "Invalid room." << std::endl;
	}
}

//for verb use
void Parser::searchItemToUse(playerString& curSentence, Player& curPlayer, Room& curRoom)
{
#ifdef NOISYTEST
    std::cout << "'Use' function > proceeding to use object." << std::endl;
#endif // NOISYTEST

	bool itemFound = false;

	//iterate through vector of strings to find item name
	for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
	{
		//check if item is in player inventory
        std::transform(i->begin(), i->end(), i->begin(), ::tolower);
		if (curPlayer.itemInInventory((*i)) == true)
		{
			//use item in player inventory if it can be used
			if(curPlayer.useItem(*i) == true)
			{
				cout << "You used " << (*i) << endl;
//				curPlayer.removeItem((*i));//remove item from player inventory
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
		std::cout << "Item not in inventory." << std::endl;
	}
}

//for verb take
void Parser::takeItemInRoom(playerString& curSentence, Player& curPlayer, Room& curRoom)
{
#ifdef NOISYTEST
    std::cout << "'take' function > proceeding to take object." << std::endl;
#endif // NOISYTEST
	bool itemTaken = false;

	//iterate through vector of strings to find item name
	for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
	{
		//check if item is in room
		std::transform(i->begin(), i->end(), i->begin(), ::tolower);
		if (curRoom.checkItemInRoom((*i)) == true)
		{
			//item is in room, pick up item and place in player inventory
			curPlayer.pickUpItem(*i);
			//remove item from the room
	//		curRoom.removeItem(*i);
			cout << "You picked up " << (*i) << endl;
			itemTaken = true;
			break;
		}

	}
	if (itemTaken == false)
	{
		std::cout << "Item can not be picked up." << std::endl;
	}

}

//for verb open
void Parser::openObject(playerString& curSentence, Player& curPlayer, Room& curRoom)
{

#ifdef NOISYTEST
    std::cout << "'Open' function > proceeding to open object." << std::endl;
#endif // NOISYTEST

	bool objectOpened = false;

	//iterate through vector of strings to find names
	for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
	{
		//check if any string matches the names

		std::transform(i->begin(), i->end(), i->begin(), ::tolower);
		if (curRoom.checkItemInRoom((*i)) == true)
		{
			std::cout << "You have opened " << (*i) << std::endl;

			//set chest to be opened/empty
			objectOpened = true;
			break;
		}

	}
	if (objectOpened == false)
	{
		std::cout << "You cannot open that."  << std::endl;
	}
}

//for verb talk
void Parser::talkToNPC(playerString& curSentence, Player& curPlayer, Room& curRoom)
{
#ifdef NOISYTEST
    std::cout << "'talk' function > proceeding to talk to Sphinx." << std::endl;
#endif // NOISYTEST

	bool talked = false;

	//iterate through vector of strings to find names
	for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
	{
		//check if any string matches the names
		std::transform(i->begin(), i->end(), i->begin(), ::tolower);
		if (curRoom.checkItemInRoom((*i)) == true)
		{
			std::cout << (*i) << ": riddle riddle riddle riddle... " << std::endl;

			talked = true;
			break;
		}

	}
	if (talked == false)
	{
		std::cout << "You cannot talk to that."  << std::endl;
	}
}

//for verb drink
void Parser::drinkSomething(playerString& curSentence, Player& curPlayer, Room& curRoom)
{
#ifdef NOISYTEST
    std::cout << "'drink' function > proceeding to drink something." << std::endl;
#endif // NOISYTEST

	bool drinked = false;

	//iterate through vector of strings to find names
	for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
	{
		//check if item is in inventory
		std::transform(i->begin(), i->end(), i->begin(), ::tolower);
		if (curPlayer.itemInInventory((*i)) == true)
		{
		    //use the item
			curPlayer.useItem(*i);

			drinked = true;
			break;
		}

	}
	if (drinked == false)
	{
		std::cout << "You cannot drink to that."  << std::endl;
	}
}

//for verb drop
void Parser::dropSomething(playerString& curSentence, Player& curPlayer, Room& curRoom)
{
#ifdef NOISYTEST
    std::cout << "'drop' function > proceeding to drop something." << std::endl;
#endif // NOISYTEST

	bool dropped = false;

	//iterate through vector of strings to find names
	for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
	{
		//check if item is in inventory
		std::transform(i->begin(), i->end(), i->begin(), ::tolower);
		if (curPlayer.itemInInventory((*i)) == true)
		{
		    //use the item
			curPlayer.dropItem(*i);
#ifdef NOISYTEST
    std::cout << "dropped " << (*i) << std::endl;
#endif // NOISYTEST
			dropped = true;
			break;
		}
	}
	if (dropped == false)
	{
		std::cout << "You cannot drop that."  << std::endl;
	}
}

//for verb look
void Parser::lookAtStuff(playerString& curSentence, Player& curPlayer, Room& curRoom)
{
#ifdef NOISYTEST
    std::cout << "'look' function > proceeding to look at something." << std::endl;
#endif // NOISYTEST

	bool looking = false;

    if(curSentence.size() < 2)
    {
        std::cout << "repeats long form explanation of the room..." << std::endl;
        looking = true;
    }
    else
    {
        //iterate through vector of strings to find names
        for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
        {
            //check if item is in room
            std::transform(i->begin(), i->end(), i->begin(), ::tolower);
            if (curRoom.checkItemInRoom((*i)) == true)
            {
                //look at item
                curRoom.lookItems(*i);
                looking = true;
                break;
            }
        }
    }

	if (looking == false)
	{
		std::cout << "You cannot look at that."  << std::endl;
	}
}

//for verb fill
void Parser::fillObject(playerString& curSentence, Player& curPlayer, Room& curRoom)
{
#ifdef NOISYTEST
    std::cout << "'fill' function > proceeding to fill object." << std::endl;
#endif // NOISYTEST

	bool filled = false;

    //iterate through vector of strings to find names
    for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
    {
        //check if item is in inventory
        std::transform(i->begin(), i->end(), i->begin(), ::tolower);
        if (curPlayer.itemInInventory((*i)) == true)
        {
            //fill
            curPlayer.useItem(*i);
            filled = true;
            break;
        }
    }

	if (filled == false)
	{
		std::cout << "You cannot fill that."  << std::endl;
	}
}

//for verb move
void Parser::moveStuff(playerString& curSentence, Player& curPlayer, Room& curRoom)
{
#ifdef NOISYTEST
    std::cout << "'move' function > proceeding to move object." << std::endl;
#endif // NOISYTEST

	bool moved = false;

    //iterate through vector of strings to find names
    for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
    {
        //check if item is in room
        std::transform(i->begin(), i->end(), i->begin(), ::tolower);
        if (curRoom.checkItemInRoom((*i)) == true)
        {
            //move item
            std::cout << "you have moved " << (*i) << endl;
            moved = true;
            break;
        }
    }

	if (moved == false)
	{
		std::cout << "You cannot move that."  << std::endl;
	}
}

//for verb cross
void Parser::crossObject(playerString& curSentence, Player& curPlayer, Room& curRoom)
{
#ifdef NOISYTEST
    std::cout << "'cross' function > proceeding to cross object." << std::endl;
#endif // NOISYTEST

	bool crossed = false;

    //iterate through vector of strings to find names
    for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
    {
        //check if object is in room
        std::transform(i->begin(), i->end(), i->begin(), ::tolower);
        if (curRoom.checkItemInRoom((*i)) == true)
        {
            //cross object
            std::cout << "you have crossed the " << (*i) << endl;
            crossed = true;
            break;
        }
    }

	if (crossed == false)
	{
		std::cout << "You cannot cross there."  << std::endl;
	}
}

//for verb unlock
void Parser::unlockObject(playerString& curSentence, Player& curPlayer, Room& curRoom)
{
#ifdef NOISYTEST
    std::cout << "'unlock' function > proceeding to unlock object." << std::endl;
#endif // NOISYTEST

	bool unlocked = false;

    //first check for key in player inventory
    if(curPlayer.itemInInventory("key") == true)
    {
        //iterate through vector of strings to find names
        for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
        {
            //check if object is in room
            std::transform(i->begin(), i->end(), i->begin(), ::tolower);
            if (curRoom.checkItemInRoom((*i)) == true)
            {
                //unlock item
                std::cout << "you have unlocked " << (*i) << endl;
                unlocked = true;
                break;
            }
        }
    }
    else
    {
        std::cout << "Missing key in inventory." << std::endl;
    }
	if (unlocked == false)
	{
		std::cout << "You cannot unlock the object."  << std::endl;
	}
}

//for verb investigate
void Parser::investigateStuff(playerString& curSentence, Player& curPlayer, Room& curRoom)
{
  //same as look smell???
}

//for verb smell
void Parser::smellStuff(playerString& curSentence, Player& curPlayer, Room& curRoom)
{
  //same as investigate and look smell??
}

//for verb sneak
void Parser::sneakSomewhere(playerString& curSentence, Player& curPlayer, Room& curRoom)
{
#ifdef NOISYTEST
    std::cout << "'sneak' function > proceeding to sneak around." << std::endl;
#endif // NOISYTEST

	bool sneaked = false;

    //iterate through vector of strings to find names
    for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
    {
        //check if object is in room
        std::transform(i->begin(), i->end(), i->begin(), ::tolower);
        if (curRoom.checkItemInRoom((*i)) == true)
        {
            //sneak around
            std::cout << "you have sneaked around the " << (*i) << endl;
            sneaked = true;
            break;
        }
    }

	if (sneaked == false)
	{
		std::cout << "You cannot cross there."  << std::endl;
	}
}

//for verb attack
void Parser::attackSomething(playerString& curSentence, Player& curPlayer, Room& curRoom)
{
#ifdef NOISYTEST
    std::cout << "'attack' function > proceeding to attack enemy." << std::endl;
#endif // NOISYTEST

	bool attacked = false;

    //iterate through vector of strings to find names
    for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
    {
        //check if enemy is in room
        std::transform(i->begin(), i->end(), i->begin(), ::tolower);
        if (curRoom.checkItemInRoom((*i)) == true)
        {
            //attacking enemy
            std::cout << "you have attacked the " << (*i) << endl;
            //curPlayer.attacking....?
            attacked = true;
            break;
        }
    }

	if (attacked == false)
	{
		std::cout << "You cannot attack that."  << std::endl;
	}
}

//for verb ring
void Parser::ringObject(playerString& curSentence, Player& curPlayer, Room& curRoom)
{
#ifdef NOISYTEST
    std::cout << "'ring' function > proceeding to ring." << std::endl;
#endif // NOISYTEST

	bool ringed = false;

    //iterate through vector of strings to find names
    for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
    {
        //check if object is in room
        std::transform(i->begin(), i->end(), i->begin(), ::tolower);
        if (curRoom.checkItemInRoom((*i)) == true)
        {
            //ringing object
            std::cout << "you have ringed the " << (*i) << endl;
            //same as use ring...
            ringed = true;
            break;
        }
    }

	if (ringed == false)
	{
		std::cout << "You cannot ring that."  << std::endl;
	}
}

//for verb say
void Parser::saySomething(playerString& curSentence, Player& curPlayer, Room& curRoom)
{
//say something???
}

//for verb block
void Parser::blockSomething(playerString& curSentence, Player& curPlayer, Room& curRoom)
{
#ifdef NOISYTEST
    std::cout << "'block' function > proceeding to block attack." << std::endl;
#endif // NOISYTEST

	bool blocked = false;

    //iterate through vector of strings to find names
    for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
    {
        //check if enemy is in room
        std::transform(i->begin(), i->end(), i->begin(), ::tolower);
        if (curRoom.checkItemInRoom((*i)) == true)
        {
            //blocking attack
            std::cout << "you have blocked the attack from " << (*i) << endl;
            //curPlayer.blocking....?
            blocked = true;
            break;
        }
    }

	if (blocked == false)
	{
		std::cout << "You cannot block that."  << std::endl;
	}
}

//for verb touch
void Parser::touchSomething(playerString& curSentence, Player& curPlayer, Room& curRoom)
{
    searchItemToUse(curSentence, curPlayer, curRoom);
}
