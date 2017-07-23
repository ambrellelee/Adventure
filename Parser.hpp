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
		typedef std::vector<std::string> playerString;
		std::string goTo = "go";
		std::string useItem = "use";
		std::string take = "take";
		std::string openChest = "open";
		std::string talk = "talk";
		std::string drink = "drink";
		std::string drop = "drop";
		std::string look = "look";
		std::string help = "help";
		std::string inventory = "inventory";
		std::string fills = "fill";
		std::string moves = "move";
		std::string cross = "cross";
		std::string unlock = "unlock";
		std::string investigate = "investigate";
		std::string smell = "smell";
		std::string sneak = "sneak";
		std::string attack = "attack";
		std::string ring = "ring";
		std::string say = "say";
		std::string block = "block";
		std::string touch = "touch";

	public:

		void parser(Room& curRoom, Player& curPlayer, playerString& curSentence);
		bool verbInSentence(playerString& curSentence, std::string stringToCompare);

		//perform the verbs
		void findNextRoom(playerString& curSentence, Room& curRoom, Player& curPlayer);
		void searchItemToUse(playerString& curSentence, Player& curPlayer, Room& curRoom);
		void takeItemInRoom(playerString& curSentence, Player& curPlayer, Room& curRoom);
		void openObject(playerString& curSentence, Player& curPlayer, Room& curRoom);
		void talkToNPC(playerString& curSentence, Player& curPlayer, Room& curRoom);
		void drinkSomething(playerString& curSentence, Player& curPlayer, Room& curRoom);
		void dropSomething(playerString& curSentence, Player& curPlayer, Room& curRoom);
		void lookAtStuff(playerString& curSentence, Player& curPlayer, Room& curRoom);
		void fillObject(playerString& curSentence, Player& curPlayer, Room& curRoom);
		void moveStuff(playerString& curSentence, Player& curPlayer, Room& curRoom);
		void crossObject(playerString& curSentence, Player& curPlayer, Room& curRoom);
		void unlockObject(playerString& curSentence, Player& curPlayer, Room& curRoom);
		void investigateStuff(playerString& curSentence, Player& curPlayer, Room& curRoom);
		void smellStuff(playerString& curSentence, Player& curPlayer, Room& curRoom);
		void sneakSomewhere(playerString& curSentence, Player& curPlayer, Room& curRoom);
		void attackSomething(playerString& curSentence, Player& curPlayer, Room& curRoom);
		void ringObject(playerString& curSentence, Player& curPlayer, Room& curRoom);
		void saySomething(playerString& curSentence, Player& curPlayer, Room& curRoom);
		void blockSomething(playerString& curSentence, Player& curPlayer, Room& curRoom);
		void touchSomething(playerString& curSentence, Player& curPlayer, Room& curRoom);

};





#endif
