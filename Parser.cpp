#include"Parser.hpp"
#include<iostream>
#include<algorithm>

//#define NOISYTEST //turn test comments on or off

using std::transform;
using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::cin;
void Parser::parser(Dungeon& curDungeon, Player& curPlayer, playerString& curSentence)
{
    if (verbInSentence(curSentence, "go") || verbInSentence(curSentence, "north") || verbInSentence(curSentence, "south") || verbInSentence(curSentence, "west") || verbInSentence(curSentence, "east") == true)
	{
		//search for the next Room and if found, go to next Room.
#ifdef NOISYTEST
		std::cout << "'GO' detected...proceeding to 'GO' function." << std::endl;
#endif
		findNextDungeon(curSentence, curDungeon, curPlayer);
	}
	else if(verbInSentence(curSentence, "hint") || verbInSentence(curSentence, "hints")== true)
	{
		//Show items in the room to take. show features in room to interact with
		curDungeon.hints();
	}
	else if (verbInSentence(curSentence, "take") || verbInSentence(curSentence, "get") || verbInSentence(curSentence, "pick") == true)
	{
#ifdef NOISYTEST
		std::cout << "'Take' 'get' 'pick up' detected...proceeding to 'Take' function." << std::endl;
#endif
		//search for item in Dungeon to take if exist
		takeItemInDungeon(curSentence, curPlayer, curDungeon);
	}
	else if(verbInSentence(curSentence, "open") || verbInSentence(curSentence, "crack") || verbInSentence(curSentence, "break") == true)
    {
#ifdef NOISYTEST
		std::cout << "'Open' detected...proceeding to 'Open' function." << std::endl;
#endif
		//Open object in the Dungeon
		openObject(curSentence, curPlayer, curDungeon);
    }
    else if(verbInSentence(curSentence, "man") == true)
    {
#ifdef NOISYTEST
		std::cout << "'say' detected...proceeding to 'say' function." << std::endl;
#endif
        if(curDungeon.featureInRoom("sphinx")== true)
        {
            //in replay to sphinx
            curDungeon.fIDesc("sphinx");
            curDungeon.validInteraction("sphinx");
        }
        else
        {
            cout << "tell your answer to sphinx? sphinx not in this room." << endl;
        }

    }
    else if(verbInSentence(curSentence, "talk") || verbInSentence(curSentence, "greet") || verbInSentence(curSentence, "say")  || verbInSentence(curSentence, "investigate") || verbInSentence(curSentence, "study") == true )
    {
#ifdef NOISYTEST
		std::cout << "'Talk' detected...proceeding to 'Talk' function." << std::endl;
#endif
		//talk to NPC in the Dungeon
		talkToNPC(curSentence, curPlayer, curDungeon);
    }
    else if(verbInSentence(curSentence, "ask") || verbInSentence(curSentence, "request") == true )
    {
#ifdef NOISYTEST
		std::cout << "'ask' 'request' detected...proceeding to 'ask' function." << std::endl;
#endif
		//ask NPC in the Dungeon
		askNPC(curSentence, curPlayer, curDungeon);
    }

    else if(verbInSentence(curSentence, "drink") == true)
    {
#ifdef NOISYTEST
		std::cout << "'Drink' detected...proceeding to 'Drink' function." << std::endl;
#endif
		//drink from inventory
		drinkSomething(curSentence, curPlayer, curDungeon);
    }
    else if(verbInSentence(curSentence, "eat") == true)
    {
#ifdef NOISYTEST
		std::cout << "'eat' detected...proceeding to 'eat' function." << std::endl;
#endif
        //eat meal
        eatSomething(curSentence, curPlayer, curDungeon);
    }
    else if(verbInSentence(curSentence, "drop") || verbInSentence(curSentence, "feed") == true)
    {
#ifdef NOISYTEST
		std::cout << "'drop' detected...proceeding to 'drop' function." << std::endl;
#endif
		//drop item in inventory
		dropSomething(curSentence, curPlayer, curDungeon);
    }
    else if(verbInSentence(curSentence, "look") == true)
    {
#ifdef NOISYTEST
		std::cout << "'look' detected...proceeding to 'look' function." << std::endl;
#endif
		//look around Dungeon
		lookAtStuff(curSentence, curPlayer, curDungeon);
    }
    else if(verbInSentence(curSentence, "help") == true)
    {
        //print help stuffs
#ifdef NOISYTEST
		std::cout << "'help' detected....print all help stuff" << std::endl;
#endif
        curDungeon.help();

    }
    else if(verbInSentence(curSentence, "inventory") == true)
    {
#ifdef NOISYTEST
		std::cout << "'inventory' detected...displaying items in inventory:" << std::endl;
#endif
		//print inventory
        curPlayer.lookBag();
    }
    else if(verbInSentence(curSentence, "fill") || verbInSentence(curSentence, "collect")  || verbInSentence(curSentence, "scoop") == true)
    {
#ifdef NOISYTEST
		std::cout << "'fill' detected...proceeding to 'fill' function." << std::endl;
#endif
		//fill flask with water
		fillObject(curSentence, curPlayer, curDungeon);
    }
    else if(verbInSentence(curSentence, "cross") == true)
    {
#ifdef NOISYTEST
		std::cout << "'cross' detected...proceeding to 'cross' function." << std::endl;
#endif
		//cross somewhere
		crossObject(curSentence, curPlayer, curDungeon);
    }
    else if(verbInSentence(curSentence, "unlock") == true)
    {
#ifdef NOISYTEST
		std::cout << "'unlock' detected...proceeding to 'unlock' function." << std::endl;
#endif
		//unlock object
		unlockObject(curSentence, curPlayer, curDungeon);
    }
    else if(verbInSentence(curSentence, "sneak") == true)
    {
#ifdef NOISYTEST
		std::cout << "'sneak' detected...proceeding to 'sneak' function." << std::endl;
#endif
		//sneak around
		sneakSomewhere(curSentence, curPlayer, curDungeon);
    }
    else if(verbInSentence(curSentence, "attack") || verbInSentence(curSentence, "kill") == true)
    {
#ifdef NOISYTEST
		std::cout << "'attack' detected...proceeding to 'attack' function." << std::endl;
#endif
		//attack enemy
		attackSomething(curSentence, curPlayer, curDungeon);
    }
    else if(verbInSentence(curSentence, "block") == true)
    {
#ifdef NOISYTEST
		std::cout << "'block' detected...proceeding to 'block' function." << std::endl;
#endif
		//block attack
		blockSomething(curSentence, curPlayer, curDungeon);
    }
    else if(verbInSentence(curSentence, "touch") == true)
    {
#ifdef NOISYTEST
		std::cout << "'touch' detected...proceeding to 'touch' function." << std::endl;
#endif
		//touch something
		touchSomething(curSentence, curPlayer, curDungeon);
    }
    else if(verbInSentence(curSentence, "status") == true)
    {
#ifdef NOISYTEST
		std::cout << "'status' detected...proceeding to 'status' function." << std::endl;
#endif
		//show status
		curPlayer.printPlayerInfo();
    }
    //pull
    else if(verbInSentence(curSentence, "pull") == true)
    {
#ifdef NOISYTEST
		std::cout << "'pull' detected...proceeding to 'pull' function." << std::endl;
#endif
		//pull lever
		pull(curSentence, curPlayer, curDungeon);
    }
    //illuminate
    else if(verbInSentence(curSentence, "illuminate") || verbInSentence(curSentence, "light")== true)
    {
#ifdef NOISYTEST
		std::cout << "'illuminate' detected...proceeding to 'illuminate' function." << std::endl;
#endif
		//illuminate
		illuminate(curSentence, curPlayer, curDungeon);
    }
    //push
    else if(verbInSentence(curSentence, "push") || verbInSentence(curSentence, "move") == true)
    {
#ifdef NOISYTEST
		std::cout << "'push' detected...proceeding to 'push' function." << std::endl;
#endif
		//push
		push(curSentence, curPlayer, curDungeon);
    }
     //read
    else if(verbInSentence(curSentence, "read") || verbInSentence(curSentence, "inspect") == true)
    {
#ifdef NOISYTEST
		std::cout << "'read' detected...proceeding to 'read' function." << std::endl;
#endif
		//read
		read(curSentence, curPlayer, curDungeon);
    }
    //pay bribe
    else if(verbInSentence(curSentence, "pay") || verbInSentence(curSentence, "bribe") == true)
    {
#ifdef NOISYTEST
		std::cout << "'pay' detected...proceeding to 'pay' function." << std::endl;
#endif
		//pay
		payBribe(curSentence, curPlayer, curDungeon);
    }
    //remove (room 13)
    else if(verbInSentence(curSentence, "remove") == true)
    {
#ifdef NOISYTEST
		std::cout << "'remove' detected...proceeding to 'remove' function." << std::endl;
#endif
		//remove
		removeSomething(curSentence, curPlayer, curDungeon);
    }
    //for save
    else if(verbInSentence(curSentence, "save") ||  verbInSentence(curSentence, "savegame") == true)
    {
#ifdef NOISYTEST
		std::cout << "'save' detected...proceeding to 'save' function." << std::endl;
#endif
		cout << "saving game...."<< endl;
		curPlayer.savePlayer();
		curDungeon.saveDungeon();
		cout << "Current game status saved!" << endl;
    }
    //for load
    else if(verbInSentence(curSentence, "load") || verbInSentence(curSentence, "loadgame") == true)
    {
#ifdef NOISYTEST
		std::cout << "'load' detected...proceeding to 'load' function." << std::endl;
#endif
        string answer;
        cout << "Are you sure you would like to load previously saved game? ";
        getline (cin, answer);
        if(answer == "yes" || answer == "y")
        {
            std::system("clear");
            cout << "loading game...."<< endl;
            curDungeon.loadDungeon(&curPlayer);
            cout << "Finished loading previously saved game.\n" <<endl;
            curDungeon.printCurLocation();
        }
        else
        {
            cout << "What would you like to do?" << endl;
        }
    }

    //for exit
    else if(verbInSentence(curSentence, "exit") == true)
    {
#ifdef NOISYTEST
		std::cout << "'exit' detected...proceeding to 'exit' function." << std::endl;
#endif
		exit(0);
    }
    else if(verbInSentence(curSentence, "jump") == true)
    {
#ifdef NOISYTEST
		std::cout << "'dev Jump' detected...Jumping to room." << std::endl;
#endif
        int i = 0;;
        std::stringstream(curSentence[1]) >> i;
        if( i >= 1 && i <= 15)
        {
            curDungeon.setCurrentRoom(i-1);
            curDungeon.printCurLocation();
        }
		else
        {
            cout << "Room 1~15 allowed"<<endl;
        }
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
void Parser::findNextDungeon(playerString& curSentence, Dungeon& curDungeon, Player& curPlayer)
{
#ifdef NOISYTEST
    std::cout << "'GO' function > proceeding to look for Dungeon name to go to." << std::endl;
#endif // NOISYTEST
    bool DungeonFound = false;
    bool prevRoom = false;
    //iterate through vector of strings to find Dungeon names
    for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
    {
        std::transform(i->begin(), i->end(), i->begin(), ::tolower);
        if (curDungeon.useExit(*i) == true)
        {
            if(curDungeon.checkRoomExitStatus(*i) == true)
            {
                if(curDungeon.previousRooms(*i) == true)
                {
                    prevRoom = true;
                }
                curDungeon.setRoomVisited();
                curDungeon.setCurrRoom(*i);
                if(curDungeon.finishCheck() == true)
                {
                    std::system("clear");
                    cout << "Congratulations you have finished the game!" << endl;
                    DungeonFound = true;
                }
                else
                {
                    std::system("clear");
                    std::cout << "****************************************************************" << std::endl;
                    std::cout << "****            You have entered: " << (*i) << " Dungeon.          ****" << std::endl;
                    std::cout << "****************************************************************" << std::endl;
                    if(prevRoom == true)
                    {
                        curDungeon.viewCurRoom();
                    }
                    else if(curDungeon.getRoomVisited() == true)
                    {
                        curDungeon.viewCurRoom();
                    }
                    else
                    {
                        curDungeon.printCurLocation();
                    }
                    DungeonFound = true;
                    curPlayer.subtractStamina(1);
                    break;
                }
            }
            else
            {
                cout << "You cannot proceed to " << *i << " Dungeon yet.\nsome feature not activated." <<endl;
                DungeonFound = true;
            }
        }
    }
    if (DungeonFound == false)
    {
        std::cout << "Invalid Dungeon." << std::endl;
    }
}

//for verb take
void Parser::takeItemInDungeon(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon)
{
#ifdef NOISYTEST
    std::cout << "'take' function > proceeding to take object." << std::endl;
#endif // NOISYTEST
	bool itemTaken = false;

	//iterate through vector of strings to find item name
	for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
	{
		//check if item is in Dungeon
		std::transform(i->begin(), i->end(), i->begin(), ::tolower);
		if (curDungeon.itemInRoom(*i) == true)
		{
		    if(curDungeon.itemAvailability(*i) == true)
            {
                if(curPlayer.hasItem(*i) == false)
                {
                    //display item interaction desc
                    curDungeon.getItemInteractDesc(*i);
                    //item is in Dungeon, pick up item and place in player inventory
                    Item temp = curDungeon.returnItem(*i);

                    curPlayer.addToBag(temp);
                    if(temp.iName == "armor")
                    {
                        curPlayer.setHitPoints(5);
                    }
                    curDungeon.validInteraction(*i); //sets feature interactionNum to +1
                    //remove item from the Dungeon
                    curDungeon.removeRoomItem(*i);
                    itemTaken = true;
                    break;
                }
                else
                {
                    cout << "You already have " << *i << " in the inventory. " << endl;
                    itemTaken = true;
                    break;
                }
            }
            else if(curPlayer.hasItem(*i) == true)
            {
                cout << "You already have " << *i << " in the inventory. " << endl;
                itemTaken = true;
            }
            else
            {
                cout << *i << " cannot be taken from the room.\nOr feature need to be activated first." << endl;
                itemTaken = true;
            }
		}
		else if(curDungeon.itemInDroppedList(*i)== true)
        {
            Item temp = curDungeon.returnItem(*i);
            curPlayer.addToBag(temp);
            curDungeon.removeRoomItem(*i);
            itemTaken = true;
            break;
        }
	}
	if (itemTaken == false)
	{
		std::cout << "Item cannot be picked up." << std::endl;
	}

}

//for verb open
void Parser::openObject(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon)
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
		if (curDungeon.featureInRoom(*i) == true)
		{
		    if(curDungeon.verbCheck(*i, "open") || curDungeon.verbCheck(*i, "crack") || curDungeon.verbCheck(*i, "break") == true)
            {
                if(*i == "vault")
                {
                    if(curPlayer.hasItem("key") == true)
                    {
                        curDungeon.fIDesc(*i);   //prints the feature's 1st interaction description
                        curDungeon.validInteraction(*i); //sets feature interactionNum to +1
                        objectOpened = true;
                        curPlayer.removeFromBag("key");
                        break;
                    }
                    else
                    {
                        cout << "You are missing key" << endl;
                        objectOpened = true;
                        break;
                    }
                }
                else
                {
                    curDungeon.fIDesc(*i);   //prints the feature's 1st interaction description
                    curDungeon.validInteraction(*i); //sets feature interactionNum to +1
                    objectOpened = true;
                    break;
                }

            }
            else
            {
                std::cout << "You cannot open " << (*i) << std::endl;
                objectOpened = true;
            }
		}

	}
	if (objectOpened == false)
	{
		std::cout << "You cannot open that."  << std::endl;
	}
}

//for verb talk
void Parser::talkToNPC(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon)
{
#ifdef NOISYTEST
    std::cout << "'talk' function > proceeding to talk" << std::endl;
#endif // NOISYTEST

	bool talked = false;

	//iterate through vector of strings to find names
	for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
	{
		//check if any string matches the names
		std::transform(i->begin(), i->end(), i->begin(), ::tolower);
		if (curDungeon.featureInRoom(*i) == true)
		{
		    if(curDungeon.verbCheck(*i,"talk") || curDungeon.verbCheck(*i,"study") ==  true)
            {
                curDungeon.fIDesc(*i);
                curDungeon.validInteraction(*i); //sets feature interactionNum to +1
                talked = true;
                break;
            }
        }
	}
	if (talked == false)
	{
		std::cout << "You cannot talk to that."  << std::endl;
	}
}

//for verbs ask, request
void Parser::askNPC(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon)
{
#ifdef NOISYTEST
    std::cout << "'ask' function > proceeding to ask" << std::endl;
#endif // NOISYTEST

	bool asked = false;

	//iterate through vector of strings to find names
	for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
	{
		//check if any string matches the names
		std::transform(i->begin(), i->end(), i->begin(), ::tolower);
		if (curDungeon.featureInRoom(*i) == true)
		{
		    if(curDungeon.verbCheck(*i,"ask") ==  true)
            {
 //               std::cout << (*i) << ": print item description or interaction here... \n" << std::endl;
                curDungeon.fIDesc(*i);
                curDungeon.validInteraction(*i); //sets feature interactionNum to +1
                asked = true;
                break;
            }
        }
	}
	if (asked == false)
	{
		std::cout << "You cannot ask or request that."  << std::endl;
	}
}
//for verb drink
void Parser::drinkSomething(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon)
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
		if (curPlayer.hasItem(*i) == true)
		{
            if(*i == "potion")
            {
                std::cout << "You drank " << *i << std::endl;
                curPlayer.setHitPoints(10);
                std::cout << "Your HP have been restored." << std::endl;
                curPlayer.removeFromBag(*i);
                drinked = true;
                break;
            }
            else if(curPlayer.canDrink(*i) == true)
            {
                //use the item
                std::cout << "You drank from " << *i << std::endl;
                curPlayer.addStamina(1);
                curPlayer.subtractWater(1);
                drinked = true;
                break;
            }
		}
		else if(*i == "water")
        {
            if(curPlayer.hasItem("flask") == true)
            {
                if(curPlayer.canDrink("flask") == true)
                {
                    //use the item
                    std::cout << "You drank water from your flask " << std::endl;
                    curPlayer.addStamina(1);
                    curPlayer.subtractWater(1);
                    drinked = true;
                    break;
                }
                else
                {
                    std::cout << "No more water in flask, needs refill..." << endl;
                    drinked = true;
                    break;
                }
            }
        }
	}
	if (drinked == false)
	{
		std::cout << "You cannot drink that."  << std::endl;
	}
}
//for verb eat
void Parser::eatSomething(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon)
{
#ifdef NOISYTEST
    std::cout << "'eat' function > proceeding to eat something." << std::endl;
#endif // NOISYTEST

	bool ate = false;

	//iterate through vector of strings to find names
	for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
	{
		//check if item is in inventory
		std::transform(i->begin(), i->end(), i->begin(), ::tolower);
		if (curPlayer.hasItem(*i) == true)
		{
            //use the item
            std::cout << "You have eaten " << *i << std::endl;
            curPlayer.addStamina(2);
            curPlayer.removeFromBag(*i);
            ate = true;
            break;
		}
		else if(curDungeon.itemInRoom(*i) == true && curDungeon.itemAvailability(*i) == true)
        {
            std::cout << "You have ate " << *i << std::endl;
            curPlayer.addStamina(2);
            curDungeon.removeRoomItem(*i);
            curDungeon.validInteraction("table");
            ate = true;
            break;
        }
	}
	if (ate == false)
	{
		std::cout << "You are missing meal in bag or You cannot eat that."  << std::endl;
	}
}
//for verb drop
void Parser::dropSomething(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon)
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
		if (curPlayer.hasItem(*i) == true)
		{
		    if(curDungeon.featureInRoom("hound") == true && *i == "guts")
            {
                //remove from inventory
                curPlayer.removeFromBag(*i);
                curDungeon.fIDesc("hound");
                curDungeon.validInteraction("hound");
                dropped = true;
                break;
            }
            else
            {
                Item temp = curPlayer.getItemInBag(*i);
                curDungeon.droppedInRoom(temp);
                curPlayer.removeFromBag(*i);
                dropped = true;
                break;
            }
		}
		else if(curDungeon.featureInRoom(*i) == true)
        {
            curPlayer.removeFromBag("guts");
            curDungeon.fIDesc(*i);
            curDungeon.validInteraction(*i);
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
void Parser::lookAtStuff(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon)
{
#ifdef NOISYTEST
    std::cout << "'look' function > proceeding to look at something." << std::endl;
#endif // NOISYTEST

	bool looking = false;

    if(curSentence.size() == 1)
    {
        curDungeon.printCurLocation();
//        std::cout << "repeats long form explanation of the Dungeon..." << std::endl;
        looking = true;
    }
    else
    {
        //iterate through vector of strings to find names
        for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
        {
            //check if item is in Dungeon
            std::transform(i->begin(), i->end(), i->begin(), ::tolower);
            if (curDungeon.itemInRoom(*i) == true)
            {
                //look at item
                curDungeon.getItemInfo(*i);
                looking = true;
                break;
            }
            else if(curDungeon.featureInRoom(*i) == true)
            {
                //look at feature
                curDungeon.fDesc(*i);
                looking = true;
                break;
            }
            else if(curPlayer.hasItem(*i) == true)
            {
                curPlayer.viewBagItem(*i);
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
void Parser::fillObject(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon)
{
#ifdef NOISYTEST
    std::cout << "'fill' function > proceeding to fill object." << std::endl;
#endif // NOISYTEST

	bool filled = false;
    if (curPlayer.hasItem("flask")== true)
    {
        //iterate through vector of strings to find names
        for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
        {
     //       if(curDungeon.featureInRoom("water") || curDungeon.featureInRoom("fountain") || curDungeon.featureInRoom("basin")== true).
            std::transform(i->begin(), i->end(), i->begin(), ::tolower);
            if(curDungeon.featureInRoom(*i) == true)
            {
                if(curDungeon.verbCheck(*i,"collect") || curDungeon.verbCheck(*i,"fill") || curDungeon.verbCheck(*i, "scoop") == true)
                {
                        //fill
                        curPlayer.fill(10);
                        curDungeon.fIDesc(*i);
                        cout << "Your flask is now filled with water." << endl;
                        curDungeon.validInteraction(*i);
                        filled = true;
                        break;
                }
            }
            else if(curDungeon.featureInRoom("basin") == true)
            {
                curPlayer.fill(10);
                curDungeon.fIDesc("basin");
                curDungeon.validInteraction("basin");
                filled = true;
                break;
            }
            else if(curDungeon.featureInRoom("fountain") == true)
            {
                curPlayer.fill(10);
                curDungeon.fIDesc("fountain");
                curDungeon.validInteraction("fountain");
                filled = true;
                break;
            }
            else
            {
                cout << "There is no water in the room to collect water from." << endl;
                filled = true;
            }
        }
    }
	if (filled == false)
	{
		std::cout << "You cannot fill that. or you are missing flask."  << std::endl;
	}
}

//for verb cross
void Parser::crossObject(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon)
{
#ifdef NOISYTEST
    std::cout << "'cross' function > proceeding to cross object." << std::endl;
#endif // NOISYTEST

	bool crossed = false;

    //iterate through vector of strings to find names
    for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
    {
        //check if object is in Dungeon
        std::transform(i->begin(), i->end(), i->begin(), ::tolower);
        if (curDungeon.featureInRoom(*i) == true)
        {
            //cross object
           // curDungeon.useItem(*i);
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
void Parser::unlockObject(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon)
{
#ifdef NOISYTEST
    std::cout << "'unlock' function > proceeding to unlock object." << std::endl;
#endif // NOISYTEST

	bool unlocked = false;

    //first check for key in player inventory
    if(curPlayer.hasItem("key") == true)
    {
        //iterate through vector of strings to find names
        for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
        {
            //check if object is in Dungeon
            std::transform(i->begin(), i->end(), i->begin(), ::tolower);
            if (curDungeon.featureInRoom(*i) == true)
            {
                if(curDungeon.verbCheck(*i, "unlock") == true)
                {
                    //unlock item
                    curDungeon.fIDesc(*i);
                    curDungeon.validInteraction(*i);
                    curPlayer.removeFromBag("key");
                    unlocked = true;
                    break;
                }
                else
                {
                    cout << "Maybe you are using the wrong command on " << *i << endl;
                    unlocked = true;
                }
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

//for verb sneak
void Parser::sneakSomewhere(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon)
{
#ifdef NOISYTEST
    std::cout << "'sneak' function > proceeding to sneak around." << std::endl;
#endif // NOISYTEST

	bool sneaked = false;

    //iterate through vector of strings to find names
    for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
    {
        //check if object is in Dungeon
        std::transform(i->begin(), i->end(), i->begin(), ::tolower);
        if (curDungeon.featureInRoom(*i) == true)
        {
            //sneak around
            curDungeon.fIDesc(*i);
            curDungeon.validInteraction(*i);
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
void Parser::attackSomething(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon)
{
#ifdef NOISYTEST
    std::cout << "'attack' function > proceeding to attack enemy." << std::endl;
#endif // NOISYTEST

	bool attacked = false;
	if(curPlayer.hasItem("sword") == true)
    {
        //iterate through vector of strings to find names
        for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
        {
            //check if enemy is in Dungeon
            std::transform(i->begin(), i->end(), i->begin(), ::tolower);
            if(curDungeon.featureInRoom(*i) == true)
            {
                if (curDungeon.verbCheck(*i, "attack") == true)
                {
                    curDungeon.fIDesc(*i);
                    //attacking enemy
                    curDungeon.validInteraction(*i);
                    curDungeon.fDesc(*i);
                    cout << "Lost 2 HP after Attack. " << endl;
                    curPlayer.subtractHitPoints(2);
                    attacked = true;
                    break;
                }
            }
        }
    }
    else
    {
           std::cout << "You are missing a weapon." << std::endl;
    }
	if (attacked == false)
	{
		std::cout << "You cannot attack that."  << std::endl;
	}
}

//for verb block
void Parser::blockSomething(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon)
{
#ifdef NOISYTEST
    std::cout << "'block' function > proceeding to block attack." << std::endl;
#endif // NOISYTEST

	bool blocked = false;

    //iterate through vector of strings to find names
    for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
    {
        //check if enemy is in Dungeon
        std::transform(i->begin(), i->end(), i->begin(), ::tolower);
        if (curDungeon.featureInRoom(*i) == true)
        {
            if (curDungeon.verbCheck(*i, "block") == true)
            {
                //blocking enemy
                curDungeon.fIDesc(*i);
                curDungeon.validInteraction(*i);
                curDungeon.fDesc(*i);
                curPlayer.subtractHitPoints(1);
                cout << "Successfully blocked, but still lost 1 HP." << endl;
                blocked = true;
                break;
            }
        }
    }

	if (blocked == false)
	{
		std::cout << "You cannot block that."  << std::endl;
	}
}

//for verb pull
void Parser::pull(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon)
{
#ifdef NOISYTEST
    std::cout << "'pull' function > proceeding to pull lever." << std::endl;
#endif // NOISYTEST

	bool pulled = false;

    //iterate through vector of strings to find names
    for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
    {
        //check if enemy is in Dungeon
        std::transform(i->begin(), i->end(), i->begin(), ::tolower);
        if (curDungeon.featureInRoom(*i) == true)
        {
            if (curDungeon.verbCheck(*i, "pull") == true)
            {
                curDungeon.fIDesc(*i);
                curDungeon.validInteraction(*i);
                pulled = true;
                break;
            }
        }
    }

	if (pulled == false)
	{
		std::cout << "You cannot pull that."  << std::endl;
	}
}
//for verb touch
void Parser::touchSomething(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon)
{
    bool touched = false;

    //iterate through vector of strings to find names
    for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
    {
        //check if enemy is in Dungeon
        std::transform(i->begin(), i->end(), i->begin(), ::tolower);
        if (curDungeon.featureInRoom(*i) == true)
        {
            if (curDungeon.verbCheck(*i, "touch") == true)
            {
                if(*i == "geysers")
                {
                    curDungeon.fIDesc(*i);
                    curDungeon.validInteraction(*i);
                    curPlayer.subtractHitPoints(2);
                    touched = true;
                    break;
                }
                else
                {
                    curDungeon.fIDesc(*i);
                    curDungeon.validInteraction(*i);
                    curPlayer.setHitPoints(10);
                    touched = true;
                    break;
                }
            }
        }
    }

	if (touched == false)
	{
		std::cout << "You cannot touch that."  << std::endl;
	}
}

//for verb illuminate
void Parser::illuminate(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon)
{
     bool illuminated = false;

    //iterate through vector of strings to find names
    for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
    {
        //check if enemy is in Dungeon
        std::transform(i->begin(), i->end(), i->begin(), ::tolower);
        if (curDungeon.featureInRoom(*i) == true)
        {
            if (curDungeon.verbCheck(*i, "illuminate") || curDungeon.verbCheck(*i, "light")== true)
            {
                curDungeon.fIDesc(*i);
                curDungeon.validInteraction(*i);
                illuminated = true;
                break;
            }
        }
    }

	if (illuminated == false)
	{
		std::cout << "You cannot illuminate that."  << std::endl;
	}
}

//for verb push
void Parser::push(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon)
{
     bool pushed = false;

    //iterate through vector of strings to find names
    for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
    {
        //check if enemy is in Dungeon
        std::transform(i->begin(), i->end(), i->begin(), ::tolower);
        if (curDungeon.featureInRoom(*i) == true)
        {
            if (curDungeon.verbCheck(*i, "push") || curDungeon.verbCheck(*i, "move") == true)
            {
               // curDungeon.fIDesc(*i);
                curDungeon.fIDesc(*i);
                curDungeon.validInteraction(*i);
                pushed = true;
                break;
            }
        }
        else if(curDungeon.featureInRoom("dark") == true)
        {
            if (*i == "panel")
            {
               // curDungeon.fIDesc(*i);
                curDungeon.fIDesc("dark");
                curDungeon.validInteraction("dark");
                pushed = true;
                break;
            }
        }
    }

	if (pushed == false)
	{
		std::cout << "You cannot push that."  << std::endl;
	}
}

//for verb read
void Parser::read(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon)
{
     bool reading = false;

    //iterate through vector of strings to find names
    for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
    {
        //check if enemy is in Dungeon
        std::transform(i->begin(), i->end(), i->begin(), ::tolower);
        if (curDungeon.featureInRoom(*i) == true)
        {
            if (curDungeon.verbCheck(*i, "read") || curDungeon.verbCheck(*i, "inspect") == true)
            {
                curDungeon.fIDesc(*i);
                if(*i == "read")
                {
                    curPlayer.setHitPoints(2);
                    cout << "You have gained 2 HP." << endl;
                }
                curDungeon.validInteraction(*i);
                reading = true;
                break;
            }
        }
    }

	if (reading == false)
	{
		std::cout << "You cannot read that."  << std::endl;
	}
}
//for verb pay bribe
void Parser::payBribe(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon)
{
     bool bribe = false;
//need coins

    //iterate through vector of strings to find names
    for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
    {
        //check if enemy is in Dungeon
        std::transform(i->begin(), i->end(), i->begin(), ::tolower);
        if (curDungeon.featureInRoom(*i) == true)
        {
            if (curDungeon.verbCheck(*i, "pay") || curDungeon.verbCheck(*i, "bribe") == true)
            {
                curDungeon.fIDesc(*i);
                curDungeon.validInteraction(*i);
                bribe = true;
                break;
            }
        }
    }

	if (bribe == false)
	{
		std::cout << "You cannot do that."  << std::endl;
	}
}
//for verb remove
void Parser::removeSomething(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon)
{
     bool removed = false;

    //iterate through vector of strings to find names
    for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
    {
        //check if enemy is in Dungeon
        std::transform(i->begin(), i->end(), i->begin(), ::tolower);
        if (curDungeon.featureInRoom(*i) == true)
        {
            if (curDungeon.verbCheck(*i, "remove") == true)
            {
                curDungeon.fIDesc(*i);
                curDungeon.validInteraction(*i);
                removed = true;
                break;
            }
        }
    }

	if (removed == false)
	{
		std::cout << "You cannot remove that."  << std::endl;
	}
}
