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

Player::Player(std::string newName, int hPoints, int pStamina, double pScore)
{
	pName = newName;
	hitPoints = hPoints;
	stamina = pStamina;
	score = pScore;
	bag = new Inventory("bag");
}

//set values
void Player::setName(std::string playerName)
{
	pName = playerName;
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

void Player::setScore(double playerScore)
{
	score = playerScore;
}

void Player::setCurrentLocation(Room* position)
{
	lastLocation = currentLocation;
	currentLocation = position;
}

//get values
std::string Player::getName()
{
     return pName;
	std::cout << pName << std::endl;
}

int Player::getHitPoints()
{
     return hitPoints;
	std::cout << hitPoints << std::endl;
}

int Player::getStamina()
{
     return stamina;
	std::cout << stamina << std::endl;
}

int Player::getScore()
{
	return score;
	std::cout << score << std::endl;
}

Room* Player::getCurrentLocation()
{
	return currentLocation;
}

Room* Player::getLastLocation()
{
	return lastLocation;
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
	bag->addInventory(thing);
}

void Player::removeFromBag(std::string thing)
{
	bag->removeInventory(thing);
}

void Player::lookBag()
{
	 bag->viewInventory();
}

bool Player::hasItem(std::string item)
{
	return bag->inInventory(item);
}

Player::~Player()
{
	delete bag;
}

//hardcoded comparsion for now refine later
/*void Player::pickUpItem(std::string thing)
{
	addToBag(thing);  
}*/

/*void Player::dropItem(std::string thing)
{
	removeFromBag(thing);
}*/

bool Player::itemInInventory(std:: string thing)
{
	return bag->inInventory(thing);	

/*	if(pItem == "sword")
    {
#ifdef NOISYTEST
        std::cout << pItem << " is in inventory." << std::endl;
#endif
        return true;
    }
    else if(pItem == "water")
    {
#ifdef NOISYTEST
        std::cout << pItem << " is in inventory." << std::endl;
#endif
        return true;
    }
    else if(pItem == "potion")
    {
#ifdef NOISYTEST
        std::cout << pItem << " is in inventory." << std::endl;
#endif
        return true;
    }
    else
        return false;
*/
}


bool Player::useItem(std:: string pItem)
{
    if(pItem == "sword")
    {
#ifdef NOISYTEST
        std::cout << "Using " << pItem << " from inventory." << std::endl;
#endif
        return true;
    }
    else if(pItem == "water")
    {
#ifdef NOISYTEST
        std::cout << "filling/Drinking " << pItem << " from inventory." << std::endl;
#endif
        return true;
    }
   else if(pItem == "potion")
   {
#ifdef NOISYTEST
        std::cout << "Drinking " << pItem << " from inventory." << std::endl;
#endif
        return true;
   }
    else
        return false;

}
/*void Player::removeItem(std::string pItem)
{
#ifdef NOISYTEST
        std::cout << pItem << " removed from inventory." << std::endl;
#endif
    removeFromBag(pItem);

}*/

void Player::viewBagItem(std::string itemName)
{
	bag -> viewItem(itemName);
}

