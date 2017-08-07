#ifndef PLAYER_HPP
#define PLAYER_HPP

#include<string>
#include<iostream>
#include<vector>
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
		Inventory bag;

	public:
		//Constructors
		Player();
		Player(std::string newName, int hPoints, int pStamina, double pScore, Inventory pInvent);
		~Player();

		//Get and Set Values
		void setName(std::string playerName);
		std::string getName();
		void setHitPoints(int playerHitPoints);
		int getHitPoints();
		void setStamina(int playerStamina);
		int getStamina();
		void setScore(double playerScore);
		int getScore();
		//void setCurrentLocation(Room*);

		//Room* getCurrentLocation();
          //Room* getLastLocation();
		
		//Player Functionality Methods
		void printPlayerInfo();
		void subtractHitPoints(int help);
		void addStamina(int sustenance);
		void addToBag(Item& thing);
		void removeFromBag(std::string thing);
		void lookBag();					//prints list of all items
		bool hasItem(std::string);			//checks to see if the item is in the player's inventory
		bool useItem(std::string pItem);		//does the same thing as hasItem?
		void viewBagItem(std::string);		//prints out information for specific item

};

#endif
