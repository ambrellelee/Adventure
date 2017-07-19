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
		Inventory *bag; 

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
		void setCurrentLocation(Room*);
	
		//Get Values
		std::string getName();
		int getHitPoints();
		int getStamina();
		int getScore();
		Room* getCurrentLocation();
          Room* getLastLocation();
	
		//add inventory method
		void move();
		void addBag();
		void removeBag();
		void lookBag();		
};
		
#endif
	
