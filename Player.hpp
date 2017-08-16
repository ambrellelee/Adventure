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
		int maxHitPoints;	
		int stamina;
		int maxStamina;	
		double score;
		Room *currentLocation;
		Room *lastLocation;
		std::string curLocationName;
          std::string lastLocationName;
		Inventory bag;
		bool gameOver;
	
	public:
		//Constructors and Destructor
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
		std::string getCurLocName();
		std::string getLastLocName();
		void setCurrentLocation(Room *curRoom);
          void setLastLocation(Room *lastRoom);
          Room *getCurrentLocation();

          //Player Functionality Methods
		void printPlayerInfo();
		void subtractHitPoints(int help);
		void addStamina(int sustenance);
		void subtractStamina(int sustenance);
		bool canDrink(std::string);			//checks to see if the player can drink from the item / feature
		bool endCheck();					//check if player game over

		//Related to Bag and Items
		void addToBag(Item& thing);
          void removeFromBag(std::string thing);
          void lookBag();                         //prints list of all items
          bool hasItem(std::string);              //checks to see if the item is in the player's inventory
          bool useItem(std::string pItem);        //does the same thing as hasItem?
          void viewBagItem(std::string);          //prints out information for specific item
		void fill(int);
		void subtractWater(int);                //decreases water level in flask
          void getItemInfo(std::string);          //print item desc

		//Save and Load methods
		int savePlayer();
		int loadPlayer();
		void printLocs();

};

#endif
