#ifndef PLAYER_HPP
#define PLAYER_HPP

#include<string>
#include<iostream>

class Player
{
	private:
		std::string pName;		//player name
		int hitPoints;
		int maxHitPoints;	//what do we want this value to be?
		int stamina;
		int maxStamina;	//what do we want this value to be?
		double score;
		std::string pInventory[12];	//Player's inventory

	public:
		void setName(std::string playerName);
		std::string getName();
		void setHitPoints(int playerHitPoints);
		int getHitPoints();
		void setStamina(int playerStamina);
		int getStamina();
		void setScore(double playerScore);
		int getScore();
		
		//add inventory method
};
		
#endif
	
