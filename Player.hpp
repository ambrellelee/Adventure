#ifndef PLAYER_HPP
#define PLAYER_HPP

#include<string>

class Player
{
	private:
		std::string pName;		//player name
		std::int hitPoints;
		std::int maxHitPoints;	//what do we want this value to be?
		std::int stamina;
		std::int maxStamina;	//what do we want this value to be?
		std::double score;
		std::string pInventory[12];	//Player's inventory

	public:
		void Player::setName(std::string playerName);
		string Player::getName();
		void Player::setHitPoints(std::int playerHitPoints);
		int Player::getHitPoints();
		void Player::setStamina(std::int playerStamina);
		int Player::getStamina();
		void Player::setScore(std::int playerScore);
		int Player::getScore();
		
		//add inventory method
}
		

	
