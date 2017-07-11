#include "Player.hpp"


void Player::setName(std::string playerName)
{
	pName = playerName;
} 

std::string Player::getName()
{ 
	return pName;         
}

void Player::setHitPoints(int playerHitPoints)
{
	hitPoints = playerHitPoints;
	
	if(hitPoints >= maxHitPoints)
	{	
		//end Game
	}
}	

int Player::getHitPoints()
{
	return hitPoints;	
}

void Player::setStamina(int playerStamina)
{
	stamina = playerStamina;
}

int Player::getStamina()
{
	return stamina;

	if(stamina <= 0) 
	{
		//end Game
	}
	else if(stamina > maxStamina)
		stamina = maxStamina;   
}

void Player::setScore(double playerScore)
{
	score = playerScore;
}

int Player::getScore()
{
	return score;
}

