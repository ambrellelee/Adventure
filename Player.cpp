#include "Player.hpp"

//Finish move, drop, and pickup methods
//add in identifier to end the game

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

bool Player::addToBag(std::string thing)
{
	return bag->addInventory(thing);
}

std::string Player::removeFromBag(std::string thing)
{
	return bag->removeInventory(thing);
}

std::string Player::lookBag()
{
	return bag->viewInventory();
}

std::string Player::pickUpItem(std::string thing)
{
	addToBag(thing);
}

void Player::dropItem(std::string thing)
{
	removeFromBag(thing);
}

Player::~Player()
{
	delete bag;
}
