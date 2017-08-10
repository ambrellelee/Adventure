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
    if (verbInSentence(curSentence, "go") == true)
	{
		//search for the next Room and if found, go to next Room.
#ifdef NOISYTEST
		std::cout << "'GO' detected...proceeding to 'GO' function." << std::endl;
#endif
		findNextDungeon(curSentence, curDungeon, curPlayer);
	}
	else if(verbInSentence(curSentence, "use") == true)
	{
#ifdef NOISYTEST
		std::cout << "'Use' detected...proceeding to 'Use' function." << std::endl;
#endif
		//search for item name in inventory and if it exist, use it.
		searchItemToUse(curSentence, curPlayer, curDungeon);
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
		//eat from inventory

		cout << "eating food~ Yum~Yum~Yum~~~~~~" << endl;
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
    else if(verbInSentence(curSentence, "attack") == true)
    {
#ifdef NOISYTEST
		std::cout << "'attack' detected...proceeding to 'attack' function." << std::endl;
#endif
		//attack enemy
		attackSomething(curSentence, curPlayer, curDungeon);
    }
    else if(verbInSentence(curSentence, "ring") == true)
    {
#ifdef NOISYTEST
		std::cout << "'ring' detected...proceeding to 'ring' function." << std::endl;
#endif
		//ring something
		ringObject(curSentence, curPlayer, curDungeon);
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
    else if(verbInSentence(curSentence, "illuminate") == true)
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
		//push
		read(curSentence, curPlayer, curDungeon);
    }
    //for exit
    else if(verbInSentence(curSentence, "exit") == true)
    {
#ifdef NOISYTEST
		std::cout << "'exit' detected...proceeding to 'exit' function." << std::endl;
#endif
		exit(0);
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

	//iterate through vector of strings to find Dungeon names
	for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
	{
		//check if any string matches the Dungeon names
		//Dungeon should return true or false if name is found or not
		std::transform(i->begin(), i->end(), i->begin(), ::tolower);
		if (curDungeon.useExit(*i) == true)
		{
		    if(curDungeon.checkRoomExitStatus(*i) == true)
            {
                curDungeon.setCurrRoom(*i);
                std::cout << "****************************************************************" << std::endl;
                std::cout << "****            You have entered: " << (*i) << " Dungeon.          ****" << std::endl;
                std::cout << "****************************************************************" << std::endl;
                curDungeon.printCurLocation();
                DungeonFound = true;
                break;
            }
            else
            {
                cout << "You can not proceed to " << *i << " Dungeon yet.\nsome feature not activated." <<endl;
            }

		}
		/**************************************************************************************
		else
        {
            std::cout << "Something is wrong. Can not go to " << (*i) << "Room." << std::endl;
        }
        **************************************************************************************/
	}
	if (DungeonFound == false)
	{
		std::cout << "Invalid Dungeon." << std::endl;
	}
}

//for verb use
void Parser::searchItemToUse(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon)
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
		if (curPlayer.hasItem(*i) == true)
		{
			//use item in player inventory if it can be used
            cout << "You used " << (*i) << endl;
  //          curPlayer.removeFromBag((*i));//remove item from player inventory
            itemFound = true;
            break;
		}
		else if(curDungeon.featureInRoom(*i) == true)
        {
            cout << "Using feature in room " << endl;

        }

	}
	if (itemFound == false)
	{
		std::cout << "Item not in inventory." << std::endl;
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
 //                   cout << "You picked up " << temp.iName << endl;
//                    cout << temp.iDesc << endl;
                    curPlayer.addToBag(temp);
                    //remove item from the Dungeon
                    //valid interaction - not working, validInteraction is checking feature list not item list...**************************************************<<------
                    curDungeon.validInteraction(*i); //sets feature interactionNum to +1
                    itemTaken = true;
                    break;
                }
                else
                {
                    cout << "You already have " << *i << " in the inventory. " << endl;
                    break;
                }
            }
            else if(curPlayer.hasItem(*i) == true)
            {
                cout << "You already have " << *i << " in the inventory. " << endl;
            }
            else
            {
                    cout << *i << " can not be taken from the room.\nOr feature need to be activated first." << endl;
            }
		}
	}
	if (itemTaken == false)
	{
		std::cout << "Item can not be picked up." << std::endl;
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
                curDungeon.fIDesc(*i);   //prints the feature's 1st interaction description
                curDungeon.validInteraction(*i); //sets feature interactionNum to +1
                objectOpened = true;
                break;
            }
            else
            {
                std::cout << "You can not open " << (*i) << std::endl;
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
 //           cout << *i << " found in player inventory"<<endl;
		    if(curPlayer.canDrink(*i) == true)
            {
                //use the item
                std::cout << "You have drinked " << *i << std::endl;
                curPlayer.addStamina(10);
                std::cout << "Your stamina have increased by 10." << std::endl;
                drinked = true;
                break;
            }
 //           cout << "can drink? : "<<curPlayer.canDrink(*i)<<endl;
		}
	}
	if (drinked == false)
	{
		std::cout << "You cannot drink that."  << std::endl;
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
		    //remove from inventory
			curPlayer.removeFromBag(*i);
#ifdef NOISYTEST
    std::cout << "dropped " << (*i) << std::endl;
#endif // NOISYTEST
			dropped = true;
			break;
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
        curDungeon.viewCurRoom();
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
            if(curDungeon.featureInRoom(*i) == true)
            {
                //look at feature
                curDungeon.fDesc(*i);
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

    //iterate through vector of strings to find names
    for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
    {
 //       if(curDungeon.featureInRoom("water") || curDungeon.featureInRoom("fountain") || curDungeon.featureInRoom("basin")== true).
        if(curDungeon.featureInRoom(*i) == true)
        {
            //check if item is in inventory
            std::transform(i->begin(), i->end(), i->begin(), ::tolower);
            if(curDungeon.verbCheck(*i,"collect") || curDungeon.verbCheck(*i,"fill") || curDungeon.verbCheck(*i, "scoop") == true)
            {
                if (curPlayer.hasItem("flask")== true)
                {
                    //fill
                    curPlayer.fill(10);
                    curDungeon.fIDesc(*i);
                    cout << "Your flask is now filled with water." << endl;
                    filled = true;
                    break;
                }
            }

        }
        else
        {
            cout << "There is no water in the room to collect water from." << endl;
            break;
        }
    }

	if (filled == false)
	{
		std::cout << "You cannot fill that."  << std::endl;
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
    if(curPlayer.hasItem("key") || curPlayer.hasItem("mirrorKey")== true)
    {
        //iterate through vector of strings to find names
        for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
        {
            //check if object is in Dungeon
            std::transform(i->begin(), i->end(), i->begin(), ::tolower);
            if (curDungeon.featureInRoom(*i) == true)
            {
                //unlock item
                curDungeon.fIDesc(*i);
            //    curDungeon.validInteraction(*i);
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

//for verb ring
void Parser::ringObject(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon)
{
#ifdef NOISYTEST
    std::cout << "'ring' function > proceeding to ring." << std::endl;
#endif // NOISYTEST

	bool ringed = false;

    //iterate through vector of strings to find names
    for (playerString::iterator i = curSentence.begin(); i != curSentence.end(); ++i)
    {
        //check if object is in Dungeon
        std::transform(i->begin(), i->end(), i->begin(), ::tolower);
        if (curDungeon.featureInRoom(*i) == true)
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
               // curDungeon.fIDesc(*i);
               curDungeon.validInteraction(*i);
                curDungeon.fDesc(*i);
                //blocking enemy

                //std::cout << "you have blocked the attack from " << (*i) << endl;
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
                curDungeon.validInteraction(*i);
                curDungeon.fIDesc(*i);
                curPlayer.subtractHitPoints(2);
                touched = true;
                break;
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
            if (curDungeon.verbCheck(*i, "illuminate") == true)
            {
               // curDungeon.fIDesc(*i);
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
