#ifndef PLAYER_HPP
#define PLAYER_HPP

#include<string>
#include<iostream>
#include "Room.hpp"
#include "Inventory.hpp"


class Player
{
	private:
		std::string pName;		//player name
		int hitPoints;
		int maxHitPoints;	//what do we want this value to be?
		int stamina;
		int maxStamina;	//what do we want this value to be?
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
		bool addToBag(std::string);
		std::string removeFromBag(std::string);
		std::string lookBag();		
		std::string pickUpItem(std::string);
		void dropItem(std::string);

};
		
#endif
	
