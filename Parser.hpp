#ifndef PARSER_HPP
#define PARSER_HPP

#include"Room.hpp"
#include"Player.hpp"
#include"Inventory.hpp"
#include "Feature.hpp"
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>

class Parser
{
	private:
		//create vector to hold strings from player input
		vector<string> playerString;
		std:string goTo = "go";
		std:string useItem = "use";
		std:string take = "take";
		std:string openChest = "open";
		std:string talk = "talk";
		std:string drink = "drink";
		std:string drop = "drop";
		std:string look = "look";
		std:string help = "help";
		std:string inventory = "inventory";
		std:string fill = "fill";
		std:string move = "move";
		std:string cross = "cross";
		std:string unlock = "unlock";
		std:string investigate = "investigate";
		std:string smell = "smell";
		std:string sneak = "sneak";
		std:string attack = "attack";
		std:string ring = "ring";
		std:string say = "say";
		std:string block = "block";
		std:string touch = "touch";
		
	public:
		
		void parser(Room& curRoom, Player& curPlayer, playerString& curSentence);
		bool verbInSentence(playerString& curSentence, std::string stringToCompare);
		
		//perform the verbs
		void findNextRoom(playerString& curSentence, Room& curRoom, Player& curPlayer);
		void searchItemToUse(playerString& curSentence, Player& curPlayer, Room& curRoom);
		void pickUpItemInRoom(playerString& curSentence, Player& curPlayer, Room& curRoom);
		
}





#endif