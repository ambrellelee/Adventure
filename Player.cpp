#include "Player.hpp"

//Finish move; test drop and pickup methods

//Constructors
Player::Player()
{
	pName = "no name";
	hitPoints = 0;
	stamina = 3;
	score = 0;
}

Player::Player(std::string newName, int hPoints, int pStamina, double pScore, Inventory pInvent)
{
	pName = newName;
	hitPoints = hPoints;
	stamina = pStamina;
	score = pScore;
	bag = pInvent;
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
	hitPoints = playerHitPoints;

	if(hitPoints >= maxHitPoints)
	{
		std::cout << "You have been hit too many times. You have lost." << std::endl;
		exit(0);
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

	 if(stamina <= 0)
     {
          std::cout << "You do not have enough stamina left. You have expired." <<std::endl;
		exit(0);
     }
     else if(stamina > maxStamina)
     {
        stamina = maxStamina;
     }

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
/*
void Player::setCurrentLocation(Room* position)
{
	lastLocation = currentLocation;
	currentLocation = position;
}

Room* Player::getCurrentLocation()
{
	return currentLocation;
}

Room* Player::getLastLocation()
{
	return lastLocation;
}
*/
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

	if(hitPoints >= maxHitPoints)
	{
		std::cout << "You have been hit too may times, you have died." << std::endl;
	}

	else if(hitPoints < 0)
	{
		hitPoints = 0;
		std::cout << "You have zero hit points!" << std::endl;
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
	else if(stamina <= 0)
	{
		std::cout << "You have expired due to lack of sustenance." << std::endl;
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
	//delete bag;
}

/*********************************
 Yu's edit
*********************************/
void Player::viewBagItem(std::string itemName)
{
	bag.viewItem(itemName);
}

/*
void Player::savePlayer(std::ofstream& savePlayerFile)
{
	savePlayerFile << "name" << pName << std::endl;
	savePlayerFile << "hitPoints" << hitPoints << std::endl;
	savePlayerFile << "stamina" << stamina << std::endl;
	savePlayerFile << "score" << score << std::endl;
	for(int i = 0; i < bag->size(); i++)
	{
		savePlayerFile << bag[i] <<std::endl;
	}

}


void Player::loadPlayer(std::ifstream& loadPlayerFile)
{
	std::string info;

	loadPlayerFile >> info >> pName;
	loadPlayerFile >> info >> hitPoints;
	loadPlayerFile >> info >> stamina;
	loadPlayerFile >> info >> score;
	//inFile >> info >> bag;
}
*/
