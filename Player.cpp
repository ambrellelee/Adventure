#include "Player.hpp"

std::string pName;       //player name
          std::int hitPoints;
          std::int maxHitPoints;   //what do we want this value to be?
          std::int stamina;
          std::int maxStamina;     //what do we want this value to be?
          std::double score;
          std::string pInventory[12];   //Player's inventory

void Player::setName(std::string playerName);
{
	pName = playerName;
} 

string Player::getName();
{ 
	return pName;         
}

void Player::setHitPoints(std::int playerHitPoints);
{
	hitPoints = playerHitPoints;
	
	if hitPoints >= maxHitPoints
		//end Game
}
          
int Player::getHitPoints();
{
	return hitPoints;	
}

void Player::setStamina(std::int playerStamina);
{
	stamina = playerStamina;
}

int Player::getStamina();
{
	return stamina;

	if stamina <= 0 
		//end Game

	else if stamina > maxStamina
		stamina = maxStamina;   
}

void Player::setScore(std::double playerScore);
{
	score = playerScore;
}

int Player::getScore();
{
	return score;
}

