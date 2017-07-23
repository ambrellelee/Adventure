#include "Player.hpp"

#define NOISYTEST

//Constructors
Player::Player()
{
	hitPoints = 0;
	stamina = 0;
	score = 0;
}

Player::Player(int hPoints, int pStamina, double pScore)
{
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
		//end Game
	}
}

void Player::setStamina(int playerStamina)
{
	stamina = playerStamina;

	 if(stamina <= 0)
     {
          //end Game
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
}

int Player::getHitPoints()
{
     return hitPoints;
}

int Player::getStamina()
{
     return stamina;
}

int Player::getScore()
{
	return score;
}

Room* Player::getCurrentLocation()
{
	return currentLocation;
}

Room* Player::getLastLocation()
{
	return lastLocation;
}

void move()
{

}

void Player::addToBag(std::string thing)
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

void Player::pickUpItem(std::string thing)
{
    std::cout << "picked up item, add to bag" << std::endl;
//	addToBag(thing);  //buggy at this point
}

void Player::dropItem(std::string thing)
{
	removeFromBag(thing);
}

Player::~Player()
{
	delete bag;
}

bool Player::itemInInventory(std:: string pItem)
{
    if(pItem == "sword")
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
void Player::removeItem(std::string pItem)
{
#ifdef NOISYTEST
        std::cout << pItem << " removed from inventory." << std::endl;
#endif
    removeFromBag(pItem);

}
