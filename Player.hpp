#ifndef PLAYER_HPP
#define PLAYER_HPP

#include<string>
#include<iostream>

//add methods to find location in game
//add methods to move player through game

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
		//Constructors
		Player();
		Player(std::string hPoints, int pStamina, double pScore); 	
	
		//Set Values	
		void setName(std::string playerName);
		void setHitPoints(int playerHitPoints);
		void setStamina(int playerStamina);
		void setScore(double playerScore);
	
		//Get Values
		std::string getName();
		int getHitPoints();
		int getStamina();
		int getScore();
	
		//add inventory method
};
		
#endif
	
