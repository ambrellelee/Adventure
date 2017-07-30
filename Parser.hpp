#ifndef PARSER_HPP
#define PARSER_HPP

#include"Dungeon.hpp"
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
		/*
		const std::string goTo = "go";
		const std::string useItem = "use";
		const std::string take = "take";
		const std::string openChest = "open";
		const std::string talk = "talk";
		const std::string drink = "drink";
		const std::string drop = "drop";
		const std::string look = "look";
		const std::string help = "help";
		const std::string inventory = "inventory";
		const std::string fills = "fill";
		const std::string moves = "move";
		const std::string cross = "cross";
		const std::string unlock = "unlock";
		const std::string investigate = "investigate";
		const std::string smell = "smell";
		const std::string sneak = "sneak";
		const std::string attack = "attack";
		const std::string ring = "ring";
		const std::string say = "say";
		const std::string block = "block";
		const std::string touch = "touch";
		const std::string quit = "exit";
*/
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
