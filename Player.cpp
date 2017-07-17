#include "Player.hpp"

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

