#ifndef PLAYER_HPP
#define PLAYER_HPP

#include<string>
#include<iostream>
#include "Room.hpp"
#include "Inventory.hpp"


//add methods to find location in game
//add methods to move player through game

class Player
{
	private:
		std::string pName;		//player name
		int hitPoints;
		int maxHitPoints = 10;	//what do we want this value to be?
		int stamina;
		int maxStamina = 10;	//what do we want this value to be?
		double score;
		Room *currentLocation;
		Room *lastLocation;		

	public:
		//Constructors
		Player();
		Player(int hPoints, int pStamina, double pScore); 	
		~Player();	

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
		void move();
		Room* getCurrentLocation();
		Room* getLastLocation();
		void setCurrentLocation(Room*);
		
};
		
#endif
	
