#include "Player.hpp"
#include "Item.hpp"
#include "Inventory.hpp"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

//Constructors
Player::Player()
{
	pName = "Player 1";
	hitPoints = 10;
	stamina = 3;
	score = 0;
	maxHitPoints = 20;
	maxStamina = 10;
	gameOver = false;
     bag = Inventory("myInventory");
     lastLocation = NULL;
     currentLocation = NULL;

}

Player::Player(std::string newName, int hPoints, int pStamina, double pScore, Inventory pInvent)
{
	pName = newName;
	hitPoints = hPoints;
	stamina = pStamina;
	score = pScore;
	bag = pInvent;
	maxHitPoints = 20;
	maxStamina = 10;
	gameOver = false;
	lastLocation = NULL;
     currentLocation = NULL;
}

//Get and Set Methods
void Player::setName(std::string playerName)
{
	pName = playerName;
}

std::string Player::getName()
{
     return pName;
	std::cout << pName << std::endl;
}

void Player::setHitPoints(int playerHitPoints)
{
	hitPoints += playerHitPoints;

    if(hitPoints >= maxHitPoints)
    {
        hitPoints = maxHitPoints;
        std::cout << "Your HP is at MAX." << std::endl;
    }
}

int Player::getHitPoints()
{
    return hitPoints;
	std::cout << hitPoints << std::endl;
}

void Player::setStamina(int playerStamina)
{
	stamina = playerStamina;
}

int Player::getStamina()
{
     return stamina;
	std::cout << stamina << std::endl;
}

void Player::setScore(double playerScore)
{
	score = playerScore;
}

int Player::getScore()
{
	return score;
	std::cout << score << std::endl;
}

std::string Player::getCurLocName()
{
        return curLocationName;
}

std::string Player::getLastLocName()
{
        return lastLocationName;
}

void Player::setCurrentLocation(Room *curRoom)
{
        currentLocation = curRoom;
        curLocationName = curRoom->getName();
}

void Player::setLastLocation(Room *lastRoom)
{
        lastLocation = lastRoom;
        lastLocationName = lastRoom->getName();
}

Room *Player::getCurrentLocation()
{
        return currentLocation;
}

void Player::printPlayerInfo()
{
	std::cout << "Name:" << pName << std::endl;
     std::cout << "Hit Points:" << hitPoints << std::endl;
     std::cout << "Stamina: " << stamina << std::endl;
     std::cout << "Score: " << score << std::endl;
}

void Player::subtractHitPoints(int help)
{
	hitPoints -= help;

	if(hitPoints < 0)
	{
	    hitPoints = 0;
		std::cout << "You have been hit too may times, you have died." << std::endl;
		gameOver = true;
	}
}

void Player::addStamina(int sustenance)
{
	stamina += sustenance;

	if(stamina > maxStamina)
	{
		stamina = maxStamina;
		std::cout << "You have your maximum level of stamina." << std::endl;
	}
	else
	{
		std::cout << "Your stamina have increased by " << sustenance << std::endl;
	}
}

void Player::subtractWater(int water)
{
	bag.decreaseFlask(water);
}

void Player::subtractStamina(int sustenance)
{
    stamina -= sustenance;
    std::cout << "Your current stamina is: " << stamina << std::endl;
    if(stamina <= 0)
    {
        std::cout << "You do not have enough stamina left. You have expired." <<std::endl;
		gameOver = true;
    }
}

void Player::addToBag(Item& thing)
{
    //find the item name and pull the whole item then add to inventory
	bag.addInventory(thing);
}

void Player::removeFromBag(std::string thing)
{
	bag.removeInventory(thing);
}

void Player::lookBag()
{
	 bag.viewInventory();
}

bool Player::hasItem(std::string item)
{
	return bag.inInventory(item);
}

bool Player::useItem(std::string pItem)
{
	bool canUse;

	if(hasItem(pItem))
	{
		canUse = true;
	}
	else
	{
		canUse = false;
	}
	return canUse;
}

bool Player::canDrink(std::string pItem)
{
	return bag.drinkable(pItem);
}

void Player::fill(int liquid)
{
     bag.fillFlask(liquid);
}

Player::~Player()
{
}

void Player::viewBagItem(std::string itemName)
{
	bag.viewItem(itemName);
}
void Player::getItemInfo(std::string itemName)
{
    bag.getInfo(itemName);
}

Item Player::getItemInBag(std::string itemName)
{
    std::vector<Item> tempItems;
    tempItems = bag.getStuff();

    Item tempItem = Item("", "", "", 0, 0, 0, 0, 0);
     std::vector<string> temp;
     for(size_t i =0; i < tempItems.size(); i++)
     {
        //split string into vector
        //http://code.runnable.com/VHb0hWMZp-ws1gAr/splitting-a-string-into-a-vector-for-c%2B%2B
        std::stringstream ss(tempItems[i].iName);
        std::string tok;
        while(getline(ss, tok, ' '))
        {
            temp.push_back(tok);
        }
        for(size_t j = 0; j < temp.size(); j++)
        {
            if(temp[j] == itemName)
            {
                tempItem = tempItems[i];
            }
        }
        temp.clear();
     }
     return tempItem;
}
bool Player::endCheck()
{
    return gameOver;
}

int Player::savePlayer()
{
        fstream outputFile;
        vector<Item> myStuff = bag.getStuff();
        std::string fileName = "saveData/playerFile.txt";


        outputFile.open(fileName.c_str(), ios::out);
        if (!outputFile)
        {
                cout << "ERROR: Could not open file: " << fileName << endl;
                cout << "Terminating savegame command" << endl;
                return 1;
        }

        outputFile << pName << endl;
        outputFile << hitPoints << endl;
        outputFile << maxHitPoints << endl;
        outputFile << stamina << endl;
        outputFile << maxStamina << endl;
        outputFile << score << endl;

        if (currentLocation != NULL)
        {
                outputFile << currentLocation->getName() << endl;
        }
        else
        {
                outputFile << "NULL" << endl;
        }
        if (lastLocation != NULL)
        {
                outputFile << lastLocation->getName() << endl;
        }
        else
        {
                outputFile << "NULL" << endl;
        }
        outputFile << myStuff.size() << endl;
        for (size_t i = 0; i < myStuff.size(); i++)
        {
                outputFile << myStuff[i].iName << endl;
                outputFile << myStuff[i].iDesc << endl;
                outputFile << myStuff[i].useDesc << endl;
                outputFile << myStuff[i].waterLevel << endl;
                outputFile << myStuff[i].maxWater << endl;

                if (myStuff[i].available == true)
                        outputFile << "True" << endl;
                else
                        outputFile << "False" << endl;

                outputFile << myStuff[i].featureSource << endl;
                outputFile << myStuff[i].whenCanTake << endl;

        }

        outputFile << bag.getName() << endl;

        if (gameOver)
                outputFile << "True" << endl;
        else
                outputFile << "False" << endl;

        outputFile.close();
        return 0;
}

int Player::loadPlayer()
{
        fstream inputFile;
        vector<Item> myStuff;
        bag.clearInventory();
        std::string fileName = "saveData/playerFile.txt";
        std::string line;
        int numItems;
        string iName, iDescription, iUse, waterLevel, maxWater, canGet;
        string inFeature, interactionGet;
        int waterNum, waterLimit, featNum, interactionNum;
        bool canPickUp;

        inputFile.open(fileName.c_str(), ios::in);
        if (!inputFile)
        {
                cout << "ERROR: Could not open file: " << fileName << endl;
                cout << "Terminating loadgame command" << endl;
                return 1;
        }

        getline(inputFile, line);
        pName = line;

        getline(inputFile, line);
        stringstream hitNum(line);
        hitNum >> hitPoints;

        getline(inputFile, line);
        stringstream maxHit(line);
        maxHit >> maxHitPoints;

        getline(inputFile, line);
        stringstream stamNum(line);
        stamNum >> stamina;

        getline(inputFile, line);
        stringstream maxStam(line);
        maxStam >> maxStamina;

        getline(inputFile, line);
        stringstream scoreNum(line);
        scoreNum >> score;

        getline(inputFile, line);

        if (line != "NULL")
                curLocationName = line;
        else
                curLocationName = "";

        getline(inputFile, line);

        if (line != "NULL")
                lastLocationName = line;
        else
                lastLocationName = "";

        getline(inputFile, line);
        stringstream itemNum(line);
        itemNum >> numItems;

        for (int i = 0; i < numItems; i++)
        {
                getline(inputFile, line);
                iName = line;

                getline(inputFile, line);
                iDescription = line;

                getline(inputFile, line);
                iUse = line;

                getline(inputFile, line);
                stringstream wLevel(line);
                wLevel >> waterNum;

                getline(inputFile, line);
                stringstream limit(line);
                limit >> waterLimit;

                getline(inputFile, line);
                if (line == "True")
                        canPickUp = true;
                else
                        canPickUp = false;

                getline(inputFile, line);
                stringstream fNum(line);
                fNum >> featNum;

                getline(inputFile, line);
                stringstream intNum(line);
                intNum >> interactionNum;


                Item newItem = Item(iName, iDescription, iUse, waterNum, waterLimit, canPickUp, featNum, interactionNum);
                bag.addInventory(newItem);

        }

        getline(inputFile, line);
        bag.setName(line);

        getline(inputFile, line);
        if (line == "True")
                gameOver = true;
        else
                gameOver = false;

        inputFile.close();


        return 0;
}

void Player::printLocs()
{
        cout << currentLocation->getName() << endl;
        cout << "lastLocation " << lastLocation->getName() << endl;
}
